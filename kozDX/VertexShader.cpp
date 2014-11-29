/**
* @file   VertexShader.cpp
* @brief  ���_�V�F�[�_�����b�v
* @author kozonoyuki
* @date   11/29�ɏ����n��
*/

#include "VertexShader.h"

koz::VertexShader::VertexShader()
{
	// �f�t�H���g�ݒ�
	m_EntryName = "VS";
	m_ShaderVersion = "vs_4_0";
}

koz::VertexShader::~VertexShader()
{

}

HRESULT koz::VertexShader::CreateVertexShader(ID3D11Device* pDevice, std::string ShaderPath)
{
	HRESULT hr = S_OK;
	ID3D11VertexShader* pVertexShader = nullptr;
	ID3DBlob* pBlob = nullptr;
	hr = CompileShaderFromFile(StringToWcstring(ShaderPath), m_EntryName.c_str(), m_ShaderVersion.c_str(), &pBlob);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"���_�V�F�[�_�t�@�C�����R���p�C���ł��܂���ł����B", L"Error", MB_OK);
		return hr;
	}
	hr = pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"���_�V�F�[�_���쐬���邱�Ƃ��ł��܂���ł����B", L"Error", MB_OK);
		return hr;
	}
	m_VertexShader.Attach(pVertexShader);
	return hr;
}

void koz::VertexShader::SetEntryName(std::string EntryName)
{
	m_EntryName = EntryName;
}

void koz::VertexShader::SetShaderVersion(std::string ShaderVersion)
{
	m_ShaderVersion = ShaderVersion;
}

ID3D11VertexShader* koz::VertexShader::GetPtr()
{
	return m_VertexShader;
}