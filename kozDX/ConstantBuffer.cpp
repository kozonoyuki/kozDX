/**
* @file   ConstantBuffer.cpp
* @brief  コンスタントバッファ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#include "stdafx.h"
#include "ConstantBuffer.h"
#include "Description.h"

template <class T>
koz::ConstantBuffer<T>::ConstantBuffer() { }

template <class T>
koz::ConstantBuffer<T>::ConstantBuffer(CComPtr<ID3D11Device> pDevice)
{
	ID3D11Buffer *pConstantBuffer = nullptr;
	ZeroMemory(&m_ConstantBufferDesc, sizeof(m_ConstantBufferDesc));
	m_ConstantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	m_ConstantBufferDesc.ByteWidth = sizeof(T);
	m_ConstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	m_ConstantBufferDesc.CPUAccessFlags = 0;
	HRESULT hr = pDevice->CreateBuffer(&m_ConstantBufferDesc, nullptr, &pConstantBuffer);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"コンスタントバッファを作成できませんでした。", L"Error", MB_OK);
	}
	m_ConstantBuffer.Attach(pConstantBuffer);
}

template <class T>
koz::ConstantBuffer<T>::~ConstantBuffer() { }

template <class T>
void koz::ConstantBuffer<T>::Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer)
{
	pDeviceContext->UpdateSubresource(m_ConstantBuffer, 0, nullptr, &pConstantBuffer, 0, 0);
}

template <class T>
void koz::ConstantBuffer<T>::SetVertexShader(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->VSSetConstantBuffers(Slot, 1, &m_ConstantBuffer);
}

template <class T>
void koz::ConstantBuffer<T>::SetPixelShader(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->PSSetConstantBuffers(Slot, 1, &m_ConstantBuffer);
}

// リンク用定義
template class koz::ConstantBuffer < koz::DescWVP > ;
template class koz::ConstantBuffer < koz::DescDynamic > ;
template class koz::ConstantBuffer < koz::DescAnimation > ;
template class koz::ConstantBuffer < koz::DescStatic > ;
