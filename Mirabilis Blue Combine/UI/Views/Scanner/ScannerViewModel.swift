//
//  ScannerViewModel.swift
//  Mirabilis Blue
//
//  Created by Max Ueda on 31/08/26.
//

import Combine
import Foundation
import hardware
import OSLog

@MainActor
final class ScannerViewModel: ObservableObject {

    enum State: Equatable {
        case idle
        case scanning
        case connecting(BluetoothDevice)
        case noDeviceFound
    }

    // MARK: - Dependencies
    private let bluetoothService: BluetoothService
    private var cancellables = Set<AnyCancellable>()

    var onConnected: ((BluetoothDevice) -> Void)?
    
    // MARK: - State

    @Published
    private(set) var state: State = .idle

    // MARK: - Private

    private var scanTimeoutTask: Task<Void, Never>?

    // MARK: - Init

    init(
        bluetoothService: BluetoothService
    ) {
        self.bluetoothService = bluetoothService
        bindBluetoothEvents()
    }
}

// MARK: - Presentation

extension ScannerViewModel {

    var isScanSheetPresented: Bool {
        state != .idle
    }

    var isScanning: Bool {
        state == .scanning
    }

    var canRetry: Bool {
        state == .noDeviceFound
    }
}

// MARK: - User Actions

extension ScannerViewModel {

    func scan() {
        startScan()
    }

    func retry() {
        startScan()
    }

    func cancel() {
        cancelScanTimeout()
        bluetoothService.stopScan()
        state = .idle

        AppLogger.ui.debug(
            "BLE scan cancelled by user"
        )
    }
}

// MARK: - Scan Lifecycle

private extension ScannerViewModel {

    func startScan() {
        cancelScanTimeout()

        state = .scanning

        AppLogger.ui.debug(
            "Starting device scan"
        )
        bluetoothService.startScan()

        startScanTimeout()
    }

    func startScanTimeout() {
        scanTimeoutTask = Task { [weak self] in
            do {
                try await Task.sleep(
                    for: .seconds(30)
                )
            } catch {
                return
            }

            guard !Task.isCancelled else {
                return
            }

            self?.handleScanTimeout()
        }
    }

    func cancelScanTimeout() {
        scanTimeoutTask?.cancel()
        scanTimeoutTask = nil
    }

    func handleScanTimeout() {
        guard state == .scanning else {
            return
        }
        bluetoothService.stopScan()
        state = .noDeviceFound

        AppLogger.ui.debug(
            "BLE scan timed out"
        )
    }
}

// MARK: - Lifecycle

extension ScannerViewModel {

    func tearDown() {
        cancelScanTimeout()
        bluetoothService.stopScan()
        state = .idle

        AppLogger.ui.debug(
            "ScannerViewModel torn down"
        )
    }
}

// MARK: - Bluetooth Bindings

private extension ScannerViewModel {

    func bindBluetoothEvents() {
        bindDeviceDiscovery()
    }

    func bindDeviceDiscovery() {
        bluetoothService.devicesPublisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    guard case .failure(let error) = completion else {
                        return
                    }

                    self?.handleBluetoothError(error)
                },
                receiveValue: { [weak self] device in
                    self?.handleDiscoveredDevice(device)
                }
            )
            .store(in: &cancellables)
    }
    
    func bindConnectionState(
        for device: BluetoothDevice
    ) {
        guard let publisher =
            bluetoothService.connectionStatePublisher() else {
            return
        }

        publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    guard case .failure(let error) = completion else {
                        return
                    }

                    self?.handleBluetoothError(error)
                },
                receiveValue: { [weak self] connectionState in
                    guard connectionState == .connected else {
                        return
                    }

                    self?.handleConnectedDevice(device)
                }
            )
            .store(in: &cancellables)
    }
}

// MARK: - Bluetooth Event Handling

private extension ScannerViewModel {

    func handleDiscoveredDevice(
        _ device: BluetoothDevice
    ) {
        guard state == .scanning else {
            return
        }

        cancelScanTimeout()
        bluetoothService.stopScan()

        state = .connecting(device)

        AppLogger.ui.debug(
            "Device discovered. Connecting to \(device.displayName, privacy: .public)"
        )

        bindConnectionState(for: device)

        Task {
            do {
                try await bluetoothService.connect()
            } catch {
                handleBluetoothError(error)
            }
        }
    }
    
    func handleConnectedDevice(
        _ device: BluetoothDevice
    ) {
        guard case .connecting = state else {
            return
        }

        state = .idle

        AppLogger.ui.debug(
            "Device connected. Opening device screen"
        )

        if let onConnected {
            onConnected(device)
        }
    }

    func handleBluetoothError(
        _ error: Error
    ) {
        cancelScanTimeout()
        bluetoothService.stopScan()

        state = .noDeviceFound

        AppLogger.ui.error(
            "Bluetooth BLE flow failed: \(error.localizedDescription, privacy: .public)"
        )
    }
}


