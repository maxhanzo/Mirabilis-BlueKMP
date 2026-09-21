//
//  BluetoothConnectionController.swift
//  Mirabilis Blue
//

import Combine
import Foundation
import OSLog
import hardware

@MainActor
final class BluetoothConnectionController: ObservableObject {

    enum State: Equatable {
        case disconnected
        case connecting
        case connected(BluetoothDevice)
    }

    private let bluetoothService: BluetoothService
    private var connectionCancellable: AnyCancellable?
    private var presentationCancellables = Set<AnyCancellable>()

    @Published private(set) var state: State = .disconnected
    @Published private(set) var isConnected = false
    @Published private(set) var lastConnectedDevice: BluetoothDevice?
    @Published private(set) var isReconnecting = false
    @Published var shouldPresentReconnectAlert = false

    private var intentionalDisconnect = false

    init(
        bluetoothService: BluetoothService
    ) {
        self.bluetoothService = bluetoothService
        bindPresentationState()
    }

    var isConnecting: Bool {
        state == .connecting
    }

    var reconnectMessage: String {
        guard let device = lastConnectedDevice else {
            return "The Bluetooth connection was lost."
        }

        return "The connection to \(device.displayName) was lost. Move closer to the device and try again."
    }

    func trackConnectedDevice(
        _ device: BluetoothDevice
    ) {
        lastConnectedDevice = device
        state = .connected(device)
        shouldPresentReconnectAlert = false
        isReconnecting = false
        intentionalDisconnect = false
        bindConnectionState()
    }

    func retryConnection() {
        guard lastConnectedDevice != nil,
              !isReconnecting else {
            shouldPresentReconnectAlert = false
            return
        }

        shouldPresentReconnectAlert = false
        isReconnecting = true
        state = .connecting

        Task { [weak self] in
            guard let self else { return }

            do {
                try await bluetoothService.connect()
            } catch {
                isReconnecting = false
                state = .disconnected
                shouldPresentReconnectAlert =
                    lastConnectedDevice != nil

                AppLogger.bluetooth.error(
                    "Reconnect failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }

    func disconnect() async throws {
        intentionalDisconnect = true
        shouldPresentReconnectAlert = false
        try await bluetoothService.disconnect()
        state = .disconnected
    }

    func dismissReconnectAlert() {
        shouldPresentReconnectAlert = false
    }
}

private extension BluetoothConnectionController {

    func bindPresentationState() {
        $state
            .map { state in
                if case .connected = state { return true }
                return false
            }
            .removeDuplicates()
            .sink { [weak self] in self?.isConnected = $0 }
            .store(in: &presentationCancellables)
    }

    func bindConnectionState() {
        connectionCancellable?.cancel()

        guard let publisher =
                bluetoothService.connectionStatePublisher() else {
            return
        }

        connectionCancellable = publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    guard case .failure(let error) = completion else { return }
                    self?.handleConnectionFailure(error)
                },
                receiveValue: { [weak self] connectionState in
                    self?.handleConnectionState(connectionState)
                }
            )
    }

    func handleConnectionState(
        _ connectionState: BleDeviceState
    ) {
        switch connectionState {
        case .connected:
            if let device = lastConnectedDevice {
                state = .connected(device)
            }
            intentionalDisconnect = false
            isReconnecting = false
            shouldPresentReconnectAlert = false

        case .connecting:
            state = .connecting

        case .disconnected:
            state = .disconnected
            isReconnecting = false

            if intentionalDisconnect {
                intentionalDisconnect = false
                shouldPresentReconnectAlert = false
            } else if lastConnectedDevice != nil {
                shouldPresentReconnectAlert = true
            }

        default:
            break
        }
    }

    func handleConnectionFailure(
        _ error: Error
    ) {
        isReconnecting = false
        state = .disconnected
        shouldPresentReconnectAlert =
            !intentionalDisconnect &&
            lastConnectedDevice != nil
        intentionalDisconnect = false

        AppLogger.bluetooth.error(
            "Connection flow failed: \(error.localizedDescription, privacy: .public)"
        )
    }
}
