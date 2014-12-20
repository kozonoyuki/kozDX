/**
* @file   Texture.h
* @brief  テクスチャクラス
* @author kozonoyuki
* @date   12/20に書き始め
*/

#pragma once

#include "Utility.h"
#include "DDSTextureLoader.h"

namespace koz
{
	/**
	* @brief テクスチャクラス
	*/
	class Texture
	{
	private:
		/**
		* テクスチャ用シェーダリソースビュー
		*/
		CComPtr<ID3D11ShaderResourceView> m_Texture;

		/**
		* デフォルトコンストラクタ（使用禁止）
		*/
		Texture();

	public:
		/**
		* コンストラクタ（テクスチャをロードする)
		* @param pDevice デバイス
		* @param filename ファイルパス
		*/
		Texture(CComPtr<ID3D11Device> pDevice, std::string filename);

		/**
		* デストラクタ
		*/
		~Texture();

		/**
		* PSにテクスチャをセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}