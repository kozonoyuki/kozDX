/**
* @file   BlendState.h
* @brief  ブレンドステート設定用クラス
* @author kozonoyuki
* @date   12/13に書き始め
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
	/**
	* @brief ブレンドステート設定用クラス
	*/
	class BlendState
	{
	private:
		/**
		* ブレンドステート
		*/
		CComPtr<ID3D11BlendState> m_BlendState;

		/**
		* ブレンドステート構造体
		*/
		D3D11_BLEND_DESC m_BlendDesc;

		/**
		* レンダーターゲット番号
		*/
		unsigned char m_RenderTargetNumber;

	public:
		/**
		* コンストラクタ
		*/
		BlendState();

		/**
		* デストラクタ
		*/
		~BlendState();

		/**
		* ブレンドステートを作成する
		* @param pDevice デバイス
		* @param RenderTargetNumber どのターゲットのブレンドを行うか 0~7
		* @param AlphaToCoverageEnable TRUEの場合、マルチサンプリングにおいて、描画ターゲットにピクセル値を設定するときα値を使う
		* @param IndependentBlendEnable FALSEの場合、RenderTarget[0]の設定のみが使われ、1~7の設定が無視される
		* @param BlendEnable TRUEの場合、ブレンディングを有効にする
		* @param SrcBlend ソースのRGB値を選択
		* @param DestBlend ディスティネーションのRGB値を選択
		* @param BlendOp RGB値のブレンド設定
		* @param SrcBlendAlpha ソースのα値を選択する
		* @param DestBlendAlpha ディスティネーションのα値を選択
		* @param BlendOpAlpha αのブレンド設定
		* @param RenderTargetWriteMask RGBA値のうち、書き込む値を指定する
		* @return 結果
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			unsigned short RenderTargetNumber,
			BOOL AlphaToCoverageEnable,
			BOOL IndependentBlendEnable,
			BOOL BlendEnable,
			D3D11_BLEND SrcBlend,
			D3D11_BLEND DestBlend,
			D3D11_BLEND_OP BlendOp,
			D3D11_BLEND SrcBlendAlpha,
			D3D11_BLEND DestBlendAlpha,
			D3D11_BLEND_OP BlendOpAlpha,
			UINT8 RenderTargetWriteMask
		);

		/**
		* ブレンドステートをセットする
		* @param pDeviceContext デバコン
		* @param factorR 定数値R
		* @param factorG 定数値G
		* @param factorB 定数値B
		* @param factorA 定数値A
		* @param SampleMask サンプル用マスク
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext, FLOAT factorR, FLOAT factorG, FLOAT factorB, FLOAT factorA, UINT SampleMask);
	};
}