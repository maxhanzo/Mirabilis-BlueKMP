//
//  Mirabilis_BlueApp.swift
//  Mirabilis Blue
//
//  Created by Max Ueda on 31/08/26.
//

import SwiftUI

@main
struct Mirabilis_BlueApp: App {

    @State private var coordinator: AppCoordinator

    init() {
        _coordinator = State(
            initialValue: AppCoordinator()
        )
    }

    var body: some Scene {
        WindowGroup {
            AppCoordinatorView(
                coordinator: coordinator
            )
        }
    }
}
