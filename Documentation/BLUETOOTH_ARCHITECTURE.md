# Bluetooth Architecture

## Overview

Bluetooth transport and protocol access are owned by the Kotlin
Multiplatform `hardware` framework using Kable.

Swift does not create or retain `CBCentralManager`, `CBPeripheral`,
CoreBluetooth delegates, or a second connection path.

``` text
SwiftUI
    ↓
ViewModels
    ↓
BluetoothService
    ↓
MirabilisBlueService / MirabilisBlueDevice
    ↓
BleClient
    ↓
KableClient
    ↓
Kable
    ↓
platform BLE
```

## Migration from native CoreBluetooth

The previous iOS implementation isolated CoreBluetooth behind
`BluetoothManager`.

Its reactive path was:

``` text
CoreBluetooth delegate callbacks
    ↓
BluetoothManager
    ↓
PassthroughSubject<BluetoothEvent, Never>
    ↓
Combine
    ↓
ViewModels
```

That architecture was useful because the ViewModels already depended on
streams rather than directly on CoreBluetooth delegates. The KMP
migration therefore replaced the producer of those streams without
replacing Combine itself.

The new path is:

``` text
Kable
    ↓
BleClient / MirabilisBlueDevice
    ↓
Flow / StateFlow
    ↓
KMP-NativeCoroutinesCombine
    ↓
AnyPublisher
    ↓
ViewModels
```

For one-shot commands:

``` text
ViewModel
    ↓
BluetoothService
    ↓
KMP-NativeCoroutinesAsync
    ↓
Kotlin suspend function
    ↓
Kable
```

## BluetoothService

`BluetoothService` is the only Swift-facing BLE adapter.

It wraps `MirabilisBlueService` and retains the `MirabilisBlueDevice`
produced by discovery.

It exposes:

-   scan start/stop;
-   connect/disconnect;
-   connection-state publisher;
-   Device Information reads;
-   Basic Write and Last Written Value;
-   Observable Write and Observable Value notifications;
-   Periodic Event Stream notifications;
-   Write Without Response and corresponding read;
-   Secure Write;
-   Secure State read/notifications;
-   Total Uploaded Bytes;
-   file-transfer upload/download/cancel/state.

The adapter does not reproduce Kable or KMP BLE logic. It exists to make
generated Kotlin APIs idiomatic for the Swift application.

## Scanning

Scanning starts in `ScannerViewModel` through `BluetoothService`.

``` text
ScannerViewModel
    ↓
BluetoothService.startScan()
    ↓
MirabilisBlueService.startScan(...)
    ↓
Kable scanner
```

The KMP service exposes discovered devices as `StateFlow`.
KMP-NativeCoroutinesCombine turns that stream into a Combine publisher.

`BluetoothService` casts the exported device to `MirabilisBlueDevice`,
retains it, and maps it to the lightweight Swift `BluetoothDevice` used
by the UI.

The advertised peripheral name remains:

``` text
BLE-MIRABILIS-BLUE
```

The name filtering itself belongs to the KMP scan configuration.

## Connection

Once a device has been discovered, `ScannerViewModel` observes its
connection state and calls the KMP-backed `connect()` operation.

``` text
ScannerViewModel
    ↓
BluetoothService.connect()
    ↓
MirabilisBlueDevice.connect()
    ↓
BleClient / KableClient
    ↓
Kable
```

Connection state returns as a KMP `Flow<BleDeviceState>` and is bridged
into Combine.

On `.connected`, the coordinator navigates to `DeviceView` and starts
connection tracking.

## Disconnection and reconnect

The same `BluetoothService` is used for both intentional disconnect and
reconnect.

`BluetoothConnectionController` observes the KMP connection state. It
does not own a central manager or a second BLE client.

An unexpected `.disconnected` state can present the existing reconnect
UI. Retry calls `BluetoothService.connect()` on the retained KMP device.

An intentional disconnect calls `BluetoothService.disconnect()` and
returns to Scanner without treating the transition as an unexpected
connection loss.

## GATT operations

GATT operations are represented by purpose-specific methods on
`MirabilisBlueDevice`.

The Swift adapter does not look up CoreBluetooth characteristics.
Instead, each Swift-facing operation invokes the corresponding KMP API.

Examples:

``` text
BluetoothService.readSerialNumber()
    ↓
MirabilisBlueDevice.readSerialNumber()
```

``` text
BluetoothService.writeObservableValue(Data)
    ↓
Data → KotlinByteArray
    ↓
MirabilisBlueDevice.writeObservable(value:)
```

``` text
MirabilisBlueDevice.observePeriodicEvents()
    ↓
Flow<KotlinByteArray>
    ↓
Combine
    ↓
DeviceViewModel
```

This removes UUID lookup and characteristic ownership from the Swift
transport layer.

## Notifications

Notification-style characteristics are represented as KMP `Flow`
streams.

The iOS application consumes those streams through Combine for:

-   Observable Value;
-   Periodic Event Stream;
-   Secure State;
-   connection state;
-   file-transfer state.

This is the key continuity between the CoreBluetooth + Combine and KMP +
Combine versions: ViewModels still react to publishers, but the
publisher source is now a KMP stream.

## Secure operations

Pairing/encryption requirements are handled by the KMP/Kable BLE
implementation and the platform BLE stack.

The Swift application exposes Secure Write and Secure State operations
but does not own a separate CoreBluetooth pairing implementation.

## Byte interop

BLE payloads cross the Kotlin/Swift boundary as `KotlinByteArray`.

`BluetoothService` provides stateless conversion helpers:

``` text
KotlinByteArray → Data
Data → KotlinByteArray
```

These helpers are `nonisolated` because they do not read or mutate
actor-isolated state and may be used from Combine transformation
closures.

The same principle is used by the file-transfer-state mapper.

## MirabilisGATT

`MirabilisGATT` is not a transport layer.

It contains Swift-side metadata useful for presentation, such as
characteristic identity/grouping and notification capability. Actual
service/characteristic discovery and BLE access are KMP
responsibilities.

## Ownership rule

Only one layer may own a BLE session.

For this project that layer is KMP/Kable:

``` text
KMP/Kable = BLE owner
Swift     = adapter + reactive presentation
```

The old native CoreBluetooth transport was removed after the KMP path
had been physically validated for scanning, connection, ordinary GATT
operations, secure operations, notifications, statistics, and file
transfer.
