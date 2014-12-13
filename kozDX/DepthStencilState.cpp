/**
* @file   DepthStencilState.h
* @brief  深度ステンシル設定用クラス
* @author kozonoyuki
* @date   12/13に書き始め
*/

#include "stdafx.h"
#include "DepthStencilState.h"

HRESULT koz::DepthStencilState::Create(
	CComPtr<ID3D11Device> pDevice,
	BOOL DepthEnable,
	D3D11_DEPTH_WRITE_MASK DepthWriteMask,
	D3D11_COMPARISON_FUNC DepthFunc,
	BOOL StencilEnable,
	UINT8 StencilReadMask,
	UINT8 StencilWriteMask,
	D3D11_STENCIL_OP FrontStencilFailOp,
	D3D11_STENCIL_OP FrontStencilDepthFailOp,
	D3D11_STENCIL_OP FrontStencilPassOp,
	D3D11_COMPARISON_FUNC FrontStencilFunc,
	D3D11_STENCIL_OP BackStencilFailOp,
	D3D11_STENCIL_OP BackStencilDepthFailOp,
	D3D11_STENCIL_OP BackStencilPassOp,
	D3D11_COMPARISON_FUNC BackStencilFunc
	)
{
	HRESULT hr = S_OK;
	ID3D11DepthStencilState *pDepthStencilState = nullptr;
	m_DepthStencilDesc.DepthEnable = DepthEnable;
	m_DepthStencilDesc.DepthWriteMask = DepthWriteMask;
	m_DepthStencilDesc.DepthFunc = DepthFunc;
	m_DepthStencilDesc.StencilEnable = StencilEnable;
	m_DepthStencilDesc.StencilReadMask = StencilReadMask;
	m_DepthStencilDesc.StencilWriteMask = StencilWriteMask;
	m_DepthStencilDesc.FrontFace.StencilFailOp = FrontStencilFailOp;
	m_DepthStencilDesc.FrontFace.StencilDepthFailOp = FrontStencilDepthFailOp;
	m_DepthStencilDesc.FrontFace.StencilPassOp = FrontStencilPassOp;
	m_DepthStencilDesc.FrontFace.StencilFunc = FrontStencilFunc;
	m_DepthStencilDesc.BackFace.StencilFailOp = BackStencilFailOp;
	m_DepthStencilDesc.BackFace.StencilDepthFailOp = BackStencilDepthFailOp;
	m_DepthStencilDesc.BackFace.StencilPassOp = BackStencilPassOp;
	m_DepthStencilDesc.BackFace.StencilFunc = BackStencilFunc;
	hr = pDevice->CreateDepthStencilState(&m_DepthStencilDesc, &pDepthStencilState);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"深度ステンシルステートを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	m_DepthStencilState.Attach(pDepthStencilState);
	return hr;
}

void koz::DepthStencilState::Set(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT StencilRef)
{
	pDeviceContext->OMSetDepthStencilState(m_DepthStencilState, StencilRef);
}