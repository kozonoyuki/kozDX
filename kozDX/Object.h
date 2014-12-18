/**
* @file   Object.h
* @brief  オブジェクトを構成する抽象クラス
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
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
		CComPtr<ID3D11Buffer> m_WVPConstantBuffer;

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