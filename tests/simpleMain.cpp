#include <iostream>
#include "renderer.h"

int main() {
    // Create a DX12 renderer
    std::unique_ptr<CNF::Renderer> renderer = CNF::CreateRenderer(CNF::RendererType::DX12);

    // Initialize the renderer
    bool success = renderer->Initialize(800, 600, nullptr);

    // Check the result
    if (success) {
        std::cout << "Renderer initialized successfully.\n";
    } else {
        std::cout << "Renderer failed to initialize.\n";
    }

    return 0;
}
