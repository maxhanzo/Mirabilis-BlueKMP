# Bluetooth Architecture

## Ownership

KMP/Kable owns scanning, connection state, GATT reads/writes, notifications, security and file-transfer transport. Swift does not create or retain CoreBluetooth central/peripheral objects.

## Swift adapter

`BluetoothService` is the Swift-facing boundary. It wraps `MirabilisBlueService`, captures the discovered `MirabilisBlueDevice`, and exposes operations appropriate to Swift:

- scan start/stop;
- connect/disconnect;
- connection-state publisher;
- device-information reads;
- basic, observable, write-without-response and secure operations;
- observable/periodic/secure notification publishers;
- total-uploaded-bytes read;
- file-transfer upload/download/cancel/state.

## Reactive bridge

```text
Kable
  ↓
KMP Flow / StateFlow
  ↓
KMP-NativeCoroutinesCombine
  ↓
AnyPublisher
  ↓
ViewModel
  ↓
@Published
  ↓
SwiftUI
```

One-shot commands use KMP suspend functions → KMP-NativeCoroutinesAsync → Swift `async/await`. This preserves Combine as the iOS reactive layer while replacing the source feeding it.

## Connection lifecycle

`ScannerViewModel` scans and connects through `BluetoothService`. Once connected, `AppCoordinator` gives the connected `BluetoothDevice` to `BluetoothConnectionController`, which observes the KMP connection state. Unexpected disconnection presents the reconnect UI; retry calls the same KMP device's `connect()`. Intentional disconnect calls KMP `disconnect()` and returns to the scanner without presenting the reconnect alert.
