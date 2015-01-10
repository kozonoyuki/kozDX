/**
* @file   DepthStencilTexture.h
* @brief  デプスステンシルテクスチャ（レンダリング結果）
* @author kozonoyuki
* @date   1/11に書き始め
*/

namespace koz
{
	/**
	* @brief デプスステンシルテクスチャクラス
	*/
	class DepthStencilTexture
	{
	private:
		/**
		* デプスステンシルテクスチャ
		*/
		CComPtr<ID3D11Texture2D> m_DepthStencilTexture;

		/**
		* デプスステンシルテクスチャ構造体
		*/
		D3D11_TEXTURE2D_DESC m_DepthStencilTextureDesc;

		/**
		* デプスステンシルビュー
		*/
		CComPtr<ID3D11DepthStencilView> m_DepthStencilView;

		/**
		* デプスステンシルビュー構造体
		*/
		D3D11_DEPTH_STENCIL_VIEW_DESC m_DepthStencilViewDesc;

		/**
		* シェーダリソースビュー
		*/
		CComPtr<ID3D11ShaderResourceView> m_ShaderResourceView;

		/**
		* シェーダリソースビュー構造体
		*/
		D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc;

	public:
		/**
		* コンストラクタ
		*/
		DepthStencilTexture();

		/**
		* デストラクタ
		*/
		~DepthStencilTexture();

		/**
		* デプスステンシルテクスチャを作成する
		* @param pDevice デバイス
		* @param Width テクスチャの幅
		* @param Height テクスチャの高さ
		* @param MipLevels ミップマップレベル数 0と指定すると完全なミップマップチェインが作られる
		* @param ArraySize テクスチャ配列の要素数
		* @param Format テクセルのフォーマット
		* @param SampleDescCount マルチ・サンプリングの設定
		* @param SampleDescQuality マルチ・サンプリングの品質
		* @param Usage テクスチャリソースの使用法
		* @param BindFlags テクスチャをパイプラインにバインドする方法
		* @param CPUAccessFlags CPUアクセスの種類CPUからアクセスしない場合は0
		* @param MiscFlags その他のフラグ
		* @return 結果
		*/
		HRESULT Create2DTexture(
			CComPtr<ID3D11Device> pDevice,
			UINT Width,
			UINT Height,
			UINT MipLevels,
			UINT ArraySize,
			DXGI_FORMAT Format,
			UINT SampleDescCount,
			UINT SampleDescQuality,
			D3D11_USAGE Usage,
			UINT BindFlags,
			UINT CPUAccessFlags,
			UINT MiscFlags
		);

		/**
		* デプスステンシルビューを作成する
		* @param pDevice デバイス
		* @param Format フォーマット 次のいづれか<br>
		*               DXGI_FORMAT_D16_UNORM<br>
		*               DXGI_FORMAT_D24_UNORM_S8_UINT<br>
		*               DXGI_FORMAT_D32_FLOAT<br>
		*               DXGI_FORMAT_D32_FLOAT_S8X24_UINT
		* @param ViewDimension リソースの種類
		* @param Flags テクスチャが読み取り専用でない0 専用D3D11_DSV_READ_ONLY_DEPTH or _STENCIL
		* @param MipSlice 2Dテクスチャの設定
		* @return 結果
		*/
		HRESULT Create2DDepthStencilView(
			CComPtr<ID3D11Device> pDevice,
			DXGI_FORMAT Format,
			D3D11_DSV_DIMENSION ViewDimension,
			UINT Flags,
			UINT MipSlice
		);

		/**
		* シェーダリソースビューを作成する
		* @param pDevice デバイス
		* @param Format フォーマット 
		* @param ViewDimension リソースの種類
		* @param MostDetailedMip 最も詳細なミップマップ・レベル
		* @param MipLevels 全てのミップマップ・レベル
		* @return 結果
		*/
		HRESULT Create2DShaderResourceView(
			CComPtr<ID3D11Device> pDevice,
			DXGI_FORMAT Format,
			D3D11_SRV_DIMENSION ViewDeimension,
			UINT MostDetailedMip,
			UINT MipLevels
		);

		/**
		* デプスステンシルビューをセットする
		* @param pDeviceContext デバコン
		* @param pRenderTargetView レンダーターゲットビュー
		*/
		void SetTarget(CComPtr<ID3D11DeviceContext> pDeviceContext, CComPtr<ID3D11RenderTargetView> pRenderTargetView);

		/**
		* テクスチャをシェーダに設定する
		* @param pDeviceContext デバコン
		* @param Slot スロット番号
		*/
		void SetPS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}