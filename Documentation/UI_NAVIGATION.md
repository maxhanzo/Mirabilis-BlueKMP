# UI Navigation

## Overview

Navigation remains a native SwiftUI concern.

The BLE migration changed the implementation beneath the screens, not
the user-facing route structure.

``` text
Scanner
    ↓
Device
    ↓
File Transfer
```

`AppCoordinator` owns the navigation path and one shared
`BluetoothService`.

## AppCoordinator

`AppCoordinator` is the composition root for the application.

It creates the single `BluetoothService` instance on the main actor and
shares it with:

-   `ScannerViewModel`;
-   `DeviceViewModel`;
-   `FileTransferViewModel`;
-   `BluetoothConnectionController`.

This is important because `BluetoothService` retains the discovered
`MirabilisBlueDevice`. Every screen therefore works with the same KMP
BLE session.

## Scanner → Device

`ScannerViewModel` starts scanning through `BluetoothService`.

``` text
ScannerView
    ↓
ScannerViewModel
    ↓
BluetoothService
    ↓
MirabilisBlueService
    ↓
Kable
```

Discovered KMP devices arrive through `Flow`/`StateFlow`,
KMP-NativeCoroutinesCombine, and Combine.

The service retains the discovered `MirabilisBlueDevice` and maps it to
the Swift `BluetoothDevice` used by the UI.

The scanner then observes the KMP device connection state and calls
`connect()` through `BluetoothService`.

On `.connected`, the coordinator navigates to `DeviceView` and starts
connection tracking.

## Device screen

`DeviceViewModel` receives the same `BluetoothService` instance used by
the scanner.

All GATT operations therefore target the already discovered/connected
KMP device.

The Device screen continues to present the tutorial operations:

-   Device Information;
-   Basic Operations;
-   Notifications;
-   Write Without Response;
-   Secure Operations;
-   File Transfer;
-   Statistics.

The UI does not discover or retain CoreBluetooth characteristics.
Operations are routed to purpose-specific KMP device APIs through
`BluetoothService`.

## Device → File Transfer

Selecting File Transfer creates `FileTransferViewModel` with the same
shared `BluetoothService`.

``` text
DeviceView
    ↓
FileTransferView
    ↓
FileTransferViewModel
    ↓
shared BluetoothService
    ↓
same MirabilisBlueDevice
```

No new scan, peripheral, manager, or BLE connection is created for the
File Transfer screen.

## Back navigation and intentional disconnect

The application preserves its explicit disconnect flow when leaving the
connected-device experience.

An intentional disconnect is routed through:

``` text
AppCoordinator
    ↓
BluetoothConnectionController / BluetoothService
    ↓
MirabilisBlueDevice.disconnect()
    ↓
KMP / Kable
```

The application then returns to Scanner.

Because the disconnect is intentional, it is not presented as a
connection-loss/reconnect condition.

## Unexpected disconnect

`BluetoothConnectionController` observes the KMP connection-state
publisher exposed by `BluetoothService`.

An unexpected `.disconnected` state drives the existing SwiftUI
reconnect presentation.

The controller does not own another BLE transport.

``` text
KMP connection state
    ↓
KMP-NativeCoroutinesCombine
    ↓
BluetoothService
    ↓
BluetoothConnectionController
    ↓
SwiftUI reconnect presentation
```

## Retry

Retry uses the same retained KMP device:

``` text
Retry
    ↓
BluetoothConnectionController
    ↓
BluetoothService.connect()
    ↓
MirabilisBlueDevice.connect()
    ↓
Kable
```

There is no native CoreBluetooth reconnect path.

## File Transfer during connection changes

`FileTransferViewModel` observes the same KMP-backed connection state as
the rest of the application.

Its upload, download, statistics, and cancellation capabilities are
derived from connection state and transfer state. File-transfer protocol
state itself remains owned by KMP.

If the device disconnects, the Swift UI updates
presentation/capabilities while the BLE transport remains under
KMP/Kable ownership.

## Presentation ownership

The following remain native iOS concerns:

-   navigation path;
-   alerts and overlays;
-   reconnect presentation;
-   file importer;
-   file exporter;
-   progress/status text;
-   SwiftUI view state.

Bluetooth transport, connection state source, GATT execution, security,
and file-transfer protocol mechanics are not duplicated in the
navigation layer.
