#include "renderer.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>

namespace CNF {

    bool DX12Renderer::Renderer::Initialize(int windowWidth, int windowHeight, void* windowHandle)
    {
        HRESULT hr;

        // -- Create the Device -- //

        IDXGIFactory4* dxgiFactory;
        hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));
        if (FAILED(hr))
        {
            // Error handling here
            return false;
        }

        IDXGIAdapter1* adapter;

        // Loop through adapters until we find a DX12 compatible one
        for (UINT i = 0; dxgiFactory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
        {
            DXGI_ADAPTER_DESC1 desc;
            adapter->GetDesc1(&desc);

            if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
            {
                // We don't want a software device
                continue;
            }

            // Check for DX12 support
            if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
            {
                break;
            }
        }

        hr = D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));
        if (FAILED(hr))
        {
            // Error handling here
            return false;
        }

        // -- Create the Command Queue -- //

        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
        queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
        queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
        hr = device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&commandQueue));
        if (FAILED(hr))
        {
            // Error handling here
            return false;
        }

        // TODO: Remaining initialization code...

        return true;
    }

    std::unique_ptr<Renderer> CreateRenderer(RendererType type) {
        switch (type) {
            case RendererType::DX12:
                return std::make_unique<DX12Renderer>();
            case RendererType::Vulkan:
                return std::make_unique<VulkanRenderer>();
            default:
                return nullptr;
        }
    }
}
