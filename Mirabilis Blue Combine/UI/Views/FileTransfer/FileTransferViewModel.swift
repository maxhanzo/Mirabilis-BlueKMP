//
//  FileTransferViewModel.swift
//  Mirabilis Blue
//
//  Created by Max Ueda on 04/09/26.
//

import Combine
import Foundation
import hardware
import OSLog

fileprivate enum TransferState: Equatable {
    case idle
    case uploading(
        bytesTransferred: Int,
        totalBytes: Int
    )
    case downloading(
        bytesTransferred: Int
    )
    case completedUpload(
        bytesTransferred: Int
    )
    case completedDownload(
        data: Data
    )
    case cancelled
    case failed(
        message: String
    )

    var isTransferring: Bool {
        switch self {
        case .uploading,
             .downloading:
            return true

        case .idle,
             .completedUpload,
             .completedDownload,
             .cancelled,
             .failed:
            return false
        }
    }
}

struct FileTransferPresentationState:
    Equatable {

    let statusText: String?
    let uploadProgress: Double?
    let uploadProgressText: String?
    let indeterminateProgressText: String?
    let isError: Bool

    fileprivate static func make(
        transferState: TransferState,
        isConnected: Bool
    ) -> FileTransferPresentationState {

        switch transferState {

        case .idle:
            return .init(
                statusText:
                    isConnected
                    ? nil
                    : "Bluetooth disconnected",
                uploadProgress: nil,
                uploadProgressText: nil,
                indeterminateProgressText: nil,
                isError: false
            )

        case let .uploading(
            bytesTransferred,
            totalBytes
        ):
            let progressText = """
            \(bytesTransferred.formatted()) / \
            \(totalBytes.formatted()) bytes
            """

            let progress: Double? =
                totalBytes > 0
                ? Double(bytesTransferred) /
                    Double(totalBytes)
                : nil

            return .init(
                statusText: progressText,
                uploadProgress: progress,
                uploadProgressText: progressText,
                indeterminateProgressText: nil,
                isError: false
            )

        case let .downloading(
            bytesTransferred
        ):
            let text = """
            \(bytesTransferred.formatted()) \
            bytes downloaded
            """

            return .init(
                statusText: text,
                uploadProgress: nil,
                uploadProgressText: nil,
                indeterminateProgressText: text,
                isError: false
            )

        case let .completedUpload(
            bytesTransferred
        ):
            return .init(
                statusText:
                    "Upload completed — \(bytesTransferred.formatted()) bytes",
                uploadProgress: nil,
                uploadProgressText: nil,
                indeterminateProgressText: nil,
                isError: false
            )

        case let .completedDownload(
            data
        ):
            return .init(
                statusText:
                    "Download completed — \(data.count.formatted()) bytes",
                uploadProgress: nil,
                uploadProgressText: nil,
                indeterminateProgressText: nil,
                isError: false
            )

        case .cancelled:
            return .init(
                statusText: "Transfer cancelled",
                uploadProgress: nil,
                uploadProgressText: nil,
                indeterminateProgressText: nil,
                isError: false
            )

        case let .failed(message):
            return .init(
                statusText: message,
                uploadProgress: nil,
                uploadProgressText: nil,
                indeterminateProgressText: nil,
                isError: true
            )
        }
    }
}

@MainActor
final class FileTransferViewModel: ObservableObject {

    // MARK: - Dependencies

    private let bluetoothService:
        BluetoothService

    private var cancellables =
        Set<AnyCancellable>()

    // MARK: - Device

    let device: BluetoothDevice

    // MARK: - Statistics

    @Published
    private(set) var totalUploadedBytes:
        UInt64?

    @Published
    private(set) var
        isReadingTotalUploadedBytes = false

    // MARK: - File Selection

    @Published
    private(set) var selectedFile:
        SelectedFile?

    // MARK: - Download Export

    @Published
    private(set) var downloadedData:
        Data?

    @Published
    var isFileExporterPresented = false

    let defaultDownloadFilename =
        "mirabilis_download.bin"

    // MARK: - Transfer

    @Published
    private var transferState:
        TransferState = .idle

    @Published
    private(set) var transferPresentation =
        FileTransferPresentationState.make(
            transferState: .idle,
            isConnected: false
        )

    @Published
    private(set) var errorMessage:
        String?

    private var hasLoaded = false
    private var activeUploadSize: Int?

    @Published
    private(set) var isConnected = false

    // MARK: - Reactive UI Capabilities

    @Published
    private var isTransferAvailable = false

    @Published
    private(set) var canReadStatistics = false

    @Published
    private(set) var canUpload = false

    @Published
    private(set) var canCancel = false

    init(
        device: BluetoothDevice,
        bluetoothService: BluetoothService
    ) {
        self.device = device
        self.bluetoothService = bluetoothService

        bindConnectionState()
        bindFileTransferState()
        bindPresentationState()

        AppLogger.ui.debug(
            "FileTransferViewModel initialized for \(device.displayName, privacy: .public)"
        )
    }
}

// MARK: - Connection State Binding

private extension FileTransferViewModel {

    func bindConnectionState() {
        guard let publisher =
                bluetoothService.connectionStatePublisher() else {
            return
        }

        publisher
            .map { $0 == .connected }
            .removeDuplicates()
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    if case .failure(let error) = completion {
                        self?.errorMessage =
                            error.localizedDescription
                    }
                },
                receiveValue: { [weak self] isConnected in
                    guard let self else {
                        return
                    }

                    self.isConnected = isConnected

                    if !isConnected {
                        isReadingTotalUploadedBytes = false
                    } else if hasLoaded {
                        readTotalUploadedBytes()
                    }
                }
            )
            .store(in: &cancellables)
    }
}

// MARK: - Reactive Presentation State

private extension FileTransferViewModel {

    func bindPresentationState() {
        bindTransferPresentation()
        bindTransferAvailability()
        bindCanReadStatistics()
        bindCanUpload()
        bindCanCancel()
    }

    func bindTransferPresentation() {
        Publishers.CombineLatest(
            $transferState,
            $isConnected
        )
        .map {
            transferState,
            isConnected in

            FileTransferPresentationState.make(
                transferState: transferState,
                isConnected: isConnected
            )
        }
        .removeDuplicates()
        .sink { [weak self] presentation in
            self?.transferPresentation =
                presentation
        }
        .store(in: &cancellables)
    }

    func bindTransferAvailability() {
        Publishers.CombineLatest(
            $isConnected,
            $transferState
        )
        .map {
            isConnected,
            transferState in

            isConnected &&
            !transferState.isTransferring
        }
        .removeDuplicates()
        .sink { [weak self] isAvailable in
            self?.isTransferAvailable =
                isAvailable
        }
        .store(in: &cancellables)
    }

    func bindCanReadStatistics() {
        Publishers.CombineLatest(
            $isTransferAvailable,
            $isReadingTotalUploadedBytes
        )
        .map {
            isAvailable,
            isReading in

            isAvailable &&
            !isReading
        }
        .removeDuplicates()
        .sink { [weak self] canReadStatistics in
            self?.canReadStatistics =
                canReadStatistics
        }
        .store(in: &cancellables)
    }

    func bindCanUpload() {
        Publishers.CombineLatest(
            $isTransferAvailable,
            $selectedFile
        )
        .map {
            isAvailable,
            selectedFile in

            isAvailable &&
            selectedFile != nil
        }
        .removeDuplicates()
        .sink { [weak self] canUpload in
            self?.canUpload =
                canUpload
        }
        .store(in: &cancellables)
    }

    func bindCanCancel() {
        Publishers.CombineLatest(
            $isConnected,
            $transferState
        )
        .map {
            isConnected,
            transferState in

            isConnected &&
            transferState.isTransferring
        }
        .removeDuplicates()
        .sink { [weak self] canCancel in
            self?.canCancel =
                canCancel
        }
        .store(in: &cancellables)
    }
}

// MARK: - Presentation

extension FileTransferViewModel {

    var canChooseFile: Bool {
        isTransferAvailable
    }

    var canDownload: Bool {
        isTransferAvailable
    }

    var totalUploadedBytesText:
        String {
        guard let totalUploadedBytes else {
            return "Not read"
        }

        return """
        \(totalUploadedBytes.formatted()) bytes
        """
    }

    var hasSelectedFile: Bool {
        selectedFile != nil
    }

    var downloadedDocument:
        DownloadedFileDocument? {
        guard let downloadedData else {
            return nil
        }

        return DownloadedFileDocument(
            data: downloadedData
        )
    }
}

// MARK: - Lifecycle / Statistics

extension FileTransferViewModel {

    func load() {
        guard !hasLoaded else {
            return
        }

        hasLoaded = true

        guard isConnected else {
            return
        }

        readTotalUploadedBytes()
    }

    func readTotalUploadedBytes() {
        guard isConnected else {
            handleNotConnected()
            return
        }

        guard !isReadingTotalUploadedBytes else {
            return
        }

        errorMessage = nil
        isReadingTotalUploadedBytes = true

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                totalUploadedBytes =
                    try await bluetoothService
                        .readTotalUploadedBytes()

                isReadingTotalUploadedBytes = false
            } catch {
                isReadingTotalUploadedBytes = false
                errorMessage =
                    error.localizedDescription
            }
        }
    }
}

// MARK: - File Selection

extension FileTransferViewModel {

    func selectFile(
        at url: URL
    ) {
        errorMessage = nil

        let didStartAccessing =
            url.startAccessingSecurityScopedResource()

        defer {
            if didStartAccessing {
                url.stopAccessingSecurityScopedResource()
            }
        }

        do {
            let resourceValues =
                try url.resourceValues(
                    forKeys: [
                        .fileSizeKey,
                        .isRegularFileKey
                    ]
                )

            guard resourceValues
                .isRegularFile == true else {
                throw FileSelectionError
                    .notARegularFile
            }

            if let fileSize =
                resourceValues.fileSize {

                guard fileSize > 0 else {
                    throw FileSelectionError
                        .emptyFile
                }

                guard fileSize <=
                        bluetoothService.maximumFileSize else {
                    throw FileSelectionError
                        .fileTooLarge
                }
            }

            let data = try Data(
                contentsOf: url
            )

            guard !data.isEmpty else {
                throw FileSelectionError
                    .emptyFile
            }

            guard data.count <=
                    bluetoothService.maximumFileSize else {
                throw FileSelectionError
                    .fileTooLarge
            }

            selectedFile =
                SelectedFile(
                    name:
                        url.lastPathComponent,
                    data: data
                )

            AppLogger.ui.info(
                "Selected file: \(url.lastPathComponent, privacy: .public), \(data.count) bytes"
            )

        } catch let error
            as FileSelectionError {

            selectedFile = nil
            errorMessage =
                error.localizedDescription

        } catch {
            selectedFile = nil
            errorMessage =
                "Unable to read the selected file."

            AppLogger.ui.error(
                "Unable to read selected file: \(error.localizedDescription, privacy: .public)"
            )
        }
    }

    func handleFileImporterError(
        _ error: Error
    ) {
        errorMessage =
            error.localizedDescription
    }

    func handleFileExporterResult(
        _ result: Result<URL, Error>
    ) {
        switch result {

        case .success(let url):
            AppLogger.ui.info(
                "Downloaded file exported to \(url.lastPathComponent, privacy: .public)"
            )

        case .failure(let error):
            errorMessage =
                error.localizedDescription
        }
    }
}

// MARK: - Transfer Actions

extension FileTransferViewModel {

    func uploadSelectedFile() {
        guard isConnected else {
            handleNotConnected()
            return
        }

        guard let selectedFile else {
            return
        }

        errorMessage = nil
        downloadedData = nil
        activeUploadSize = selectedFile.data.count

        // Give the UI an immediate transferring state while the Bluetooth
        // state stream begins emitting the authoritative progress.
        transferState = .uploading(
            bytesTransferred: 0,
            totalBytes: selectedFile.data.count
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService.uploadFile(
                    selectedFile.data
                )
            } catch {
                transferState = .failed(
                    message: error.localizedDescription
                )
            }
        }
    }

    func downloadFile() {
        guard isConnected else {
            handleNotConnected()
            return
        }

        errorMessage = nil
        downloadedData = nil

        transferState = .downloading(
            bytesTransferred: 0
        )

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService.downloadFile()
            } catch {
                transferState = .failed(
                    message: error.localizedDescription
                )
            }
        }
    }

    func cancelTransfer() {
        guard isConnected else {
            handleNotConnected()
            return
        }

        Task { [weak self] in
            guard let self else {
                return
            }

            do {
                try await bluetoothService
                    .cancelFileTransfer()
            } catch {
                transferState = .failed(
                    message: error.localizedDescription
                )
            }
        }
    }
}

// MARK: - File Transfer State

private extension FileTransferViewModel {

    func bindFileTransferState() {
        guard let publisher =
                bluetoothService.fileTransferStatePublisher() else {
            return
        }

        publisher
            .receive(on: DispatchQueue.main)
            .sink(
                receiveCompletion: { [weak self] completion in
                    if case .failure(let error) = completion {
                        self?.transferState = .failed(
                            message:
                                error.localizedDescription
                        )
                    }
                },
                receiveValue: { [weak self] state in
                    self?.handleFileTransferState(
                        state
                    )
                }
            )
            .store(in: &cancellables)
    }

    func handleFileTransferState(
        _ state: BluetoothFileTransferState
    ) {
        switch state {

        case .idle:
            transferState = .idle

        case let .uploading(
            bytesTransferred,
            totalBytes
        ):
            activeUploadSize = totalBytes

            transferState = .uploading(
                bytesTransferred: bytesTransferred,
                totalBytes: totalBytes
            )

        case let .downloading(
            bytesTransferred
        ):
            transferState = .downloading(
                bytesTransferred: bytesTransferred
            )

        case let .completed(data):
            if let data {
                downloadedData = data

                transferState = .completedDownload(
                    data: data
                )

                isFileExporterPresented = true
            } else {
                let uploadedBytes =
                    activeUploadSize ?? 0

                transferState = .completedUpload(
                    bytesTransferred: uploadedBytes
                )

                activeUploadSize = nil

                if isConnected {
                    readTotalUploadedBytes()
                }
            }

        case .cancelled:
            activeUploadSize = nil
            transferState = .cancelled

        case let .failed(message):
            activeUploadSize = nil
            transferState = .failed(
                message: message
            )
        }
    }
}

// MARK: - Errors

private extension FileTransferViewModel {

    func handleNotConnected() {
        isReadingTotalUploadedBytes =
            false

        errorMessage =
            "Connect to the device before using file transfer."
    }
}
