/**
* @file   DepthStencilTexture.cpp
* @brief  デプスステンシルテクスチャ（レンダリング結果）
* @author kozonoyuki
* @date   1/11に書き始め
*/

#include "stdafx.h"
#include "DepthStencilTexture.h"

HRESULT koz::DepthStencilTexture::Create2DTexture(
	CComPtr<ID3D11Device> pDevice,
	UINT Width,
	UINT Height,
	UINT MipLevels,
	UINT ArraySize,
	DXGI_FORMAT Format,
	UINT SampleDescCount,
	UINT SampleDescQuality,
	D3D11_USAGE Usage,
	UINT BindFlags,
	UINT CPUAccessFlags,
	UINT MiscFlags
	)
{
	HRESULT hr = S_OK;
	ID3D11Texture2D *pDepthStencilTexture;
	this->m_DepthStencilTextureDesc.Width = Width;
	this->m_DepthStencilTextureDesc.Height = Height;
	this->m_DepthStencilTextureDesc.MipLevels = MipLevels;
	this->m_DepthStencilTextureDesc.ArraySize = ArraySize;
	this->m_DepthStencilTextureDesc.Format = Format;
	this->m_DepthStencilTextureDesc.SampleDesc.Count = SampleDescCount;
	this->m_DepthStencilTextureDesc.SampleDesc.Quality = SampleDescQuality;
	this->m_DepthStencilTextureDesc.Usage = Usage;
	this->m_DepthStencilTextureDesc.BindFlags = BindFlags;
	this->m_DepthStencilTextureDesc.CPUAccessFlags = CPUAccessFlags;
	this->m_DepthStencilTextureDesc.MiscFlags = MiscFlags;
	hr = pDevice->CreateTexture2D(&this->m_DepthStencilTextureDesc, nullptr, &pDepthStencilTexture);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"深度ステンシル2Dテクスチャを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	this->m_DepthStencilTexture.Attach(pDepthStencilTexture);
	return hr;
}

HRESULT koz::DepthStencilTexture::Create2DDepthStencilView(
	CComPtr<ID3D11Device> pDevice,
	DXGI_FORMAT Format,
	D3D11_DSV_DIMENSION ViewDimension,
	UINT Flags,
	UINT MipSlice
	)
{
	HRESULT hr = S_OK;
	ID3D11DepthStencilView *pDepthStencilView;
	this->m_DepthStencilViewDesc.Format = Format;
	this->m_DepthStencilViewDesc.ViewDimension = ViewDimension;
	this->m_DepthStencilViewDesc.Flags = Flags;
	this->m_DepthStencilViewDesc.Texture2D.MipSlice = MipSlice;
	hr = pDevice->CreateDepthStencilView(this->m_DepthStencilTexture, &this->m_DepthStencilViewDesc, &pDepthStencilView);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"深度ステンシルビューを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	this->m_DepthStencilView.Attach(pDepthStencilView);
	return hr;
}

HRESULT koz::DepthStencilTexture::Create2DShaderResourceView(
	CComPtr<ID3D11Device> pDevice,
	DXGI_FORMAT Format,
	D3D11_SRV_DIMENSION ViewDeimension,
	UINT MostDetailedMip,
	UINT MipLevels
	)
{
	HRESULT hr = S_OK;
	ID3D11ShaderResourceView *pShaderResourceView;
	this->m_ShaderResourceViewDesc.Format = Format;
	this->m_ShaderResourceViewDesc.ViewDimension = ViewDeimension;
	this->m_ShaderResourceViewDesc.Texture2D.MostDetailedMip = MostDetailedMip;
	this->m_ShaderResourceViewDesc.Texture2D.MipLevels = MipLevels;
	hr = pDevice->CreateShaderResourceView(this->m_DepthStencilTexture, &this->m_ShaderResourceViewDesc, &pShaderResourceView);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"シェーダリソースビューを作成できませんでした。", L"Error", MB_OK);
		return hr;
	}
	this->m_ShaderResourceView.Attach(pShaderResourceView);
	return hr;
}

void koz::DepthStencilTexture::SetTarget(CComPtr<ID3D11DeviceContext> pDeviceContext, CComPtr<ID3D11RenderTargetView> pRenderTargetView)
{
	pDeviceContext->OMSetRenderTargets(1, &pRenderTargetView, this->m_DepthStencilView);
}

void koz::DepthStencilTexture::SetPS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->PSSetShaderResources(Slot, 1, &this->m_ShaderResourceView);
}