# File Transfer

## Overview

File transfer is implemented entirely by the Kotlin Multiplatform BLE
layer.

The iOS application no longer contains a second implementation of the
transfer protocol.

``` text
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
KMP file-transfer engine
    ↓
BleClient / KableClient
    ↓
Kable
```

## Migration from the Swift protocol engine

The previous native implementation had its own complete transfer state
machine in Swift.

It included:

-   `FileTransferService`;
-   `FileTransferProtocol`;
-   `FileTransferChunk`;
-   `FileTransferState`;
-   `FileTransferError`.

That implementation handled protocol details such as:

-   upload chunk creation;
-   sequence numbers;
-   batching;
-   ACK/NACK/CAN handling;
-   upload/download commands;
-   notification processing;
-   download packet assembly;
-   sequence validation;
-   cancellation;
-   transfer progress;
-   disconnect/error handling.

Those responsibilities are now provided by the KMP implementation and
are not duplicated in the iOS application.

## KMP protocol ownership

The KMP transfer engine owns the BLE protocol semantics, including:

-   start/end framing;
-   upload and download commands;
-   packet/chunk construction;
-   sequence numbering and rollover;
-   acknowledgement intervals;
-   ACK/NACK/CAN handling;
-   transfer cancellation;
-   upload progress;
-   download progress;
-   downloaded-data reconstruction;
-   secure/encrypted GATT transport.

`BluetoothService` only bridges the generated KMP API into forms
convenient for Swift.

## Swift responsibilities

The Swift feature now focuses on native presentation and file-system
integration.

`FileTransferViewModel` owns:

-   selected-file presentation;
-   file importer handling;
-   transfer progress/status presentation;
-   downloaded-data presentation;
-   file exporter presentation;
-   total-uploaded-byte statistics;
-   UI capability state such as whether upload/download/cancel is
    currently available.

The following types remain because they represent iOS-specific concerns
rather than BLE protocol mechanics:

-   `FileTransferView`;
-   `FileTransferViewModel`;
-   `SelectedFile`;
-   `DownloadedFileDocument`;
-   `FileSelectionError`.

## Upload

The upload path is:

``` text
FileTransferView
    ↓
FileTransferViewModel.uploadSelectedFile()
    ↓
BluetoothService.uploadFile(Data)
    ↓
Data → KotlinByteArray
    ↓
MirabilisBlueDevice.upload(data:)
    ↓
KMP transfer engine
    ↓
Kable
```

The ViewModel may set an immediate local uploading presentation state so
the UI responds without waiting for the first KMP emission. After that,
KMP file-transfer state is authoritative for progress and completion.

On upload completion, the KMP completed state contains no downloaded
payload. The ViewModel interprets that as upload completion and
refreshes Total Uploaded Bytes.

## Download

The download path is:

``` text
FileTransferView
    ↓
FileTransferViewModel.downloadFile()
    ↓
BluetoothService.downloadFile()
    ↓
MirabilisBlueDevice.download()
    ↓
KMP transfer engine
```

Download progress arrives through the KMP file-transfer state stream.

When the completed state contains data, `BluetoothService` converts the
KMP byte array to Foundation `Data`. `FileTransferViewModel` stores the
result and presents the native file exporter.

The file exporter and `DownloadedFileDocument` remain Swift
responsibilities because they belong to the iOS file-system/UI boundary.

## Cancellation

Cancellation is no longer implemented by constructing a Swift protocol
packet.

``` text
FileTransferViewModel.cancelTransfer()
    ↓
BluetoothService.cancelFileTransfer()
    ↓
MirabilisBlueDevice.cancelFileTransfer()
    ↓
KMP transfer engine
```

KMP updates the transfer state accordingly and the UI reacts through
Combine.

## Transfer state

KMP exports its file-transfer state implementations to Swift.
`BluetoothService` maps those generated framework types into a
lightweight Swift-facing `BluetoothFileTransferState`.

Conceptually:

``` text
KMP FileTransferState
    ↓
BluetoothService mapper
    ↓
BluetoothFileTransferState
    ↓
Combine
    ↓
FileTransferViewModel
    ↓
FileTransferPresentationState
    ↓
SwiftUI
```

The mapper is `nonisolated` because it is a pure, stateless
transformation used from a Combine pipeline.

The KMP types are explicitly namespace-qualified where necessary
(`hardware.FileTransferState`, etc.) to avoid collisions with similarly
named Swift types during migration.

## Progress

Upload state provides both transferred and total byte counts, allowing
determinate progress.

Download state provides the transferred byte count, so the iOS UI
presents downloaded bytes as an indeterminate transfer status until
completion.

The Swift ViewModel derives human-readable status and progress values
from the KMP state; it does not calculate protocol-level transfer
progress independently.

## Maximum file size

The maximum selectable file size comes from the KMP file-transfer
protocol through `BluetoothService.maximumFileSize`.

The limit is therefore defined once by the protocol implementation
rather than duplicated as a Swift constant.

File selection still validates the chosen file before starting the
transfer so the user receives an immediate iOS-side error for an empty,
invalid, or oversized file.

## Total Uploaded Bytes

Total Uploaded Bytes is a normal KMP GATT read exposed by
`BluetoothService`.

`FileTransferViewModel` reads the statistic when appropriate and
refreshes it after a successful upload.

The Swift application does not decode the BLE characteristic manually
through CoreBluetooth.

## Result

The final boundary is intentionally simple:

``` text
KMP:
    transfer protocol + BLE transport + transfer state

Swift:
    Combine binding + presentation + file importer/exporter
```

This eliminates two independent protocol engines and ensures that both
upload and download use the same shared KMP implementation.
