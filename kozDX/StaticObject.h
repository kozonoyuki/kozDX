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
	* @brief 静的コンスタントバッファ構造体
	*/
	struct DescStatic
	{
	public:
		DirectX::XMMATRIX Position;
		DirectX::XMMATRIX Rotation;
		DirectX::XMMATRIX Scale;
	};

	/**
	* @brief 静的オブジェクトクラス<br>
	*        静的に動作するオブジェクトに必要なものを定義
	*/
	class StaticObject : protected Object
	{
	public:
		/**
		* 作成した後一度も変更しないコンスタントバッファ
		*/
		std::shared_ptr<ConstantBuffer<DescStatic>> m_StaticConstantBuffer;

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