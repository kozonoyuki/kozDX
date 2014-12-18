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
	class DynamicObject : public Object
	{
	private:

	public:
		/**
		* コンストラクタ
		*/
		DynamicObject();

		/**
		* デストラクタ
		*/
		~DynamicObject();
	};
}