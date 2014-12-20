/**
* @file   SamplerState.h
* @brief  サンプラーステート
* @author kozonoyuki
* @date   12/20に書き始め
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief サンプラーステート設定用クラス
	*/
	class SamplerState
	{
	private:
		/**
		* サンプラーステート
		*/
		CComPtr<ID3D11SamplerState> m_SamplerState;

		/**
		* サンプラーステート構造体
		*/
		D3D11_SAMPLER_DESC m_SamplerDesc;

	public:
		/**
		* コンストラクタ
		*/
		SamplerState();

		/**
		* デストラクタ
		*/
		~SamplerState();

		/**
		* サンプラーステートを作成する
		* @param pDevice デバイス
		* @param Filter テクスチャサンプリングで使うフィルタ
		* @param AddressU U座標アドレッシング・モード
		* @param AddressV V座標アドレッシング・モード
		* @param AddressW W座標アドレッシング・モード
		* @param MipLODBias ミップマップレベル=計算されたLOD+MipLODBias
		* @param MaxAnisotropy 異方性フィルタリングのときの次数 1~16
		* @param ComparisonFunc サンプルとの比較関数
		* @param BorderColorR 境界色R
		* @param BorderColorG 境界色G
		* @param BorderColorB 境界色B
		* @param BorderCOlorA 境界色A
		* @param MinLOD ミップマップ範囲の下限値 0が最大で最も詳細
		* @param MaxLOD ミップマップ範囲の上限値 MaxLOD >= MinLOD 上限なければD3D11_FLOAT32_MAXのような値を設定する
		* @return 結果
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			D3D11_FILTER Filter,
			D3D11_TEXTURE_ADDRESS_MODE AddressU,
			D3D11_TEXTURE_ADDRESS_MODE AddressV,
			D3D11_TEXTURE_ADDRESS_MODE AddressW,
			FLOAT MipLODBias,
			UINT MaxAnisotropy,
			D3D11_COMPARISON_FUNC ComparisonFunc,
			FLOAT BorderColorR,
			FLOAT BorderColorG,
			FLOAT BorderColorB,
			FLOAT BorderColorA,
			FLOAT MinLOD,
			FLOAT MaxLOD
		);

		/**
		* サンプラーステートをVSにセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void SetVS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);

		/**
		* サンプラーステートをGSにセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void SetGS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);

		/**
		* サンプラーステートをPSにセットする
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void SetPS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}