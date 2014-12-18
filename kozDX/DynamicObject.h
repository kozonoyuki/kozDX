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
	class DynamicObject : public Object
	{
	private:

	public:
		/**
		* �R���X�g���N�^
		*/
		DynamicObject();

		/**
		* �f�X�g���N�^
		*/
		~DynamicObject();
	};
}