/**
* @file   Object.h
* @brief  オブジェクトを構成する抽象クラス
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include "ConstantBuffer.h"
#include <d3d11_1.h>
#include <atlbase.h>
#include <memory>
#include <DirectXMath.h>

namespace koz
{
	/**
	* @brief WVPコンスタントバッファの用構造体
	*/
	struct DescWVP
	{
	public:
		DirectX::XMMATRIX World;
		DirectX::XMMATRIX View;
		DirectX::XMMATRIX Projection;
	};

	/**
	* @brief オブジェクトを構成する抽象クラス<br>
	*        オブジェクト描画に最低限必要なメンバ・メソッドを定義する
	*/
	class Object
	{
	public:
		/**
		* 頂点バッファ
		*/
		CComPtr<ID3D11Buffer> m_VertexBuffer;

		/**
		* インデックスバッファ
		*/
		CComPtr<ID3D11Buffer> m_IndexBuffer;

		/**
		* WorldViewProjection コンスタントバッファ
		*/
		std::shared_ptr<ConstantBuffer<DescWVP>> m_WVPConstantBuffer;

		/**
		* コンストラクタ
		*/
		Object() {

		}

		/**
		* デストラクタ
		*/
		~Object() {

		}

		/**
		* バッファをセットし、描画まで行う
		*/
		virtual void Draw() = 0;
	};
}