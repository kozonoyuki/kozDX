/**
* @file   PixelShader.h
* @brief  �s�N�Z���V�F�[�_�����b�v
* @author kozonoyuki
* @date   11/29�ɏ����n��
*/

#include "stdafx.h"
#include "PixelShader.h"

koz::PixelShader::PixelShader()
{
	// �f�t�H���g�ݒ�
	m_EntryName = "PS";
	m_ShaderVersion = "ps_4_0";
}

koz::PixelShader::~PixelShader()
{

}

HRESULT koz::PixelShader::Create(CComPtr<ID3D11Device> pDevice, std::string ShaderPath)
{
	HRESULT hr = S_OK;
	ID3D11PixelShader* pPixelShader = nullptr;
	ID3DBlob* pBlob = nullptr;
	hr = CompileShaderFromFile(StringToWcstring(ShaderPath), m_EntryName.c_str(), m_ShaderVersion.c_str(), &pBlob);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"�s�N�Z���V�F�[�_���R���p�C���ł��܂���ł����B", L"Error", MB_OK);
		return hr;
	}
	hr = pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"�s�N�Z���V�F�[�_���쐬���邱�Ƃ��ł��܂���ł����B", L"Error", MB_OK);
		return hr;
	}
	m_PixelShader.Attach(pPixelShader);
	return hr;
}

void koz::PixelShader::SetEntryName(std::string EntryName)
{
	m_EntryName = EntryName;
}

void koz::PixelShader::SetShaderVersion(std::string ShaderVersion)
{
	m_ShaderVersion = ShaderVersion;
}

void koz::PixelShader::Set(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	pDeviceContext->PSSetShader(m_PixelShader, nullptr, 0);
}