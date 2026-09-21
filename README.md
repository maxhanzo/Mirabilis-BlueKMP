# Mirabilis Blue --- KMP + Combine

Reference iOS client for the Mirabilis Blue BLE tutorial peripheral.

This version represents the final step of the iOS architecture evolution
used by the tutorial project: the SwiftUI and Combine presentation
architecture is preserved, while Bluetooth transport and BLE protocol
semantics have moved from the native CoreBluetooth layer into the Kotlin
Multiplatform `hardware` framework built on Kable.

The important architectural idea is:

> **KMP does not replace Combine. It replaces what feeds Combine.**

## Architecture

``` text
SwiftUI
  ↓
ViewModels
  ↓
BluetoothService (Swift adapter)
  ↓
KMP-NativeCoroutines
  ↓
MirabilisBlueService / MirabilisBlueDevice
  ↓
BleClient / KableClient
  ↓
Kable
  ↓
platform BLE
```

Events and durable state travel in the opposite direction:

``` text
Kable
  ↓
KMP Flow / StateFlow
  ↓
KMP-NativeCoroutinesCombine
  ↓
Combine publishers
  ↓
ViewModels
  ↓
@Published presentation state
  ↓
SwiftUI
```

One-shot KMP `suspend` operations are bridged through
KMP-NativeCoroutinesAsync and consumed from Swift with `async/await`.

## What changed from CoreBluetooth + Combine

The previous version used a native Swift BLE transport:

``` text
CoreBluetooth
  ↓
BluetoothManager
  ↓
PassthroughSubject<BluetoothEvent, Never>
  ↓
Combine
  ↓
ViewModels
  ↓
SwiftUI
```

The application no longer contains that transport. KMP/Kable is now the
sole BLE owner.

The following native BLE infrastructure was removed:

-   `BluetoothManager`
-   `BluetoothManaging`
-   the `BluetoothManager` CoreBluetooth delegate/GATT extensions
-   `BluetoothEvent`
-   `BluetoothState`
-   `BluetoothError`
-   native `CBCentralManager` / `CBPeripheral` ownership
-   the parallel native connection/disconnection path

The old KMP-specific adapter name was also simplified. There is no
longer a native manager and a KMP manager to distinguish, so the
Swift-facing adapter is simply `BluetoothService`.

## BluetoothService

`BluetoothService` is the single Swift-facing BLE boundary. One
app-scoped instance is created by `AppCoordinator` and shared by
Scanner, Device, File Transfer, and connection-management code.

Its responsibilities are deliberately narrow:

-   start and stop scanning through `MirabilisBlueService`;
-   retain the discovered `MirabilisBlueDevice`;
-   connect and disconnect the retained device;
-   expose KMP connection state as Combine;
-   expose GATT reads, writes, and notification streams;
-   bridge file-transfer commands and state;
-   map KMP values into Swift presentation-friendly values;
-   convert between `KotlinByteArray` and `Data`.

Stateless conversion/mapping functions used by Combine are marked
`nonisolated`, including the KMP file-transfer-state mapper.

## BLE ownership

KMP/Kable owns:

-   scanning;
-   connection lifecycle;
-   GATT discovery and access;
-   reads and writes;
-   write without response;
-   notifications;
-   encrypted/secure operations;
-   file-transfer transport and protocol state.

The iOS application does not create or retain CoreBluetooth
central/peripheral objects and does not run a second BLE transport
beside Kable.

## GATT operations

The SwiftUI screens are intentionally almost unchanged.
`DeviceViewModel` now calls `BluetoothService`, which delegates the
operation to `MirabilisBlueDevice`.

The KMP path covers:

-   Device Information reads;
-   Basic Write and Last Written Value;
-   Observable Write and Observable Value notifications;
-   Periodic Event Stream notifications;
-   Write Without Response and its corresponding read;
-   Secure Write and Secure State read/notifications;
-   Total Uploaded Bytes.

`MirabilisGATT` remains on the Swift side only as lightweight
UI/presentation metadata. It does not perform Bluetooth operations.

## File transfer

File-transfer semantics now live entirely in KMP.

Swift calls the KMP-backed operations exposed by `BluetoothService`:

-   upload;
-   download;
-   cancel;
-   observe transfer state.

The former Swift protocol engine was removed, including:

-   `FileTransferService`
-   `FileTransferProtocol`
-   `FileTransferChunk`
-   `FileTransferState`
-   `FileTransferError`

Chunk construction, sequence numbers, batching, ACK/NACK handling,
cancellation, encrypted GATT transport, progress state, and download
reconstruction are therefore implemented once, in KMP.

The iOS File Transfer feature retains only iOS-specific presentation and
file-system concerns:

-   `FileTransferView`
-   `FileTransferViewModel`
-   `SelectedFile`
-   `DownloadedFileDocument`
-   `FileSelectionError`

The maximum selectable file size comes from the KMP file-transfer
protocol through `BluetoothService`; it is not duplicated as a Swift
protocol constant.

## Connection and reconnection

`BluetoothConnectionController` no longer observes native
`BluetoothEvent` values. It observes the KMP device connection state
through the shared `BluetoothService`.

An unexpected disconnection drives the existing reconnect UI. Retry
reconnects through KMP/Kable. An intentional disconnect also goes
through `BluetoothService`, then returns the application to the Scanner
without presenting the reconnect alert.

This preserves the existing SwiftUI presentation behavior without
reintroducing a second BLE owner.

## Dependency ownership

`AppCoordinator` is the composition root. It creates the single
`BluetoothService` on the main actor and injects that same instance
where BLE access is needed.

``` text
AppCoordinator
  └── BluetoothService
       ├── ScannerViewModel
       ├── DeviceViewModel
       ├── FileTransferViewModel
       └── BluetoothConnectionController
```

Because `BluetoothService` retains the discovered KMP device, sharing
this instance ensures that every screen and controller operates on the
same BLE session.

## Documentation

-   `Documentation/ARCHITECTURE.md` --- application layering, dependency
    ownership, and the CoreBluetooth → KMP migration.
-   `Documentation/BLUETOOTH_ARCHITECTURE.md` --- KMP/Kable BLE
    ownership, NativeCoroutines bridging, and GATT flow.
-   `Documentation/FILE_TRANSFER.md` --- KMP-owned file-transfer
    protocol and Swift presentation responsibilities.
-   `Documentation/UI_NAVIGATION.md` --- Scanner, Device, File Transfer,
    disconnect, and reconnect navigation.
