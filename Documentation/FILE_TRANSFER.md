# File Transfer

## Ownership

The file-transfer protocol is implemented in KMP. The iOS app does not contain a second protocol engine.

```text
FileTransferView
    ↓
FileTransferViewModel
    ↓
BluetoothService
    ↓
MirabilisBlueDevice
    ├── upload(data:)
    ├── download()
    ├── cancelFileTransfer()
    └── getFileTransferState()
    ↓
KMP transfer engine
    ↓
Kable
```

The removed Swift implementation previously contained `FileTransferService`, `FileTransferProtocol`, `FileTransferChunk`, `FileTransferState`, and `FileTransferError`. Those types are no longer needed because chunking, sequencing, ACK/NACK, cancellation and download reconstruction are KMP responsibilities.

## Swift responsibilities

`FileTransferViewModel` handles file selection, presentation state, progress text, export presentation and total-uploaded-byte statistics. `SelectedFile`, `DownloadedFileDocument`, and `FileSelectionError` remain because they are iOS UI/file-system concerns.

The maximum selectable file size is read from the KMP `FileTransferProtocol` through `BluetoothService.maximumFileSize`; the protocol constant is not duplicated in Swift.

## State bridge

KMP `FileTransferState` implementations are mapped by `BluetoothService` to `BluetoothFileTransferState`. The mapper is `nonisolated` because it is a stateless Combine transformation. A completed state with data represents a download result; a completed state without data represents upload completion.
