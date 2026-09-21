//
//  AppCoordinator.swift
//  Mirabilis Blue
//

import Combine
import Foundation
import hardware
import OSLog

@MainActor
final class AppCoordinator: ObservableObject {

    enum Route: Hashable {
        case device(BluetoothDevice)
        case fileTransfer(BluetoothDevice)
    }

    private let bluetoothService: BluetoothService
    let connectionController: BluetoothConnectionController

    @Published var path: [Route] = []
    let scannerViewModel: ScannerViewModel

    init() {
        let bluetoothService = BluetoothService()
        self.bluetoothService = bluetoothService
        self.connectionController = BluetoothConnectionController(
            bluetoothService: bluetoothService
        )
        self.scannerViewModel = ScannerViewModel(
            bluetoothService: bluetoothService
        )

        self.scannerViewModel.onConnected = { [weak self] device in
            self?.connectionController.trackConnectedDevice(device)
            self?.showDevice(device)
        }
    }
}

extension AppCoordinator {

    func showDevice(_ device: BluetoothDevice) {
        path.append(.device(device))
    }

    func showFileTransfer(for device: BluetoothDevice) {
        path.append(.fileTransfer(device))
    }

    func popToScanner() {
        path.removeAll()
    }

    func disconnectAndReturnToScanner() {
        Task { [weak self] in
            guard let self else { return }

            do {
                try await connectionController.disconnect()
            } catch {
                AppLogger.bluetooth.error(
                    "Disconnect failed: \(error.localizedDescription, privacy: .public)"
                )
            }

            popToScanner()
        }
    }
}

extension AppCoordinator {

    func makeDeviceViewModel(
        device: BluetoothDevice
    ) -> DeviceViewModel {
        DeviceViewModel(
            device: device,
            bluetoothService: bluetoothService
        )
    }

    func makeFileTransferViewModel(
        device: BluetoothDevice
    ) -> FileTransferViewModel {
        FileTransferViewModel(
            device: device,
            bluetoothService: bluetoothService
        )
    }
}
