/**
* @file   DynamicObject.h
* @brief  静的オブジェクトを構成する抽象クラス
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include "Object.h"

namespace koz
{
	/**
	* @brief 静的オブジェクトクラス<br>
	*        静的に動作するオブジェクトに必要なものを定義
	*/
	class StaticObject : public Object
	{
	private:

	public:
		/**
		* コンストラクタ
		*/
		StaticObject();

		/**
		* デストラクタ
		*/
		~StaticObject();
	};
}