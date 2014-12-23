#include <Windows.h>
#include <atlbase.h>
#include <d3d11_1.h>
#include <memory>
#include "../kozDX/DynamicModel.h"
//#include "../kozDX/FbxLoader.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "kozDX.lib")


static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("kozDX Text Program");

HINSTANCE hInst;
HWND hWnd;
UINT width = 500;
UINT height = 100;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("kozDX Test Program"),
			NULL);
		return 1;
	}

	hInst = hInstance;

	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		width, height,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("kozDX Test Program"),
			NULL);
		return 1;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	/**************************************************************************/
	CComPtr<ID3D11Device> pDevice;
	CComPtr<ID3D11DeviceContext> pDeviceContext;
	CComPtr<IDXGISwapChain> pSwapChain;
	ID3D11Device* m_pd3dDevice;
	ID3D11DeviceContext* m_pd3dDeviceContext;
	IDXGISwapChain* m_pSwapChain;

	// デバイスの作成
	D3D_DRIVER_TYPE			m_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL		m_featureLevel = D3D_FEATURE_LEVEL_11_0;
	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,	// ハードウェアドライバ
		D3D_DRIVER_TYPE_WARP,		// ソフトウェア・ラスタライザ
		D3D_DRIVER_TYPE_REFERENCE,	// リファレンスラスタライザ
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

	// スワップチェインの設定
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

	HRESULT hr = S_OK;
	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		m_driverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(nullptr, m_driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
			D3D11_SDK_VERSION, &sd, &m_pSwapChain, &m_pd3dDevice, &m_featureLevel, &m_pd3dDeviceContext);

		if (hr == E_INVALIDARG)
		{
			hr = D3D11CreateDeviceAndSwapChain(nullptr, m_driverType, nullptr, createDeviceFlags, &featureLevels[1], numFeatureLevels - 1,
				D3D11_SDK_VERSION, &sd, &m_pSwapChain, &m_pd3dDevice, &m_featureLevel, &m_pd3dDeviceContext);
		}

		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr))
		return 1;

	pDevice.Attach(m_pd3dDevice);
	pDeviceContext.Attach(m_pd3dDeviceContext);
	pSwapChain.Attach(m_pSwapChain);
	std::shared_ptr<koz::DynamicModel> dModel = std::make_shared<koz::DynamicModel>(pDevice, "C:\\Users\\Yuki\\Documents\\Visual Studio 2013\\Projects\\kozDX\\TestProject\\LegTestBone.fbx");
	//std::shared_ptr<koz::Texture> tex = std::make_shared<koz::Texture>(pDevice, "C:\\Users\\Yuki\\Documents\\Visual Studio 2013\\Projects\\kozDX\\TestProject\\ceil.dds");
	/**************************************************************************/
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}