/**
* @file   ConstantBuffer.h
* @brief  コンスタントバッファをラッパ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

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
		* データを更新する
		* @param pDeviceContext デバコン
		* @param pConstantBuffer データ
		*/
		void Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer);

		/**
		* 頂点シェーダにセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void SetVertexShader(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);

		/**
		* ピクセルシェーダにセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void SetPixelShader(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}