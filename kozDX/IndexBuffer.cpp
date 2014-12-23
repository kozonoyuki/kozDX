/**
* @file   IndexBuffer.cpp
* @brief  �C���f�b�N�X�o�b�t�@
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#include "stdafx.h"
#include "IndexBuffer.h"

template <class T>
koz::IndexBuffer<T>::IndexBuffer()
{
}

template <class T>
koz::IndexBuffer<T>::IndexBuffer(CComPtr<ID3D11Device> pDevice, T * pIndex, unsigned int Size)
{
	ID3D11Buffer *pIndexBuffer = nullptr;
	ZeroMemory(&this->m_IndexBufferDesc, sizeof(this->m_IndexBufferDesc));
	this->m_IndexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	this->m_IndexBufferDesc.ByteWidth = sizeof(T) * Size;
	this->m_IndexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	this->m_IndexBufferDesc.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = pIndex;
	HRESULT hr = pDevice->CreateBuffer(&this->m_IndexBufferDesc, &InitData, &pIndexBuffer);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"�C���f�b�N�X�o�b�t�@���쐬�ł��܂���ł����B", L"Error", MB_OK);
	}
	this->m_IndexBuffer.Attach(pIndexBuffer);
}

template <class T>
koz::IndexBuffer<T>::~IndexBuffer()
{

}

template <class T>
void koz::IndexBuffer<T>::Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pIndexBuffer)
{
	pDeviceContext->UpdateSubresource(this->m_IndexBuffer, 0, nullptr, &pIndexBuffer, 0, 0);
}

template <class T>
void koz::IndexBuffer<T>::Set(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	pDeviceContext->IASetIndexBuffer(this->m_IndexBuffer, DXGI_FORMAT_R16_UINT, 0);
}

// �����N�p��`
template class koz::IndexBuffer < WORD > ;