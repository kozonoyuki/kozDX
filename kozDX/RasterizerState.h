/**
 * @file   RasterizerState.h
 * @brief  ラスタライザ設定用クラス
 * @author kozonoyuki
 * @date   11/29に書き始め
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
	/**
	 * @brief ラスタライザステート設定用クラス
	*/
	class RasterizerState
	{
	private:
		/**
		 * ラスタライザステート
		*/
		CComPtr<ID3D11RasterizerState> m_RasterizerState;

		/**
		* ラスタライザステート構造体
		*/
		D3D11_RASTERIZER_DESC m_RasterizerDesc;

	public:
		/**
		* コンストラクタ
		*/
		RasterizerState();

		/**
		 * デストラクタ
		*/
		~RasterizerState();

		/**
		 * ラスタライザステートを作成する
		 * @param pDevice デバイス
		 * @param FillMode フィルモードを設定する<br>
		 *                 D3D11_FILL_WIREFRAME ワイヤフレームを描画<br>
		 *                 D3D11_FILL_SOLID     三角形を塗りつぶす
		 * @param CullMode 裏面処理を設定する<br>
		 *                 D3D11_CULL_NONE   全ての三角形を描画<br>
		 *                 D3D11_CULL_FRONT  表を向いている三角形を描画しない<br>
		 *                 D3D11_CULL_BACK   裏を向いている三角形を描画しない
		 * @param FrontCounterClockwise 三角形の裏表を決める頂点の並び順<br>
		 *                              TRUE   反時計回りが表<br>
		 *                              FALSE  時計回りが表
		 * @param DepthBias 深度値に加えるバイアス
		 * @param DepthBiasClamp 深度値に加えるバイアスの最大値
		 * @param SlopeScaledDepthBias 与えるバイアスの勾配
		 * @param DepthClipEnable TRUEなら深度値によるクリッピングを有効にする
		 * @param ScissorEnable シザー矩形によるカリングを有効にする
		 * @param MultisampleEnable マルチ・サンプルによるアンチエイリアシングを有効にする
		 * @param AntialiasedLineEnable 線のアンチエイリアシングを有効にする
		 * @return 結果
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			D3D11_FILL_MODE FillMode,
			D3D11_CULL_MODE CullMode,
			BOOL FrontCounterClockwise,
			INT DepthBias,
			FLOAT DepthBiasClamp,
			FLOAT SlopeScaledDepthBias,
			BOOL DepthClipEnable,
			BOOL ScissorEnable,
			BOOL MultisampleEnable,
			BOOL AnitialiasedLineEnable
		);

		/**
		 * ラスタライザステートをセットする
		 * @param pDeviceContext デバコン
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}