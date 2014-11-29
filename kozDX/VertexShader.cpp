/**
* @file   VertexShader.cpp
* @brief  頂点シェーダをラップ
* @author kozonoyuki
* @date   11/29に書き始め
*/

#include "VertexShader.h"

koz::VertexShader::VertexShader()
{
	// デフォルト設定
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
		MessageBox(nullptr, L"頂点シェーダファイルをコンパイルできませんでした。", L"Error", MB_OK);
		return hr;
	}
	hr = pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"頂点シェーダを作成することができませんでした。", L"Error", MB_OK);
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