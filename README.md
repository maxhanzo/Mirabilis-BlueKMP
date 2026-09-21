# Mirabilis Blue — KMP + Combine

Reference iOS client for the Mirabilis Blue BLE tutorial peripheral. The application keeps SwiftUI and Combine on iOS while BLE transport and protocol semantics are provided by the Kotlin Multiplatform `hardware` framework using Kable.

## Architecture

```text
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

Streams travel back to Swift as `Flow` / `StateFlow` → KMP-NativeCoroutines → Combine publishers → `@Published` presentation state. One-shot suspend operations are bridged to Swift `async/await`.

## BLE ownership

The KMP/Kable layer is the sole BLE transport owner. The iOS target contains no native `BluetoothManager`, `CBCentralManager`, `CBPeripheral`, delegate extensions, or parallel CoreBluetooth connection path.

`BluetoothService` is the single Swift-facing adapter. It owns the KMP `MirabilisBlueService`, retains the discovered `MirabilisBlueDevice`, maps KMP device/transfer state into Swift values, and performs byte-array conversion at the interop boundary.

## File transfer

File-transfer protocol semantics live entirely in KMP. Swift calls `upload(data:)`, `download()`, `cancelFileTransfer()`, observes `getFileTransferState()`, and presents progress/results. Chunking, sequencing, ACK/NACK handling, encrypted GATT transport, download reconstruction, and cancellation are not duplicated in the iOS application.

The iOS File Transfer feature therefore contains only presentation and file-system concerns: `FileTransferView`, `FileTransferViewModel`, `SelectedFile`, `DownloadedFileDocument`, and `FileSelectionError`.

## Documentation

- `Documentation/ARCHITECTURE.md` — application layering and dependency graph.
- `Documentation/BLUETOOTH_ARCHITECTURE.md` — KMP/Kable BLE boundary and Combine bridging.
- `Documentation/FILE_TRANSFER.md` — KMP-owned file-transfer integration.
- `Documentation/UI_NAVIGATION.md` — navigation, connection and reconnection flow.
