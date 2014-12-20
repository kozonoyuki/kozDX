/**
* @file   VertexBuffer.cpp
* @brief  頂点バッファ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#include "stdafx.h"
#include "VertexBuffer.h"

template <typename T>
koz::VertexBuffer<T>::VertexBuffer()
{
}

template <typename T>
koz::VertexBuffer<T>::VertexBuffer(CComPtr<ID3D11Device> pDevice, T * pVertex, unsigned int Size)
{
	ID3D11Buffer *pVertexBuffer = nullptr;
	ZeroMemory(&this->m_VertexBufferDesc, sizeof(this->m_VertexBufferDesc));
	this->m_VertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	this->m_VertexBufferDesc.ByteWidth = sizeof(T) * Size;
	this->m_VertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	this->m_VertexBufferDesc.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = pVertex;
	HRESULT hr = pDevice->CreateBuffer(&this->m_VertexBufferDesc, &InitData, &pVertexBuffer);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"頂点バッファを作成できませんでした。", L"Error", MB_OK);
	}
	m_VertexBuffer.Attach(pVertexBuffer);
}

template <typename T>
koz::VertexBuffer<T>::~VertexBuffer()
{

}

template <typename T>
void koz::VertexBuffer<T>::Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pVertexBuffer)
{
	pDeviceContext->UpdateSubresource(this->m_VertexBuffer, 0, nullptr, &pVertexBuffer, 0, 0);
}

template <typename T>
void koz::VertexBuffer<T>::Set(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	UINT stride = sizeof(T);
	UINT offset = 0;
	pDeviceContext->IASetVertexBuffers(0, 1, &this->m_VertexBuffer, &stride, &offset);
}