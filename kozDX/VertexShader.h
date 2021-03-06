/**
 * @file   VertexShader.h
 * @brief  頂点シェーダをラップ
 * @author kozonoyuki
 * @date   11/29に書き始め
*/

#pragma once

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
		HRESULT Create(CComPtr<ID3D11Device> pDevice, std::string ShaderPath, D3D11_INPUT_ELEMENT_DESC* pLayout, UINT LayoutSize);

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
		 * 頂点シェーダをセットする
		 * @param pDeviceContext デバコン
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);


	};
}