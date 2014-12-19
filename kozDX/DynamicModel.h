/**
* @file   DynamicModel.h
* @brief  �A�j���[�V�������f��
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

#include "DynamicObject.h"
#include <string>

namespace koz
{
	/**
	* @brief ���I���f���N���X
	*/
	class DynamicModel : protected DynamicObject
	{
	private:


	public:
		/**
		* �R���X�g���N�^
		*/
		DynamicModel();

		/**
		* �R���X�g���N�^
		*/
		DynamicModel(CComPtr<ID3D11Device> pDevice, std::string filename);

		/**
		* �f�X�g���N�^
		*/
		~DynamicModel();

		/**
		* �o�b�t�@���Z�b�g���A�`��܂ōs��
		*/
		void Draw();
	};
}