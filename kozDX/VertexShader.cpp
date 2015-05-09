/**
* @file   VertexShader.cpp
* @brief  頂点シェーダをラップ
* @author kozonoyuki
* @date   11/29に書き始め
*/

#include "stdafx.h"
#include "VertexShader.h"
#include "Utility.h"

koz::VertexShader::VertexShader()
{
	// デフォルト設定
	m_EntryName = "VS";
	m_ShaderVersion = "vs_4_0";
}

koz::VertexShader::~VertexShader()
{

}

HRESULT koz::VertexShader::Create(CComPtr<ID3D11Device> pDevice, std::string ShaderPath, D3D11_INPUT_ELEMENT_DESC* pLayout, UINT LayoutSize)
{
	HRESULT hr = S_OK;
	ID3D11VertexShader* pVertexShader = nullptr;
	ID3DBlob* pBlob = nullptr;
	ID3D11InputLayout* pInputLayout = nullptr;
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
	hr = pDevice->CreateInputLayout(pLayout, LayoutSize, pBlob->GetBufferPointer(),
		pBlob->GetBufferSize(), &pInputLayout);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"インプットレイアウトを作成することができませんでした。", L"Error", MB_OK);
		return hr;
	}
	m_VertexShader.Attach(pVertexShader);
	pBlob->Release();
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

void koz::VertexShader::Set(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	pDeviceContext->VSSetShader(m_VertexShader, nullptr, 0);
}