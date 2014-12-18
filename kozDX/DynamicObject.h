/**
* @file   DynamicObject.h
* @brief  動的オブジェクトを構成する抽象クラス
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include "Object.h"

namespace koz
{
	/**
	* @brief 動的オブジェクトクラス<br>
	*        動的に動作するオブジェクトに必要なものを定義
	*/
	class DynamicObject : protected Object
	{
	public:
		/**
		* 動的コンスタントバッファ。変化が激しいデータを格納。Posなど
		*/
		CComPtr<ID3D11Buffer> m_DynamicConstantBuffer;

		/**
		* アニメーションに用いるコンスタントバッファ
		*/
		CComPtr<ID3D11Buffer> m_AnimationConstantBuffer;

		/**
		* コンストラクタ
		*/
		DynamicObject()
		{

		}

		/**
		* デストラクタ
		*/
		~DynamicObject()
		{

		}

	};
}