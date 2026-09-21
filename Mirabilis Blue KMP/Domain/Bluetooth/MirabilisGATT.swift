//
//  MirabilisGATT.swift
//  Mirabilis Blue
//

import Foundation

nonisolated enum MirabilisGATT {
    private static let customPrefix =
        "7E57A000-0000-4B1A-9C00-00000000"

    enum Service: CaseIterable, Hashable, Sendable {
        case deviceInformation
        case tutorial
    }

    enum Characteristic: CaseIterable, Hashable, Sendable {
        case serialNumber
        case hardwareRevision
        case firmwareRevision
        case basicWrite
        case lastWrittenValue
        case observableWrite
        case observableValue
        case periodicEventStream
        case writeWithoutResponse
        case lastWriteWithoutResponseValue
        case secureWrite
        case secureState
        case fileTransferRX
        case fileTransferTX
        case totalUploadedBytes

        var uuid: String {
            switch self {
            case .serialNumber: return "2A25"
            case .hardwareRevision: return "2A27"
            case .firmwareRevision: return "2A26"
            case .basicWrite: return customUUID(suffix: "0002")
            case .lastWrittenValue: return customUUID(suffix: "0003")
            case .observableWrite: return customUUID(suffix: "0004")
            case .observableValue: return customUUID(suffix: "0005")
            case .periodicEventStream: return customUUID(suffix: "0006")
            case .writeWithoutResponse: return customUUID(suffix: "0007")
            case .lastWriteWithoutResponseValue: return customUUID(suffix: "0008")
            case .secureWrite: return customUUID(suffix: "0009")
            case .secureState: return customUUID(suffix: "000A")
            case .fileTransferRX: return customUUID(suffix: "000B")
            case .fileTransferTX: return customUUID(suffix: "000C")
            case .totalUploadedBytes: return customUUID(suffix: "000E")
            }
        }

        var service: Service {
            switch self {
            case .serialNumber, .hardwareRevision, .firmwareRevision:
                return .deviceInformation
            default:
                return .tutorial
            }
        }

        var supportsNotifications: Bool {
            switch self {
            case .observableValue, .periodicEventStream, .secureState, .fileTransferTX:
                return true
            default:
                return false
            }
        }

        private func customUUID(suffix: String) -> String {
            "\(MirabilisGATT.customPrefix)\(suffix)"
        }
    }
}
