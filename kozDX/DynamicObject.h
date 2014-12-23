/**
* @file   DynamicObject.h
* @brief  ���I�I�u�W�F�N�g���\�����钊�ۃN���X
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

#include "Object.h"

namespace koz
{
	/**
	* @brief ���I�I�u�W�F�N�g�N���X<br>
	*        ���I�ɓ��삷��I�u�W�F�N�g�ɕK�v�Ȃ��̂��`
	*/
	class DynamicObject : protected Object
	{
	public:
		/**
		* ���I�R���X�^���g�o�b�t�@�B�ω����������f�[�^���i�[�BPos�Ȃ�
		*/
		std::shared_ptr<ConstantBuffer<DescDynamic>> m_DynamicConstantBuffer;

		/**
		* �A�j���[�V�����ɗp����R���X�^���g�o�b�t�@
		*/
		std::shared_ptr<ConstantBuffer<DescAnimation>> m_AnimationConstantBuffer;

		/**
		* �R���X�g���N�^
		*/
		DynamicObject()
		{

		}

		/**
		* �f�X�g���N�^
		*/
		~DynamicObject()
		{

		}

		/**
		* �o�b�t�@���Z�b�g���A�`��܂ōs��
		* @param pDeviceContext �f�o�R��
		*/
		void Draw(CComPtr<ID3D11DeviceContext> pDeviceContext) = 0;
	};
}