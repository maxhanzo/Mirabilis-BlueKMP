# Architecture

## Overview

The iOS app is a SwiftUI + Combine presentation layer over a Kotlin Multiplatform BLE implementation. BLE transport is not implemented twice: KMP/Kable is the sole owner.

```text
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
BleClient / KableClient / Kable
    ↓
platform BLE
```

## Swift layer

`AppCoordinator` owns one app-scoped `BluetoothService` and injects that same instance into Scanner, Device and File Transfer ViewModels. This is important because `BluetoothService` retains the currently discovered KMP device.

`BluetoothConnectionController` observes the KMP device connection state through `BluetoothService`, presents reconnect state, and retries/disconnects through the same service. It does not own a second transport.

`MirabilisGATT` is presentation metadata: characteristic identifiers, grouping and notification capability. It does not perform BLE operations.

## Interop

KMP suspend functions are exposed to Swift through KMP-NativeCoroutinesAsync and consumed with `async/await`. KMP `Flow`/`StateFlow` values are exposed through KMP-NativeCoroutinesCombine and consumed as Combine publishers. Stateless conversion helpers in `BluetoothService` are `nonisolated`.

## Removed native transport

The former Swift CoreBluetooth transport (`BluetoothManager`, `BluetoothManaging`, delegate extensions, `BluetoothEvent`, `BluetoothState`, and `BluetoothError`) has been removed. There is no parallel BLE owner in the iOS target.
