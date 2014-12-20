/**
* @file   DepthStencilState.h
* @brief  深度ステンシル設定用クラス
* @author kozonoyuki
* @date   12/13に書き始め
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief 深度ステンシルステート設定用クラス
	*/
	class DepthStencilState
	{
	private:
		/**
		* 深度ステンシルステート
		*/
		CComPtr<ID3D11DepthStencilState> m_DepthStencilState;

		/**
		* 深度ステンシルステート構造体
		*/
		D3D11_DEPTH_STENCIL_DESC m_DepthStencilDesc;

	public:
		/**
		* コンストラクタ
		*/
		DepthStencilState();

		/**
		* デストラクタ
		*/
		~DepthStencilState();

		/**
		* 深度ステンシルステートを作成する
		* @param pDevice デバイス
		* @param DepthEnable TRUEで深度テスト有効　FALSEで無効
		* @param DepthWriteMask 深度値の書き込みマスク
		* @param DepthFunc 深度テストを行う関数
		* @param StencilEnable TRUEでステンシルテストが有効　FALSEで無効
		* @param StencilReadMask ステンシル値の読み込みマスク
		* @param StencilWriteMask ステンシル値の書き込みマスク
		* @param FrontStencilFailOp 前面 : ステンシルテストに失敗したときの動作
		* @param FrontStencilDepthFailOp 前面 : ステンシルテストに成功して、深度テストに失敗したときの動作
		* @param FrontStencilPassOp 前面 : ステンシルテスト、深度テスト両方に成功したときの動作
		* @param FrontStencilFunc 前面 : ステンシルテストを行う関数
		* @param BackStencilFailOp 後面 : ステンシルテストに失敗したときの動作
		* @param BackStencilDepthFailOp 後面 : ステンシルテストに成功して、深度テストに失敗したときの動作
		* @param BackStencilPassOp 後面 : ステンシルテスト、深度テスト両方に成功したときの動作
		* @param BackStencilFunc 後面 : ステンシルテストを行う関数
		* @return 結果
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			BOOL DepthEnable,
			D3D11_DEPTH_WRITE_MASK DepthWriteMask,
			D3D11_COMPARISON_FUNC DepthFunc,
			BOOL StencilEnable,
			UINT8 StencilReadMask,
			UINT8 StencilWriteMask,
			D3D11_STENCIL_OP FrontStencilFailOp,
			D3D11_STENCIL_OP FrontStencilDepthFailOp,
			D3D11_STENCIL_OP FrontStencilPassOp,
			D3D11_COMPARISON_FUNC FrontStencilFunc,
			D3D11_STENCIL_OP BackStencilFailOp,
			D3D11_STENCIL_OP BackStencilDepthFailOp,
			D3D11_STENCIL_OP BackStencilPassOp,
			D3D11_COMPARISON_FUNC BackStencilFunc
		);

		/**
		* 深度ステンシルステートをセットする
		* @param pDeviceContext デバコン
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT StencilRef);
	};
}