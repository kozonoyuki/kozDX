/**
* @file   Texture.h
* @brief  �e�N�X�`���N���X
* @author kozonoyuki
* @date   12/20�ɏ����n��
*/

#pragma once

#include "Utility.h"
#include "DDSTextureLoader.h"

namespace koz
{
	/**
	* @brief �e�N�X�`���N���X
	*/
	class Texture
	{
	private:
		/**
		* �e�N�X�`���p�V�F�[�_���\�[�X�r���[
		*/
		CComPtr<ID3D11ShaderResourceView> m_Texture;

		/**
		* �f�t�H���g�R���X�g���N�^�i�g�p�֎~�j
		*/
		Texture();

	public:
		/**
		* �R���X�g���N�^�i�e�N�X�`�������[�h����)
		* @param pDevice �f�o�C�X
		* @param filename �t�@�C���p�X
		*/
		Texture(CComPtr<ID3D11Device> pDevice, std::string filename);

		/**
		* �f�X�g���N�^
		*/
		~Texture();

		/**
		* PS�Ƀe�N�X�`�����Z�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}