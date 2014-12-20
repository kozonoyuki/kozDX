/**
* @file   SamplerState.cpp
* @brief  サンプラーステート
* @author kozonoyuki
* @date   12/20に書き始め
*/

#include "stdafx.h"
#include "SamplerState.h"

koz::SamplerState::SamplerState()
{
	ZeroMemory(&this->m_SamplerDesc, sizeof(this->m_SamplerDesc));
}

koz::SamplerState::~SamplerState()
{

}

HRESULT koz::SamplerState::Create(
	CComPtr<ID3D11Device> pDevice,
	D3D11_FILTER Filter,
	D3D11_TEXTURE_ADDRESS_MODE AddressU,
	D3D11_TEXTURE_ADDRESS_MODE AddressV,
	D3D11_TEXTURE_ADDRESS_MODE AddressW,
	FLOAT MipLODBias,
	UINT MaxAnisotropy,
	D3D11_COMPARISON_FUNC ComparisonFunc,
	FLOAT BorderColorR,
	FLOAT BorderColorG,
	FLOAT BorderColorB,
	FLOAT BorderColorA,
	FLOAT MinLOD,
	FLOAT MaxLOD
	)
{
	HRESULT hr = S_OK;
	ID3D11SamplerState* pSamplerState = nullptr;
	this->m_SamplerDesc.Filter = Filter;
	this->m_SamplerDesc.AddressU = AddressU;
	this->m_SamplerDesc.AddressV = AddressV;
	this->m_SamplerDesc.AddressW = AddressW;
	this->m_SamplerDesc.MipLODBias = MipLODBias;
	this->m_SamplerDesc.MaxAnisotropy = MaxAnisotropy;
	this->m_SamplerDesc.ComparisonFunc = ComparisonFunc;
	this->m_SamplerDesc.BorderColor[0] = BorderColorR;
	this->m_SamplerDesc.BorderColor[1] = BorderColorG;
	this->m_SamplerDesc.BorderColor[2] = BorderColorB;
	this->m_SamplerDesc.BorderColor[3] = BorderColorA;
	this->m_SamplerDesc.MinLOD = MinLOD;
	this->m_SamplerDesc.MaxLOD = MaxLOD;
	hr = pDevice->CreateSamplerState(&this->m_SamplerDesc, &pSamplerState);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"サンプラーステートを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	this->m_SamplerState.Attach(pSamplerState);
	return hr;
}

void koz::SamplerState::SetVS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->VSSetSamplers(Slot, 1, &this->m_SamplerState);
}

void koz::SamplerState::SetGS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->GSSetSamplers(Slot, 1, &this->m_SamplerState);
}

void koz::SamplerState::SetPS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->PSSetSamplers(Slot, 1, &this->m_SamplerState);
}