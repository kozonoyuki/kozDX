/**
* @file   Utility.h
* @brief  �w���p�[���C�u����
* @author kozonoyuki
* @date   11/29�ɏ����n��
*/

#pragma once

#include "stdafx.h"

/**
 * �V�F�[�_���R���p�C������
*/
static HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

	ID3DBlob* pErrorBlob = nullptr;
	hr = D3DCompileFromFile(szFileName, nullptr, nullptr, szEntryPoint, szShaderModel,
		dwShaderFlags, 0, ppBlobOut, &pErrorBlob);
	if (FAILED(hr))
	{
		if (pErrorBlob)
		{
			OutputDebugStringA(reinterpret_cast<const char*>(pErrorBlob->GetBufferPointer()));
			pErrorBlob->Release();
		}
		return hr;
	}
	if (pErrorBlob) pErrorBlob->Release();

	return S_OK;
}

/**
 * std::string������w_char*�^�ɕϊ�����
*/
static wchar_t* StringToWcstring(std::string str) {
	wchar_t * wcstr = new wchar_t[str.size() + 1];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstr, str.size() + 1, str.c_str(), _TRUNCATE);
	return wcstr;
}