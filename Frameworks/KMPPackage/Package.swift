// swift-tools-version:5.9
import PackageDescription

// BEGIN KMMBRIDGE VARIABLES BLOCK (do not edit)
let remoteKotlinUrl = "https://maven.pkg.github.com/MirabilisBlue/mirabilisblue-hardware-kmp/com/mirabilisblue/hardware-kmmbridge/0.1.17/hardware-kmmbridge-0.1.17.zip"
let remoteKotlinChecksum = "66cb16356fd7632ff6d2c3fb8fe1998377868ee31fb8d5375135121b653ad08c"
let packageName = "hardware"
// END KMMBRIDGE BLOCK

let package = Package(
    name: "KMPPackage",
    platforms: [
        .iOS(.v17)
    ],
    products: [
        .library(
            name: "KMPLibrary",
            targets: ["KMPLibrary"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/rickclephas/KMP-NativeCoroutines.git", exact: "1.0.0-ALPHA-31-spm-no-deps")
    ],
    targets: [
        .target(
            name: "KMPLibrary",
            dependencies: [
                .byName(name: packageName),
                // Swift Concurrency implementation
                .product(name: "KMPNativeCoroutinesAsync", package: "KMP-NativeCoroutines"),
                // Combine implementation
                .product(name: "KMPNativeCoroutinesCombine", package: "KMP-NativeCoroutines"),
            ],
            path: "./Sources/KMPLibrary"
        ),
        .binaryTarget(
            name: packageName,
            path: "./Sources/KMMBinary/hardware.xcframework"
        )
        //.binaryTarget(
        //    name: packageName,
        //    url: remoteKotlinUrl,
        //    checksum: remoteKotlinChecksum
        //)
    ]
)
