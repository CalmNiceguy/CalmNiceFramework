#pragma once
#include <memory>

namespace CNF {

    // This is the abstract base class
    class Renderer {
    public:
        virtual ~Renderer() = default;

        virtual bool Initialize(int windowWidth, int windowHeight, void* windowHandle) = 0;
        //virtual void ClearScreen(float r, float g, float b, float a) = 0;
        //virtual void DrawTriangle(const Triangle& triangle) = 0;
        //virtual void Present() = 0;
    };
    
    class DX12Renderer;
    // TODO: move this to its own file when we start implementing it
    class VulkanRenderer : public Renderer {
        // Vulkan implementation of Renderer
    };

    enum class RendererType {
        DX12,
        Vulkan,
        // Other types as needed...
    };


    // Factory function to create a Renderer
    std::unique_ptr<Renderer> CreateRenderer(RendererType type);
}
