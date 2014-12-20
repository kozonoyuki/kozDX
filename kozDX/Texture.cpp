/**
* @file   Texture.cpp
* @brief  �e�N�X�`���N���X
* @author kozonoyuki
* @date   12/20�ɏ����n��
*/

#include "stdafx.h"
#include "Texture.h"

koz::Texture::Texture()
{
}

koz::Texture::Texture(CComPtr<ID3D11Device> pDevice, std::string filename)
{
	ID3D11ShaderResourceView* pTexture = nullptr;
	HRESULT hr = DirectX::CreateDDSTextureFromFile(pDevice, StringToWcstring(filename), nullptr, &pTexture);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"�e�N�X�`�����쐬�ł��܂���ł����B", L"Error", MB_OK);
	}
	m_Texture.Attach(pTexture);
}

koz::Texture::~Texture()
{

}

void koz::Texture::Set(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot)
{
	pDeviceContext->PSSetShaderResources(Slot, 1, &m_Texture);
}