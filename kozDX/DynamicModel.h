/**
* @file   DynamicModel.h
* @brief  アニメーションモデル
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include "DynamicObject.h"
#include <string>

namespace koz
{
	/**
	* @brief 動的モデルクラス
	*/
	class DynamicModel : protected DynamicObject
	{
	private:


	public:
		/**
		* コンストラクタ
		*/
		DynamicModel();

		/**
		* コンストラクタ
		*/
		DynamicModel(CComPtr<ID3D11Device> pDevice, std::string filename);

		/**
		* デストラクタ
		*/
		~DynamicModel();

		/**
		* バッファをセットし、描画まで行う
		*/
		void Draw();
	};
}