/**
 * @file   VertexShader.h
 * @brief  頂点シェーダをラップ
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
	 * @brief 頂点シェーダのラッパクラス
	*/
	class VertexShader
	{
	private:
		/**
		 * 頂点シェーダのスマポ
		*/
		CComPtr<ID3D11VertexShader> m_VertexShader;

		CComPtr<ID3D11InputLayout> m_InputLayout;

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
		VertexShader();

		/**
		 * デストラクタ
		*/
		~VertexShader();

		/**
		 * 頂点シェーダを作成する
		 * @param pDevice デバイス
		 * @param ShaderPath シェーダのパス
		 * @param pLayout インプットレイアウト
		 * @param LayoutSize レイアウトサイズ
		 * @return 結果
		*/
		HRESULT CreateVertexShader(CComPtr<ID3D11Device> pDevice, std::string ShaderPath, D3D11_INPUT_ELEMENT_DESC* pLayout, UINT LayoutSize);

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
		 * 頂点シェーダのポインタを返却する
		 * @return 頂点シェーダのポインタ
		*/
		CComPtr<ID3D11VertexShader> GetPtr();
	};
}