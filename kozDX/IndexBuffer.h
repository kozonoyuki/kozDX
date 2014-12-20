/**
* @file   IndexBuffer.h
* @brief  インデックスバッファ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief インデックスバッファクラス
	*/
	template <typename T>
	class IndexBuffer
	{
	private:
		/**
		* インデックスバッファ
		*/
		CComPtr<ID3D11Buffer> m_IndexBuffer;

		/**
		* インデックスバッファ構造体
		*/
		D3D11_BUFFER_DESC m_IndexBufferDesc;

		/**
		* デフォルトコンストラクタ（使用禁止)
		*/
		IndexBuffer();

	public:
		/**
		* コンストラクタ
		* @param pDevice デバイス
		*/
		IndexBuffer(CComPtr<ID3D11Device> pDevice, T * pIndex, unsigned int Size);

		/**
		* デストラクタ
		*/
		~IndexBuffer();

		/**
		* データを更新する
		* @param pDeviceContext デバコン
		* @param pIndexBuffer データ
		*/
		void Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pIndexBuffer);

		/**
		* データをセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}