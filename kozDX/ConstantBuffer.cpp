/**
* @file   ConstantBuffer.cpp
* @brief  �R���X�^���g�o�b�t�@
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#include "stdafx.h"
#include "ConstantBuffer.h"

template <typename T>
koz::ConstantBuffer<T>::ConstantBuffer()
{
}

template <typename T>
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
		MessageBox(nullptr, L"�R���X�^���g�o�b�t�@���쐬�ł��܂���ł����B", L"Error", MB_OK);
	}
	m_ConstantBuffer.Attach(pConstantBuffer);
}

template <typename T>
koz::ConstantBuffer<T>::~ConstantBuffer()
{

}

template <typename T>
void koz::ConstantBuffer<T>::SetVertexShader(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer, UINT Slot)
{
	pDeviceContext->UpdateSubresource(m_ConstantBuffer, 0, nullptr, &pConstantBuffer, 0, 0);
	pDeviceContext->VSSetConstantBuffers(Slot, 1, &m_ConstantBuffer);
}

template <typename T>
void koz::ConstantBuffer<T>::SetPixelShader(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer, UINT Slot)
{
	pDeviceContext->UpdateSubresource(m_ConstantBuffer, 0, nullptr, &pConstantBuffer, 0, 0);
	pDeviceContext->PSSetConstantBuffers(Slot, 1, &m_ConstantBuffer);
}