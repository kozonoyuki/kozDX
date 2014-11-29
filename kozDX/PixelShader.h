/**
* @file   PixelShader.h
* @brief  ピクセルシェーダをラップ
* @author kozonoyuki
* @date   11/29に書き始め
*/

#pragma once

#include "Utility.h"
#include <d3d11_1.h>
#include <atlbase.h>
#include <string>

namespace koz
{
	/**
	 * @brief ピクセルシェーダのラッパクラス
	*/
	class PixelShader
	{
	private:
		/**
		 * ピクセルシェーダのスマポ
		*/
		CComPtr<ID3D11PixelShader> m_PixelShader;

		/**
		 * エントリー名
		*/
		std::string m_EntryName;

		/**
		 * シェーダバージョン
		*/
		std::string m_ShaderVersion;

	public:
		/**
		 * コンストラクタ
		*/
		PixelShader();

		/**
		 * デストラクタ
		*/
		~PixelShader();

		/**
		 * ピクセルシェーダを作成する
		 * @param pDevice デバイス
		 * @param ShaderPath シェーダのパス
		 * @return 結果
		*/
		HRESULT CreatePixelShader(ID3D11Device* pDevice, std::string ShaderPath);

		/**
		 * エントリポイント設定
		 * @param EntryName シェーダのメイン関数名
		*/
		void SetEntryName(std::string EntryName);

		/**
		 * シェーダバージョン設定
		 * @param ShaderVersion シェーダのバージョン
		*/
		void SetShaderVersion(std::string ShaderVersion);

		/**
		 * ピクセルシェーダのポインタを返却する
		 * @return ピクセルシェーダのポインタ
		*/
		ID3D11PixelShader* GetPtr();
	};
}