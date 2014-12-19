/**
* @file   Object.h
* @brief  �I�u�W�F�N�g���\�����钊�ۃN���X
* @author kozonoyuki
* @date   12/19�ɏ����n��
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
	* @brief �I�u�W�F�N�g���\�����钊�ۃN���X<br>
	*        �I�u�W�F�N�g�`��ɍŒ���K�v�ȃ����o�E���\�b�h���`����
	*/
	class Object
	{
	public:
		/**
		* ���_�o�b�t�@
		*/
		CComPtr<ID3D11Buffer> m_VertexBuffer;

		/**
		* �C���f�b�N�X�o�b�t�@
		*/
		CComPtr<ID3D11Buffer> m_IndexBuffer;

		/**
		* WorldViewProjection �R���X�^���g�o�b�t�@
		*/
		std::shared_ptr<ConstantBuffer<DescWVP>> m_WVPConstantBuffer;

		/**
		* �R���X�g���N�^
		*/
		Object() {

		}

		/**
		* �f�X�g���N�^
		*/
		~Object() {

		}

		/**
		* �o�b�t�@���Z�b�g���A�`��܂ōs��
		*/
		virtual void Draw() = 0;
	};
}