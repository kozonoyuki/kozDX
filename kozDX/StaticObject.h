/**
* @file   DynamicObject.h
* @brief  �ÓI�I�u�W�F�N�g���\�����钊�ۃN���X
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

#include "Object.h"

namespace koz
{
	/**
	* @brief �ÓI�I�u�W�F�N�g�N���X<br>
	*        �ÓI�ɓ��삷��I�u�W�F�N�g�ɕK�v�Ȃ��̂��`
	*/
	class StaticObject : protected Object
	{
	public:
		/**
		* �쐬�������x���ύX���Ȃ��R���X�^���g�o�b�t�@
		*/
		CComPtr<ID3D11Buffer> m_StaticConstantBuffer;

		/**
		* �R���X�g���N�^
		*/
		StaticObject();

		/**
		* �f�X�g���N�^
		*/
		~StaticObject();

	};
}