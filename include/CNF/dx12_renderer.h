#pragma once
#include "renderer.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>

namespace CNF {

    class DX12Renderer : public Renderer {
        // DX12 implementation of Renderer
        bool Renderer::Initialize(int windowWidth, int windowHeight, void* windowHandle);
        
        private:
            ID3D12Device* device;
            ID3D12CommandQueue* commandQueue;
    };

}