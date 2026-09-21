//
//  DeviceViewModel.swift
//  Mirabilis Blue
//
//  Created by Max Ueda on 31/08/26.
//

import Combine
import Foundation
import hardware
import OSLog

@MainActor
final class DeviceViewModel: ObservableObject {
    
    // MARK: - State
    
    enum State: Equatable {
        case loading
        case ready
        case disconnected
        case failed(String)
    }
    
    // MARK: - Dependencies
    
    private let bluetoothService: BluetoothService
    
    private var cancellables =
    Set<AnyCancellable>()

    private var observableValueCancellable: AnyCancellable?
    private var periodicEventCancellable: AnyCancellable?
    private var secureStateCancellable: AnyCancellable?
    
    
    // MARK: - Device
    
    let device: BluetoothDevice
    
    // MARK: - Presentation State
    
    @Published
    private(set) var state: State = .loading
    
    @Published
    private(set) var serialNumber: String?
    @Published
    private(set) var hardwareRevision: String?
    @Published
    private(set) var firmwareRevision: String?
    @Published
    private(set) var lastWrittenValue: String?
    
    @Published
    private(set) var observableValue: String?
    @Published
    private(set) var periodicEventValue: String?
    @Published
    private(set) var lastWriteWithoutResponseValue: String?
    @Published
    private(set) var secureState: String?
    @Published
    private(set) var totalUploadedBytes: UInt64?
    
    @Published
    private(set) var notifyingCharacteristics:
    Set<MirabilisGATT.Characteristic> = []
    
    @Published
    var observableWriteInput = ""
    @Published
    var writeWithoutResponseInput = ""
    @Published
    var secureWriteInput = ""
    
    @Published
    private(set) var characteristics:
    Set<MirabilisGATT.Characteristic> = []
    
    @Published
    private(set) var readingCharacteristics:
    Set<MirabilisGATT.Characteristic> = []
    
    @Published
    private(set) var writingCharacteristics:
    Set<MirabilisGATT.Characteristic> = []
    
    @Published
    var basicWriteInput = ""
    
    // MARK: - Reactive UI Capabilities
    
    @Published
    private var availableCharacteristics:
    Set<MirabilisGATT.Characteristic> = []
    
    @Published
    private(set) var canWriteBasicValue = false
    
    @Published
    private(set) var canWriteObservableValue = false
    @Published
    private(set) var canWriteWithoutResponseValue = false
    @Published
    private(set) var canWriteSecureValue = false
    
    var onDisconnected: (() -> Void)?
    
    // MARK: - Init
    
    init(
        device: BluetoothDevice,
        bluetoothService: BluetoothService
    ) {
        self.device = device
        self.bluetoothService = bluetoothService
        
        bindPresentationState()
        bindConnectionState()
        prepareCharacteristics()
        
        AppLogger.ui.debug(
            "DeviceViewModel initialized for \(device.displayName, privacy: .public)"
        )
    }
}

// MARK: - Presentation

extension DeviceViewModel {

    var deviceInformationCharacteristics: [
        MirabilisGATT.Characteristic
    ] {
        characteristics.filter {
            $0.service == .deviceInformation
        }
    }

    var isLoading: Bool {
        state == .loading
    }

    var isConnected: Bool {
        switch state {
        case .loading,
             .ready:
            return true

        case .disconnected,
             .failed:
            return false
        }
    }

    var statusText: String {
        switch state {
        case .loading:
            return "Discovering characteristics…"

        case .ready:
            return "Connected"

        case .disconnected:
            return "Disconnected"

        case .failed(let message):
            return message
        }
    }

    func value(
        for characteristic: MirabilisGATT.Characteristic
    ) -> String? {
        switch characteristic {
        case .serialNumber:
            return serialNumber

        case .hardwareRevision:
            return hardwareRevision

        case .firmwareRevision:
            return firmwareRevision

        case .lastWrittenValue:
            return lastWrittenValue

        case .observableValue:
            return observableValue

        case .periodicEventStream:
            return periodicEventValue

        case .lastWriteWithoutResponseValue:
            return lastWriteWithoutResponseValue

        case .secureState:
            return secureState

        case .totalUploadedBytes:
            return totalUploadedBytes.map(String.init)

        default:
            return nil
        }
    }

    func canRead(
        _ characteristic: MirabilisGATT.Characteristic
    ) -> Bool {
        availableCharacteristics.contains(
            characteristic
        )
    }

    func isReading(
        _ characteristic: MirabilisGATT.Characteristic
    ) -> Bool {
        readingCharacteristics.contains(
            characteristic
        )
    }

    func isWriting(
        _ characteristic: MirabilisGATT.Characteristic
    ) -> Bool {
        writingCharacteristics.contains(
            characteristic
        )
    }

    func canNotify(
        _ characteristic: MirabilisGATT.Characteristic
    ) -> Bool {
        availableCharacteristics.contains(
            characteristic
        ) &&
        characteristic.supportsNotifications
    }

    func isNotifying(
        _ characteristic: MirabilisGATT.Characteristic
    ) -> Bool {
        notifyingCharacteristics.contains(
            characteristic
        )
    }
}

// MARK: - Reactive Presentation State

private extension DeviceViewModel {

    func bindPresentationState() {
        bindAvailableCharacteristics()
        bindCanWriteBasicValue()
        bindCanWriteObservableValue()
        bindCanWriteWithoutResponseValue()
        bindCanWriteSecureValue()
    }

    func bindAvailableCharacteristics() {
        Publishers.CombineLatest(
            $state,
            $characteristics
        )
        .map {
            state,
            characteristics
                -> Set<MirabilisGATT.Characteristic> in

            guard state == .ready else {
                return []
            }

            return characteristics
        }
        .removeDuplicates()
        .sink { [weak self] characteristics in
            self?.availableCharacteristics =
                characteristics
        }
        .store(in: &cancellables)
    }

    func bindCanWriteBasicValue() {
        Publishers.CombineLatest3(
            $availableCharacteristics,
            $basicWriteInput,
            $writingCharacteristics
        )
        .map {
            availableCharacteristics,
            input,
            writingCharacteristics in

            availableCharacteristics.contains(
                .basicWrite
            ) &&
            !input.isEmpty &&
            !writingCharacteristics.contains(
                .basicWrite
            )
        }
        .removeDuplicates()
        .sink { [weak self] canWrite in
            self?.canWriteBasicValue =
                canWrite
        }
        .store(in: &cancellables)
    }

    func bindCanWriteObservableValue() {
        Publishers.CombineLatest3(
            $availableCharacteristics,
            $observableWriteInput,
            $writingCharacteristics
        )
        .map {
            availableCharacteristics,
            input,
            writingCharacteristics in

            availableCharacteristics.contains(
                .observableWrite
            ) &&
            !input.isEmpty &&
            !writingCharacteristics.contains(
                .observableWrite
            )
        }
        .removeDuplicates()
        .sink { [weak self] canWrite in
            self?.canWriteObservableValue =
                canWrite
        }
        .store(in: &cancellables)
    }

    func bindCanWriteWithoutResponseValue() {
        Publishers.CombineLatest3(
            $availableCharacteristics,
            $writeWithoutResponseInput,
            $writingCharacteristics
        )
        .map {
            availableCharacteristics,
            input,
            writingCharacteristics in

            availableCharacteristics.contains(
                .writeWithoutResponse
            ) &&
            !input.isEmpty &&
            !writingCharacteristics.contains(
                .writeWithoutResponse
            )
        }
        .removeDuplicates()
        .sink { [weak self] canWrite in
            self?.canWriteWithoutResponseValue = canWrite
        }
        .store(in: &cancellables)
    }

    func bindCanWriteSecureValue() {
        Publishers.CombineLatest3(
            $availableCharacteristics,
            $secureWriteInput,
            $writingCharacteristics
        )
        .map {
            availableCharacteristics,
            input,
            writingCharacteristics in

            availableCharacteristics.contains(
                .secureWrite
            ) &&
            !input.isEmpty &&
            !writingCharacteristics.contains(
                .secureWrite
            )
        }
        .removeDuplicates()
        .sink { [weak self] canWrite in
            self?.canWriteSecureValue = canWrite
        }
        .store(in: &cancellables)
    }

}


// MARK: - User Actions

extension DeviceViewModel {

    private func readBluetooth(
        _ characteristic: MirabilisGATT.Characteristic,
        operation: @escaping () async throws -> Data?
    ) {
        guard canRead(characteristic) else {
            return
        }

        readingCharacteristics.insert(characteristic)

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                let data = try await operation()

                readingCharacteristics.remove(characteristic)

                guard let data else {
                    return
                }

                handleUpdatedValue(
                    data,
                    for: characteristic
                )
            } catch {
                readingCharacteristics.remove(characteristic)

                state = .failed(
                    error.localizedDescription
                )

                AppLogger.ui.error(
                    "Bluetooth read failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }
    
    func readSerialNumber() {
        readBluetooth(
            .serialNumber,
            operation: bluetoothService.readSerialNumber
        )
    }

    func readHardwareRevision() {
        readBluetooth(
            .hardwareRevision,
            operation: bluetoothService.readHardwareRevision
        )
    }

    func readFirmwareRevision() {
        readBluetooth(
            .firmwareRevision,
            operation: bluetoothService.readFirmwareRevision
        )
    }

    func readLastWrittenValue() {
        readBluetooth(
            .lastWrittenValue,
            operation: bluetoothService.readLastWrittenValue
        )
    }


    func readLastWriteWithoutResponseValue() {
        readBluetooth(
            .lastWriteWithoutResponseValue,
            operation: bluetoothService.readLastWriteWithoutResponseValue
        )
    }

    func readSecureState() {
        readBluetooth(
            .secureState,
            operation: bluetoothService.readSecureState
        )
    }

    func readTotalUploadedBytes() {
        guard canRead(.totalUploadedBytes) else {
            return
        }

        readingCharacteristics.insert(
            .totalUploadedBytes
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                let value = try await
                    bluetoothService.readTotalUploadedBytes()

                readingCharacteristics.remove(
                    .totalUploadedBytes
                )

                totalUploadedBytes = value

                AppLogger.ui.debug(
                    "Bluetooth total uploaded bytes read completed"
                )
            } catch {
                readingCharacteristics.remove(
                    .totalUploadedBytes
                )

                state = .failed(
                    error.localizedDescription
                )

                AppLogger.ui.error(
                    "Bluetooth total uploaded bytes read failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }

    func writeBasicValue() {
        guard canWriteBasicValue,
              let data = basicWriteInput.data(
                  using: .utf8
              ) else {
            return
        }

        writingCharacteristics.insert(
            .basicWrite
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService.writeBasicValue(
                    data
                )

                writingCharacteristics.remove(
                    .basicWrite
                )

                AppLogger.ui.debug(
                    "Bluetooth basic write completed"
                )
            } catch {
                writingCharacteristics.remove(
                    .basicWrite
                )

                state = .failed(
                    error.localizedDescription
                )

                AppLogger.ui.error(
                    "Bluetooth basic write failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }


    func writeWithoutResponseValue() {
        guard canWriteWithoutResponseValue,
              let data = writeWithoutResponseInput.data(
                  using: .utf8
              ) else {
            return
        }

        writingCharacteristics.insert(
            .writeWithoutResponse
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService
                    .writeWithoutResponseValue(data)

                writingCharacteristics.remove(
                    .writeWithoutResponse
                )

                AppLogger.ui.debug(
                    "Bluetooth write without response completed"
                )
            } catch {
                writingCharacteristics.remove(
                    .writeWithoutResponse
                )

                state = .failed(
                    error.localizedDescription
                )

                AppLogger.ui.error(
                    "Bluetooth write without response failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }

    func writeSecureValue() {
        guard canWriteSecureValue,
              let data = secureWriteInput.data(
                  using: .utf8
              ) else {
            return
        }

        writingCharacteristics.insert(
            .secureWrite
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService.secureWriteValue(
                    data
                )

                writingCharacteristics.remove(
                    .secureWrite
                )

                AppLogger.ui.debug(
                    "Bluetooth secure write completed"
                )
            } catch {
                writingCharacteristics.remove(
                    .secureWrite
                )

                state = .failed(
                    error.localizedDescription
                )

                AppLogger.ui.error(
                    "Bluetooth secure write failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }

    func writeObservableValue() {
        guard canWriteObservableValue,
              let data = observableWriteInput.data(
                  using: .utf8
              ) else {
            return
        }

        writingCharacteristics.insert(
            .observableWrite
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService.writeObservableValue(
                    data
                )

                writingCharacteristics.remove(
                    .observableWrite
                )

                AppLogger.ui.debug(
                    "Bluetooth observable write completed"
                )
            } catch {
                writingCharacteristics.remove(
                    .observableWrite
                )

                state = .failed(
                    error.localizedDescription
                )

                AppLogger.ui.error(
                    "Bluetooth observable write failed: \(error.localizedDescription, privacy: .public)"
                )
            }
        }
    }

    func toggleObservableValueNotifications() {
        if isNotifying(.observableValue) {
            stopObservableValueNotifications()
        } else {
            startObservableValueNotifications()
        }
    }

    private func startObservableValueNotifications() {
        guard canNotify(.observableValue),
              observableValueCancellable == nil,
              let publisher =
                bluetoothService.observableValuePublisher() else {
            return
        }

        observableValueCancellable = publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    guard let self else {
                        return
                    }

                    observableValueCancellable = nil

                    if case .failure(let error) = completion {
                        notifyingCharacteristics.remove(
                            .observableValue
                        )

                        AppLogger.ui.error(
                            "Bluetooth observable notification failed: \(error.localizedDescription, privacy: .public)"
                        )
                    }
                },
                receiveValue: { [weak self] data in
                    guard let self else {
                        return
                    }

                    handleUpdatedValue(
                        data,
                        for: .observableValue
                    )
                }
            )

        notifyingCharacteristics.insert(
            .observableValue
        )

        AppLogger.ui.debug(
            "Bluetooth observable notifications enabled"
        )
    }

    private func stopObservableValueNotifications() {
        observableValueCancellable?.cancel()
        observableValueCancellable = nil

        notifyingCharacteristics.remove(
            .observableValue
        )

        AppLogger.ui.debug(
            "Bluetooth observable notifications disabled"
        )
    }

    func togglePeriodicEventNotifications() {
        toggleNotifications(
            for: .periodicEventStream
        )
    }

    func setNotifications(
        _ enabled: Bool,
        for characteristic: MirabilisGATT.Characteristic
    ) {
        guard canNotify(characteristic) else {
            return
        }

        switch characteristic {

        case .observableValue:
            if enabled {
                startObservableValueNotifications()
            } else {
                stopObservableValueNotifications()
            }

        case .periodicEventStream:
            if enabled {
                startPeriodicEventNotifications()
            } else {
                stopPeriodicEventNotifications()
            }

        case .secureState:
            if enabled {
                startSecureStateNotifications()
            } else {
                stopSecureStateNotifications()
            }

        default:
            break
        }
    }

    private func toggleNotifications(
        for characteristic: MirabilisGATT.Characteristic
    ) {
        setNotifications(
            !isNotifying(characteristic),
            for: characteristic
        )
    }
}

// MARK: - Lifecycle

extension DeviceViewModel {

    func tearDown() {
        observableValueCancellable?.cancel()
        observableValueCancellable = nil

        periodicEventCancellable?.cancel()
        periodicEventCancellable = nil

        secureStateCancellable?.cancel()
        secureStateCancellable = nil

        notifyingCharacteristics.remove(
            .observableValue
        )

        notifyingCharacteristics.remove(
            .periodicEventStream
        )

        notifyingCharacteristics.remove(
            .secureState
        )

        AppLogger.ui.debug(
            "DeviceViewModel torn down"
        )
    }
}

// MARK: - Characteristic Discovery

private extension DeviceViewModel {

    private func prepareCharacteristics() {
        characteristics = [
            .serialNumber,
            .hardwareRevision,
            .firmwareRevision,
            .basicWrite,
            .lastWrittenValue,
            .observableWrite,
            .observableValue,
            .periodicEventStream,
            .writeWithoutResponse,
            .lastWriteWithoutResponseValue,
            .secureWrite,
            .secureState,
            .totalUploadedBytes
        ]

        state = .ready

        AppLogger.ui.debug(
            "Bluetooth characteristics available"
        )
    }
    
    private func startPeriodicEventNotifications() {
        guard canNotify(.periodicEventStream),
              periodicEventCancellable == nil,
              let publisher =
                bluetoothService.periodicEventPublisher() else {
            return
        }

        periodicEventCancellable = publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    guard let self else {
                        return
                    }

                    periodicEventCancellable = nil

                    if case .failure(let error) = completion {
                        notifyingCharacteristics.remove(
                            .periodicEventStream
                        )

                        AppLogger.ui.error(
                            "Bluetooth periodic event notification failed: \(error.localizedDescription, privacy: .public)"
                        )
                    }
                },
                receiveValue: { [weak self] data in
                    guard let self else {
                        return
                    }

                    handleUpdatedValue(
                        data,
                        for: .periodicEventStream
                    )
                }
            )

        notifyingCharacteristics.insert(
            .periodicEventStream
        )

        AppLogger.ui.debug(
            "Bluetooth periodic event notifications enabled"
        )
    }

    private func stopPeriodicEventNotifications() {
        periodicEventCancellable?.cancel()
        periodicEventCancellable = nil

        notifyingCharacteristics.remove(
            .periodicEventStream
        )

        AppLogger.ui.debug(
            "Bluetooth periodic event notifications disabled"
        )
    }


    private func startSecureStateNotifications() {
        guard canNotify(.secureState),
              secureStateCancellable == nil,
              let publisher =
                bluetoothService.secureStatePublisher() else {
            return
        }

        secureStateCancellable = publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    guard let self else {
                        return
                    }

                    secureStateCancellable = nil

                    if case .failure(let error) = completion {
                        notifyingCharacteristics.remove(
                            .secureState
                        )

                        AppLogger.ui.error(
                            "Bluetooth secure state notification failed: \(error.localizedDescription, privacy: .public)"
                        )
                    }
                },
                receiveValue: { [weak self] data in
                    guard let self else {
                        return
                    }

                    handleUpdatedValue(
                        data,
                        for: .secureState
                    )
                }
            )

        notifyingCharacteristics.insert(
            .secureState
        )

        AppLogger.ui.debug(
            "Bluetooth secure state notifications enabled"
        )
    }

    private func stopSecureStateNotifications() {
        secureStateCancellable?.cancel()
        secureStateCancellable = nil

        notifyingCharacteristics.remove(
            .secureState
        )

        AppLogger.ui.debug(
            "Bluetooth secure state notifications disabled"
        )
    }
}

// MARK: - Value Updates

private extension DeviceViewModel {

    func handleUpdatedValue(
        _ data: Data,
        for characteristic:
            MirabilisGATT.Characteristic
    ) {
        readingCharacteristics.remove(
            characteristic
        )

        switch characteristic {

        case .serialNumber:
            serialNumber = data.utf8String

        case .hardwareRevision:
            hardwareRevision = data.utf8String

        case .firmwareRevision:
            firmwareRevision = data.utf8String

        case .lastWrittenValue:
            lastWrittenValue = data.utf8String

        case .observableValue:
            observableValue = data.utf8String

        case .periodicEventStream:
            periodicEventValue = data.uint8Value.map(String.init)

        case .lastWriteWithoutResponseValue:
            lastWriteWithoutResponseValue = data.utf8String

        case .secureState:
            secureState = data.utf8String

        default:
            break
        }
    }

}

// MARK: - Connection Handling

private extension DeviceViewModel {

    func bindConnectionState() {
        guard let publisher =
                bluetoothService.connectionStatePublisher() else {
            return
        }

        publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    if case .failure(let error) = completion {
                        self?.handleConnectionError(error)
                    }
                },
                receiveValue: { [weak self] connectionState in
                    guard let self else { return }

                    if connectionState == .connected {
                        if state == .disconnected {
                            state = .ready
                        }
                    } else if connectionState == .disconnected {
                        handleDisconnectedDevice()
                    }
                }
            )
            .store(in: &cancellables)
    }

    func handleDisconnectedDevice() {
        readingCharacteristics.removeAll()
        writingCharacteristics.removeAll()
        notifyingCharacteristics.removeAll()
        state = .disconnected

        AppLogger.ui.info(
            "Device disconnected while DeviceView is active"
        )

        onDisconnected?()
    }

    func handleConnectionError(
        _ error: Error
    ) {
        readingCharacteristics.removeAll()
        writingCharacteristics.removeAll()
        notifyingCharacteristics.removeAll()

        AppLogger.ui.error(
            "Device flow error: \(error.localizedDescription, privacy: .public)"
        )

        state = .failed(
            error.localizedDescription
        )
    }
}
