/**
* @file   Description.h
* @brief  構造体定義
* @author kozonoyuki
* @date   12/23に書き始め
*/

#pragma once

#include "stdafx.h"

namespace koz
{
	/**
	* 頂点構造体
	*/
	struct DynamicVertex
	{
		DirectX::XMFLOAT3 Pos;
		DirectX::XMFLOAT2 Tex;
		DirectX::XMFLOAT3 Norm;
		uint32_t boneIndex[4];
		DirectX::XMFLOAT4 boneWeight;
	};

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
}