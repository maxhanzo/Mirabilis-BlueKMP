# Architecture

## Overview

The Mirabilis Blue iOS application is a SwiftUI + Combine presentation
layer over a Kotlin Multiplatform BLE implementation.

The migration deliberately did **not** replace the existing SwiftUI or
Combine architecture. Instead, it replaced the native CoreBluetooth
transport underneath it.

Before the migration:

``` text
SwiftUI
    ↓
ViewModels
    ↓
BluetoothManaging
    ↓
BluetoothManager
    ↓
CoreBluetooth
```

Reactive BLE events travelled back through:

``` text
CoreBluetooth delegates
    ↓
BluetoothManager
    ↓
PassthroughSubject<BluetoothEvent, Never>
    ↓
Combine
    ↓
ViewModels
    ↓
@Published
    ↓
SwiftUI
```

After the migration:

``` text
SwiftUI Views
    ↓
ViewModels
    ↓
BluetoothService
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

Reactive state travels back through:

``` text
Kable
    ↓
KMP Flow / StateFlow
    ↓
KMP-NativeCoroutinesCombine
    ↓
Combine
    ↓
ViewModels
    ↓
@Published
    ↓
SwiftUI
```

KMP/Kable is the sole BLE owner. There is no parallel native
CoreBluetooth transport in the iOS application.

## Design goal

The goal of the migration was not to redesign a working SwiftUI
application around KMP. The goal was to move the reusable Bluetooth
implementation and protocol semantics into the shared Kotlin layer while
retaining the native iOS presentation architecture.

This creates a clear boundary:

``` text
Shared BLE implementation          Native iOS application
-------------------------          ----------------------
Kable                              SwiftUI
BleClient / KableClient            Combine
MirabilisBlueService        →      BluetoothService
MirabilisBlueDevice                ViewModels
Flow / StateFlow                   @Published state
suspend functions                  async/await
file-transfer engine               file picker/export UI
```

## AppCoordinator

`AppCoordinator` is the composition root for the iOS application.

It creates one app-scoped `BluetoothService` and shares that instance
with the components that require BLE access:

``` text
AppCoordinator
    │
    └── BluetoothService
          ├── ScannerViewModel
          ├── DeviceViewModel
          ├── FileTransferViewModel
          └── BluetoothConnectionController
```

The service is constructed inside the main-actor-isolated coordinator
initializer rather than as a default initializer argument. This keeps
actor isolation explicit and avoids constructing a main-actor-isolated
dependency from a potentially nonisolated default-argument context.

Sharing the service is important because it retains the currently
discovered `MirabilisBlueDevice`. Scanner, Device, File Transfer, and
reconnect operations therefore all refer to the same KMP device/session.

## BluetoothService

`BluetoothService` is the Swift/KMP adapter.

It owns the KMP `MirabilisBlueService` and retains the discovered
`MirabilisBlueDevice`. It does not implement BLE protocol mechanics
itself.

Its responsibilities include:

-   scan start/stop;
-   device discovery mapping;
-   connect/disconnect;
-   connection-state publishing;
-   Device Information reads;
-   basic read/write operations;
-   observable value write/notifications;
-   periodic notifications;
-   write-without-response operations;
-   secure read/write/notifications;
-   uploaded-byte statistics;
-   file-transfer commands and state;
-   Kotlin/Swift byte conversion.

The adapter converts KMP `KotlinByteArray` values to and from Foundation
`Data`.

Stateless transformation functions used from Combine pipelines are
`nonisolated`. This includes byte conversion and file-transfer-state
mapping. These functions do not access actor-isolated application state.

## ViewModels

ViewModels remain native Swift `ObservableObject` types.

They:

-   subscribe to Combine publishers exposed by `BluetoothService`;
-   call one-shot BLE operations with Swift `async/await`;
-   derive presentation state;
-   expose UI state through `@Published`;
-   contain no CoreBluetooth central/peripheral ownership.

This keeps the SwiftUI-facing architecture familiar while allowing the
BLE implementation to be shared.

## BluetoothConnectionController

`BluetoothConnectionController` remains a presentation-oriented
controller for connection loss and reconnect UI.

It no longer consumes native `BluetoothEvent` values and does not own a
Bluetooth transport. Instead, it observes connection state exposed by
the shared `BluetoothService`.

Retry and intentional disconnect also use the same service, so
connection ownership remains inside KMP/Kable.

## MirabilisGATT

The former native BLE UUID/catalog layer was reduced to `MirabilisGATT`.

It is lightweight presentation metadata used by the iOS UI for
characteristic identity/grouping/capability information. It does not use
`CBUUID`, perform discovery, issue reads/writes, or own notification
state.

The actual service/characteristic interaction belongs to the KMP
implementation.

## NativeCoroutines interop

Two bridge styles are used intentionally.

### Streams and durable state

KMP `Flow` and `StateFlow` values are exported through
KMP-NativeCoroutines and consumed as Combine publishers:

``` text
Flow / StateFlow
    ↓
KMP-NativeCoroutinesCombine
    ↓
AnyPublisher
    ↓
Combine pipeline
```

Examples include:

-   discovered devices;
-   connection state;
-   observable characteristic values;
-   periodic events;
-   secure-state notifications;
-   file-transfer state.

### One-shot operations

KMP `suspend` functions are bridged through KMP-NativeCoroutinesAsync
and consumed with Swift concurrency:

``` text
Kotlin suspend function
    ↓
KMP-NativeCoroutinesAsync
    ↓
asyncFunction(...)
    ↓
Swift async/await
```

Examples include connect/disconnect, reads, writes, upload, download,
and cancellation.

## Removed native CoreBluetooth layer

The previous native transport has been removed rather than left as a
fallback.

Removed responsibilities/types include:

-   `BluetoothManager`;
-   `BluetoothManaging`;
-   CoreBluetooth manager/delegate extensions;
-   `BluetoothEvent`;
-   `BluetoothState`;
-   `BluetoothError`;
-   native scan/connection ownership;
-   native characteristic discovery and GATT execution.

The iOS target therefore does not have two Bluetooth managers competing
for the same peripheral.

## File-transfer architecture

File transfer was migrated further than a simple transport replacement.
The complete protocol engine is now a KMP responsibility.

The native Swift protocol implementation (`FileTransferService`,
`FileTransferProtocol`, `FileTransferChunk`, `FileTransferState`, and
`FileTransferError`) was removed.

Swift retains only file selection/export and presentation logic. See
`FILE_TRANSFER.md` for the detailed boundary.

## Architectural result

The final application preserves the strengths of the Part 4 Combine
architecture while changing the source of its data:

``` text
CoreBluetooth → BluetoothManager → Combine
```

became:

``` text
Kable → KMP Flow/StateFlow → KMP-NativeCoroutines → Combine
```

Combine remains the native reactive layer used by the iOS ViewModels.
KMP provides the reusable BLE implementation beneath it.
