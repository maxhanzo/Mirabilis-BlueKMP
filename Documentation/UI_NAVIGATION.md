# UI Navigation

## Routes

`AppCoordinator` owns the navigation path and one shared `BluetoothService`. Routes are Scanner → Device → File Transfer.

## Scanner → Device

`ScannerViewModel` starts KMP scanning through `BluetoothService`. Discovery stops the scan, subscribes to the discovered KMP device's connection state and calls `connect()`. On `.connected`, the coordinator opens `DeviceView` and starts connection tracking.

## Device → File Transfer

Both `DeviceViewModel` and `FileTransferViewModel` receive the same `BluetoothService` instance, so all operations target the same retained `MirabilisBlueDevice`.

## Disconnect / reconnect

`BluetoothConnectionController` observes KMP connection state. An unexpected `.disconnected` state presents the reconnect alert. Retry invokes `BluetoothService.connect()`. An intentional disconnect invokes `BluetoothService.disconnect()` and returns to Scanner without showing the reconnect alert.

The reconnect overlay and alert remain SwiftUI presentation concerns; no native CoreBluetooth transport is involved.
