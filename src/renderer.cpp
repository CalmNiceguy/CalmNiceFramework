#include "renderer.h"
#include "dx12_renderer.h"
#include <memory>

namespace CNF {

    std::unique_ptr<Renderer> CreateRenderer(RendererType type) {
        switch (type) {
            case RendererType::DX12:
                return std::unique_ptr<Renderer>(new DX12Renderer());
            // case RendererType::Vulkan:
            //     return std::unique_ptr<Renderer>(new VulkanRenderer());
            default:
                return nullptr;
        }
    }

}

