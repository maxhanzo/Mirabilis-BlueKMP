//
//  BluetoothService.swift
//  Mirabilis Blue Combine
//
//  Created by Max Ueda on 21/09/26.
//

import Combine
import Foundation
import hardware
import KMPNativeCoroutinesAsync
import KMPNativeCoroutinesCombine


enum BluetoothFileTransferState: Equatable {
    case idle
    case uploading(
        bytesTransferred: Int,
        totalBytes: Int
    )
    case downloading(
        bytesTransferred: Int
    )
    case completed(
        data: Data?
    )
    case cancelled
    case failed(
        message: String
    )
}

final class BluetoothService {

    // MARK: - Dependencies

    private let service: MirabilisBlueService

    // MARK: - State

    private var discoveredDevice: MirabilisBlueDevice?
    private var connectionCancellable: AnyCancellable?

    // MARK: - Publishers

    lazy var devicesPublisher: AnyPublisher<BluetoothDevice, Error> = {
        createPublisher(for: service.getDevices())
            .compactMap { devices -> MirabilisBlueDevice? in
                devices.first as? MirabilisBlueDevice
            }
            .handleEvents(
                receiveOutput: { [weak self] device in
                    self?.discoveredDevice = device
                }
            )
            .compactMap { device in
                Self.makeBluetoothDevice(from: device)
            }
            .eraseToAnyPublisher()
    }()

    // MARK: - Init

    init() {
        service = MirabilisBlueService(mock: false)
    }

    var maximumFileSize: Int {
        Int(hardware.FileTransferProtocol.shared.maximumFileSize)
    }

    // MARK: - Scan

    func startScan() {
        print("[Bluetooth] Starting scan...")
        service.startScan(timeout: 30_000)
    }

    func stopScan() {
        print("[Bluetooth] Stopping scan...")
        service.stopScan()
    }

    // MARK: - Connection

    func connect() async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        print("[Bluetooth] Connecting to \(device.getName())...")

        _ = try await asyncFunction(
            for: device.connect()
        )

        print("[Bluetooth] Connect command completed")
    }

    func disconnect() async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        _ = try await asyncFunction(
            for: device.disconnect()
        )
    }

    func connectionStatePublisher() -> AnyPublisher<BleDeviceState, Error>? {
        guard let device = discoveredDevice else {
            return nil
        }

        return createPublisher(for: device.getState())
            .eraseToAnyPublisher()
    }

    // MARK: - Mapping

    private static func makeBluetoothDevice(
        from device: MirabilisBlueDevice
    ) -> BluetoothDevice? {
        guard let id = UUID(
            uuidString: device.getIdentifier()
        ) else {
            return nil
        }

        return BluetoothDevice(
            id: id,
            name: device.getName(),
            rssi: 0
        )
    }
    
    // MARK: - Read
    func readSerialNumber() async throws -> Data? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = try await asyncFunction(
            for: device.readSerialNumber()
        )

        return bytes.map(Self.makeData)
    }

    func readHardwareRevision() async throws -> Data? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = try await asyncFunction(
            for: device.readHardwareRevision()
        )

        return bytes.map(Self.makeData)
    }

    func readFirmwareRevision() async throws -> Data? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = try await asyncFunction(
            for: device.readFirmwareRevision()
        )

        return bytes.map(Self.makeData)
    }
    
    // MARK: - Write
    
    func writeBasicValue(
        _ data: Data
    ) async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = Self.makeKotlinByteArray(
            from: data
        )

        _ = try await asyncFunction(
            for: device.writeBasic(
                value: bytes
            )
        )
    }

    func readLastWrittenValue() async throws -> Data? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = try await asyncFunction(
            for: device.readLastWrittenValue()
        )

        return bytes.map(Self.makeData)
    }
    
    // MARK: - Observable Value

    func writeObservableValue(
        _ data: Data
    ) async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = Self.makeKotlinByteArray(
            from: data
        )

        _ = try await asyncFunction(
            for: device.writeObservable(
                value: bytes
            )
        )
    }

    func observableValuePublisher()
        -> AnyPublisher<Data, Error>? {

        guard let device = discoveredDevice else {
            return nil
        }

        return createPublisher(
            for: device.observeValue()
        )
        .map(Self.makeData)
        .eraseToAnyPublisher()
    }
    
    func periodicEventPublisher()
        -> AnyPublisher<Data, Error>? {

        guard let device = discoveredDevice else {
            return nil
        }

        return createPublisher(
            for: device.observePeriodicEvents()
        )
        .map(Self.makeData)
        .eraseToAnyPublisher()
    }
    


    // MARK: - Write Without Response

    func writeWithoutResponseValue(
        _ data: Data
    ) async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = Self.makeKotlinByteArray(
            from: data
        )

        _ = try await asyncFunction(
            for: device.writeWithoutResponse(
                value: bytes
            )
        )
    }

    func readLastWriteWithoutResponseValue() async throws -> Data? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = try await asyncFunction(
            for: device.readLastWriteWithoutResponseValue()
        )

        return bytes.map(Self.makeData)
    }

    // MARK: - Secure Operations

    func secureWriteValue(
        _ data: Data
    ) async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = Self.makeKotlinByteArray(
            from: data
        )

        _ = try await asyncFunction(
            for: device.secureWrite(
                value: bytes
            )
        )
    }

    func readSecureState() async throws -> Data? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = try await asyncFunction(
            for: device.readSecureState()
        )

        return bytes.map(Self.makeData)
    }

    func secureStatePublisher()
        -> AnyPublisher<Data, Error>? {

        guard let device = discoveredDevice else {
            return nil
        }

        return createPublisher(
            for: device.observeSecureState()
        )
        .map(Self.makeData)
        .eraseToAnyPublisher()
    }

    // MARK: - Statistics

    func readTotalUploadedBytes() async throws -> UInt64? {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let value = try await asyncFunction(
            for: device.readTotalUploadedBytes()
        )

        return value?.uint64Value
    }

    

    // MARK: - File Transfer

    func fileTransferStatePublisher()
        -> AnyPublisher<BluetoothFileTransferState, Error>? {

        guard let device = discoveredDevice else {
            return nil
        }

        return createPublisher(
            for: device.getFileTransferState()
        )
        .compactMap(Self.makeFileTransferState)
        .eraseToAnyPublisher()
    }

    func uploadFile(
        _ data: Data
    ) async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        let bytes = Self.makeKotlinByteArray(
            from: data
        )

        _ = try await asyncFunction(
            for: device.upload(
                data: bytes
            )
        )
    }

    func downloadFile() async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        _ = try await asyncFunction(
            for: device.download()
        )
    }

    func cancelFileTransfer() async throws {
        guard let device = discoveredDevice else {
            throw BluetoothServiceError.deviceUnavailable
        }

        _ = try await asyncFunction(
            for: device.cancelFileTransfer()
        )
    }

    nonisolated private static func makeFileTransferState(
        _ state: any hardware.FileTransferState
    ) -> BluetoothFileTransferState? {

        switch state {

        case is hardware.FileTransferStateIdle:
            return .idle

        case let state as hardware.FileTransferStateUploading:
            return .uploading(
                bytesTransferred:
                    Int(state.bytesTransferred),
                totalBytes:
                    Int(state.totalBytes)
            )

        case let state as hardware.FileTransferStateDownloading: //Warning:  Cast from 'FileTransferState' to unrelated type 'hardware.FileTransferStateDownloading' always fails
            return .downloading(
                bytesTransferred:
                    Int(state.bytesTransferred)
            )

        case let state as hardware.FileTransferStateCompleted:
            return .completed(
                data: state.data.map(Self.makeData)
            )

        case is hardware.FileTransferStateCancelled:
            return .cancelled

        case let state as hardware.FileTransferStateFailed:
            return .failed(
                message: state.message
            )

        default:
            return nil
        }
    }

    // MARK: - Data Mapping

    nonisolated private static func makeData(
        _ bytes: KotlinByteArray
    ) -> Data {
        Data(
            (0..<Int(bytes.size)).map {
                UInt8(
                    bitPattern: bytes.get(
                        index: Int32($0)
                    )
                )
            }
        )
    }

    nonisolated private static func makeKotlinByteArray(
        from data: Data
    ) -> KotlinByteArray {
        KotlinByteArray(
            size: Int32(data.count)
        ) { index in
            KotlinByte(
                value: Int8(
                    bitPattern: data[
                        Int(truncating: index)
                    ]
                )
            )
        }
    }
}



enum BluetoothServiceError: Error {
    case deviceUnavailable
}
