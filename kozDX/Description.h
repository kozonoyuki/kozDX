/**
* @file   Description.h
* @brief  �\���̒�`
* @author kozonoyuki
* @date   12/23�ɏ����n��
*/

#pragma once

#include "stdafx.h"

namespace koz
{
	/**
	* ���_�\����
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
	* @brief WVP�R���X�^���g�o�b�t�@�̗p�\����
	*/
	struct DescWVP
	{
	public:
		DirectX::XMMATRIX World;
		DirectX::XMMATRIX View;
		DirectX::XMMATRIX Projection;
	};

	/**
	* @brief ���I�R���X�^���g�o�b�t�@�\����
	*/
	struct DescDynamic
	{
	public:
		DirectX::XMMATRIX Position;
		DirectX::XMMATRIX Rotation;
		DirectX::XMMATRIX Scale;
	};

	/**
	* @brief �ÓI�R���X�^���g�o�b�t�@�\����
	*/
	struct DescStatic
	{
	public:
		DirectX::XMMATRIX Position;
		DirectX::XMMATRIX Rotation;
		DirectX::XMMATRIX Scale;
	};

	/**
	* �ő�{�[����
	*/
	const static int MAX_BONE_COUNT = 6;

	/**
	* @brief �A�j���[�V�����R���X�^���g�o�b�t�@�\����
	*/
	struct DescAnimation
	{
	public:
		DirectX::XMMATRIX MeshMatrix;
		DirectX::XMMATRIX BoneMatrixList[MAX_BONE_COUNT];
	};
}