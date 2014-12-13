/**
* @file   BlendState.h
* @brief  ブレンドステート設定用クラス
* @author kozonoyuki
* @date   12/13に書き始め
*/

#include "stdafx.h"
#include "BlendState.h"

koz::BlendState::BlendState()
{
	ZeroMemory(&m_BlendDesc, sizeof(m_BlendDesc));
	m_RenderTargetNumber = 0;
}

koz::BlendState::~BlendState()
{

}

HRESULT koz::BlendState::Create(
	CComPtr<ID3D11Device> pDevice,
	unsigned short RenderTargetNumber,
	BOOL AlphaToCoverageEnable,
	BOOL IndependentBlendEnable,
	BOOL BlendEnable,
	D3D11_BLEND SrcBlend,
	D3D11_BLEND DestBlend,
	D3D11_BLEND_OP BlendOp,
	D3D11_BLEND SrcBlendAlpha,
	D3D11_BLEND DestBlendAlpha,
	D3D11_BLEND_OP BlendOpAlpha,
	UINT8 RenderTargetWriteMask
	)
{
	HRESULT hr = S_OK;
	ID3D11BlendState *pBlendState = nullptr;
	m_RenderTargetNumber = RenderTargetNumber;
	m_BlendDesc.AlphaToCoverageEnable = AlphaToCoverageEnable;
	m_BlendDesc.IndependentBlendEnable = IndependentBlendEnable;
	m_BlendDesc.RenderTarget[RenderTargetNumber].BlendEnable = BlendEnable;
	m_BlendDesc.RenderTarget[RenderTargetNumber].SrcBlend = SrcBlend;
	m_BlendDesc.RenderTarget[RenderTargetNumber].DestBlend = DestBlend;
	m_BlendDesc.RenderTarget[RenderTargetNumber].BlendOp = BlendOp;
	m_BlendDesc.RenderTarget[RenderTargetNumber].SrcBlendAlpha = SrcBlendAlpha;
	m_BlendDesc.RenderTarget[RenderTargetNumber].DestBlendAlpha = DestBlendAlpha;
	m_BlendDesc.RenderTarget[RenderTargetNumber].BlendOpAlpha = BlendOpAlpha;
	m_BlendDesc.RenderTarget[RenderTargetNumber].RenderTargetWriteMask = RenderTargetWriteMask;
	hr = pDevice->CreateBlendState(&m_BlendDesc, &pBlendState);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"ブレンドステートを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	m_BlendState.Attach(pBlendState);
	return hr;
}

void koz::BlendState::Set(CComPtr<ID3D11DeviceContext> pDeviceContext, FLOAT factorR, FLOAT factorG, FLOAT factorB, FLOAT factorA, UINT SampleMask)
{
	FLOAT BlendFactor[4] = { factorR, factorG, factorB, factorA };
	pDeviceContext->OMSetBlendState(m_BlendState, BlendFactor, SampleMask);
}