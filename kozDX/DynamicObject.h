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
	* @brief 動的コンスタントバッファ構造体
	*/
	struct DescDynamic
	{
	public:
		DirectX::XMMATRIX Position;
		DirectX::XMMATRIX Rotation;
		DirectX::XMMATRIX Scale;
	};

	/**
	* 最大ボーン数
	*/
	const static int MAX_BONE_COUNT = 6;

	/**
	* @brief アニメーションコンスタントバッファ構造体
	*/
	struct DescAnimation
	{
	public:
		DirectX::XMMATRIX MeshMatrix;
		DirectX::XMMATRIX BoneMatrixList[MAX_BONE_COUNT];
	};

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
		std::shared_ptr<ConstantBuffer<DescDynamic>> m_DynamicConstantBuffer;

		/**
		* アニメーションに用いるコンスタントバッファ
		*/
		std::shared_ptr<ConstantBuffer<DescAnimation>> m_AnimationConstantBuffer;

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