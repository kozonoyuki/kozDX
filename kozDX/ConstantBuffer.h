/**
* @file   ConstantBuffer.h
* @brief  コンスタントバッファをラッパ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
	/**
	* @brief コンスタントバッファクラス
	*/
	template <typename T>
	class ConstantBuffer
	{
	private:
		/**
		* コンスタントバッファ
		*/
		CComPtr<ID3D11Buffer> m_ConstantBuffer;

		/**
		* コンスタントバッファ構造体
		*/
		D3D11_BUFFER_DESC m_ConstantBufferDesc;

		/**
		* デフォルトコンストラクタ（使用禁止)
		*/
		ConstantBuffer();

	public:
		/**
		* コンストラクタ
		* @param pDevice デバイス
		*/
		ConstantBuffer(CComPtr<ID3D11Device> pDevice);

		/**
		* デストラクタ
		*/
		~ConstantBuffer();

		/**
		* データを頂点シェーダにセットする
		* @param pDeviceContext デバコン
		* @param pConstantBuffer データ
		* @param Slot スロット番号
		*/
		void SetVertexShader(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer, UINT Slot);

		/**
		* データをピクセルシェーダにセットする
		* @param pDeviceContext デバコン
		* @param pConstantBuffer データ
		* @param Slot スロット番号
		*/
		void SetPixelShader(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer, UINT Slot);
	};
}