/**
* @file   Object.h
* @brief  �I�u�W�F�N�g���\�����钊�ۃN���X
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

#include "stdafx.h"
#include "ConstantBuffer.h"
#include "Description.h"

namespace koz
{
	/**
	* @brief �I�u�W�F�N�g���\�����钊�ۃN���X<br>
	*        �I�u�W�F�N�g�`��ɍŒ���K�v�ȃ����o�E���\�b�h���`����
	*/
	class Object
	{
	public:
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
		* @param pDeviceContext �f�o�R��
		*/
		virtual void Draw(CComPtr<ID3D11DeviceContext> pDeviceContext) = 0;
	};
}