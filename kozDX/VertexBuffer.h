/**
* @file   VertexBuffer.h
* @brief  頂点バッファ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief 頂点バッファクラス
	*/
	template <typename T>
	class VertexBuffer
	{
	private:
		/**
		* 頂点バッファ
		*/
		CComPtr<ID3D11Buffer> m_VertexBuffer;

		/**
		* 頂点バッファ構造体
		*/
		D3D11_BUFFER_DESC m_VertexBufferDesc;

		/**
		* デフォルトコンストラクタ（使用禁止)
		*/
		VertexBuffer();

	public:
		/**
		* コンストラクタ
		* @param pDevice デバイス
		*/
		VertexBuffer(CComPtr<ID3D11Device> pDevice, T * pVertex, unsigned int Size);

		/**
		* デストラクタ
		*/
		~VertexBuffer();

		/**
		* データを更新する
		* @param pDeviceContext デバコン
		* @param pVertexBuffer データ
		*/
		void Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pVertexBuffer);

		/**
		* データをセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}