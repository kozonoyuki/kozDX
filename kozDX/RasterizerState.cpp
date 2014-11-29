/**
* @file   RasterizerState.h
* @brief  ラスタライザ設定用クラス
* @author kozonoyuki
* @date   11/29に書き始め
*/

#include "stdafx.h"
#include "RasterizerState.h"

koz::RasterizerState::RasterizerState()
{
	ZeroMemory(&m_RasterizerDesc, sizeof(m_RasterizerDesc));
}

koz::RasterizerState::~RasterizerState()
{

}

HRESULT koz::RasterizerState::Create(
	CComPtr<ID3D11Device> pDevice,
	D3D11_FILL_MODE FillMode,
	D3D11_CULL_MODE CullMode,
	BOOL FrontCounterClockwise,
	INT DepthBias,
	FLOAT DepthBiasClamp,
	FLOAT SlopeScaledDepthBias,
	BOOL DepthClipEnable,
	BOOL ScissorEnable,
	BOOL MultisampleEnable,
	BOOL AnitialiasedLineEnable
	)
{
	HRESULT hr = S_OK;
	ID3D11RasterizerState *pRasterizerState = nullptr;
	m_RasterizerDesc.FillMode = FillMode;
	m_RasterizerDesc.CullMode = CullMode;
	m_RasterizerDesc.FrontCounterClockwise = FrontCounterClockwise;
	m_RasterizerDesc.DepthBias = DepthBias;
	m_RasterizerDesc.DepthBiasClamp = DepthBiasClamp;
	m_RasterizerDesc.SlopeScaledDepthBias = SlopeScaledDepthBias;
	m_RasterizerDesc.DepthClipEnable = DepthClipEnable;
	m_RasterizerDesc.ScissorEnable = ScissorEnable;
	m_RasterizerDesc.MultisampleEnable = MultisampleEnable;
	m_RasterizerDesc.AntialiasedLineEnable = AnitialiasedLineEnable;
	hr = pDevice->CreateRasterizerState(&m_RasterizerDesc, &pRasterizerState);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"ラスタライザステートを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	m_RasterizerState.Attach(pRasterizerState);
	return hr;
}

void koz::RasterizerState::Set(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	pDeviceContext->RSSetState(m_RasterizerState);
}