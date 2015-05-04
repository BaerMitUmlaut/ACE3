#include "render_window.hpp"

#include <thread>

using namespace  DirectX;

#ifdef _DEBUG

extern "C" { 
    LRESULT CALLBACK    _render_window_wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        return ace::debug::render_window::get()._wndproc(hWnd, message, wParam, lParam);
    }
}

namespace ace {
    namespace debug {
        render_window::render_window() { }

        render_window::~render_window() {
            cleanup_device();
        }

        void                render_window::init() {
            if (FAILED(init_window(GetModuleHandle(NULL), 5))) {
                throw - 1;
            }

            if (FAILED(init_device())) {
                cleanup_device();
                throw - 1;
            }

            // Main message loop
            //_render_loop_thread = std::make_shared<render_window_loop>(this);
        }
        HRESULT             render_window::init_window(HINSTANCE hInstance, int nCmdShow) {
            // Register class
            WNDCLASSEXW wcex;
            wcex.cbSize = sizeof(WNDCLASSEX);
            wcex.style = CS_HREDRAW | CS_VREDRAW;
            wcex.lpfnWndProc = _render_window_wndproc;
            wcex.cbClsExtra = 0;
            wcex.cbWndExtra = 0;
            wcex.hInstance = hInstance;
            wcex.hIcon = nullptr;
            wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
            wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            wcex.lpszMenuName = nullptr;
            wcex.lpszClassName = L"ACEDebugRender";
            //wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_ACE_DEBUG);
            wcex.hIconSm = nullptr;
            if (!RegisterClassExW(&wcex))
                return E_FAIL;

            // Create window
            hInst = hInstance;
            RECT rc = { 0, 0, 800, 600 };
            AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
            hWnd = CreateWindowW(L"ACEDebugRender", L"ACE3 VD Debug Render",
                WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
                nullptr);
            if (!hWnd)
                return E_FAIL;

            ShowWindow(hWnd, nCmdShow);

            return S_OK;
        }
        HRESULT             render_window::init_device() {
            HRESULT hr = S_OK;

            RECT rc;
            GetClientRect(hWnd, &rc);
            UINT width = rc.right - rc.left;
            UINT height = rc.bottom - rc.top;

            UINT createDeviceFlags = 0;
#ifdef _DEBUG
            createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

            D3D_DRIVER_TYPE driverTypes[] =
            {
                D3D_DRIVER_TYPE_HARDWARE,
                D3D_DRIVER_TYPE_WARP,
                D3D_DRIVER_TYPE_REFERENCE,
            };
            UINT numDriverTypes = ARRAYSIZE(driverTypes);

            D3D_FEATURE_LEVEL featureLevels[] =
            {
                D3D_FEATURE_LEVEL_11_1,
                D3D_FEATURE_LEVEL_11_0,
                D3D_FEATURE_LEVEL_10_1,
                D3D_FEATURE_LEVEL_10_0,
            };
            UINT numFeatureLevels = ARRAYSIZE(featureLevels);

            for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
            {
                driverType = driverTypes[driverTypeIndex];
                hr = D3D11CreateDevice(nullptr, driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
                    D3D11_SDK_VERSION, &pd3dDevice, &featureLevel, &pImmediateContext);

                if (hr == E_INVALIDARG)
                {
                    // DirectX 11.0 platforms will not recognize D3D_FEATURE_LEVEL_11_1 so we need to retry without it
                    hr = D3D11CreateDevice(nullptr, driverType, nullptr, createDeviceFlags, &featureLevels[1], numFeatureLevels - 1,
                        D3D11_SDK_VERSION, &pd3dDevice, &featureLevel, &pImmediateContext);
                }

                if (SUCCEEDED(hr))
                    break;
            }
            if (FAILED(hr))
                return hr;

            // Obtain DXGI factory from device (since we used nullptr for pAdapter above)
            IDXGIFactory1* dxgiFactory = nullptr;
            {
                IDXGIDevice* dxgiDevice = nullptr;
                hr = pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice));
                if (SUCCEEDED(hr))
                {
                    IDXGIAdapter* adapter = nullptr;
                    hr = dxgiDevice->GetAdapter(&adapter);
                    if (SUCCEEDED(hr))
                    {
                        hr = adapter->GetParent(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&dxgiFactory));
                        adapter->Release();
                    }
                    dxgiDevice->Release();
                }
            }
            if (FAILED(hr))
                return hr;

            // Create swap chain
            IDXGIFactory2* dxgiFactory2 = nullptr;
            hr = dxgiFactory->QueryInterface(__uuidof(IDXGIFactory2), reinterpret_cast<void**>(&dxgiFactory2));
            if (dxgiFactory2)
            {
                // DirectX 11.1 or later
                hr = pd3dDevice->QueryInterface(__uuidof(ID3D11Device1), reinterpret_cast<void**>(&pd3dDevice1));
                if (SUCCEEDED(hr))
                {
                    (void)pImmediateContext->QueryInterface(__uuidof(ID3D11DeviceContext1), reinterpret_cast<void**>(&pImmediateContext1));
                }

                DXGI_SWAP_CHAIN_DESC1 sd;
                ZeroMemory(&sd, sizeof(sd));
                sd.Width = width;
                sd.Height = height;
                sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
                sd.SampleDesc.Count = 1;
                sd.SampleDesc.Quality = 0;
                sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
                sd.BufferCount = 1;

                hr = dxgiFactory2->CreateSwapChainForHwnd(pd3dDevice, hWnd, &sd, nullptr, nullptr, &pSwapChain1);
                if (SUCCEEDED(hr))
                {
                    hr = pSwapChain1->QueryInterface(__uuidof(IDXGISwapChain), reinterpret_cast<void**>(&pSwapChain));
                }

                dxgiFactory2->Release();
            }
            else
            {
                // DirectX 11.0 systems
                DXGI_SWAP_CHAIN_DESC sd;
                ZeroMemory(&sd, sizeof(sd));
                sd.BufferCount = 1;
                sd.BufferDesc.Width = width;
                sd.BufferDesc.Height = height;
                sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
                sd.BufferDesc.RefreshRate.Numerator = 60;
                sd.BufferDesc.RefreshRate.Denominator = 1;
                sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
                sd.OutputWindow = hWnd;
                sd.SampleDesc.Count = 1;
                sd.SampleDesc.Quality = 0;
                sd.Windowed = TRUE;

                hr = dxgiFactory->CreateSwapChain(pd3dDevice, &sd, &pSwapChain);
            }

            // Note this tutorial doesn't handle full-screen swapchains so we block the ALT+ENTER shortcut
            dxgiFactory->MakeWindowAssociation(hWnd, DXGI_MWA_NO_ALT_ENTER);

            dxgiFactory->Release();

            if (FAILED(hr))
                return hr;

            // Create a render target view
            ID3D11Texture2D* pBackBuffer = nullptr;
            hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBackBuffer));
            if (FAILED(hr))
                return hr;

            hr = pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pRenderTargetView);
            pBackBuffer->Release();
            if (FAILED(hr))
                return hr;

            pImmediateContext->OMSetRenderTargets(1, &pRenderTargetView, nullptr);

            // Setup the viewport
            D3D11_VIEWPORT vp;
            vp.Width = (FLOAT)width;
            vp.Height = (FLOAT)height;
            vp.MinDepth = 0.0f;
            vp.MaxDepth = 1.0f;
            vp.TopLeftX = 0;
            vp.TopLeftY = 0;
            pImmediateContext->RSSetViewports(1, &vp);

            return S_OK;
        }
        LRESULT CALLBACK    render_window::_wndproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
            PAINTSTRUCT ps;
            HDC hdc;

            switch (message)
            {
            case WM_PAINT:
                hdc = BeginPaint(hWnd, &ps);
                EndPaint(hWnd, &ps);
                break;

            case WM_DESTROY:
                PostQuitMessage(0);
                break;

                // Note that this tutorial does not handle resizing (WM_SIZE) requests,
                // so we created the window without the resize border.

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }

            return 0;
        }
        void                render_window::render() {
            pImmediateContext->ClearRenderTargetView(pRenderTargetView, Colors::MidnightBlue);
            pSwapChain->Present(0, 0);
        }
        void                render_window::render_loop() { 
            MSG msg = { 0 };
            while (WM_QUIT != msg.message) {
                if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                } else {
                    render();
                }
            }
        }
        void                render_window::cleanup_device() {
            if (pImmediateContext) pImmediateContext->ClearState();
            if (pRenderTargetView) pRenderTargetView->Release();
            if (pSwapChain1) pSwapChain1->Release();
            if (pSwapChain) pSwapChain->Release();
            if (pImmediateContext1) pImmediateContext1->Release();
            if (pImmediateContext) pImmediateContext->Release();
            if (pd3dDevice1) pd3dDevice1->Release();
            if (pd3dDevice) pd3dDevice->Release();
        }

    };
};

#endif