/**
* @file   PixelShader.h
* @brief  �s�N�Z���V�F�[�_�����b�v
* @author kozonoyuki
* @date   11/29�ɏ����n��
*/

#pragma once

#include "Utility.h"
#include <d3d11_1.h>
#include <atlbase.h>
#include <string>

namespace koz
{
	/**
	 * @brief �s�N�Z���V�F�[�_�̃��b�p�N���X
	*/
	class PixelShader
	{
	private:
		/**
		 * �s�N�Z���V�F�[�_�̃X�}�|
		*/
		CComPtr<ID3D11PixelShader> m_PixelShader;

		/**
		 * �G���g���[��
		*/
		std::string m_EntryName;

		/**
		 * �V�F�[�_�o�[�W����
		*/
		std::string m_ShaderVersion;

	public:
		/**
		 * �R���X�g���N�^
		*/
		PixelShader();

		/**
		 * �f�X�g���N�^
		*/
		~PixelShader();

		/**
		 * �s�N�Z���V�F�[�_���쐬����
		 * @param pDevice �f�o�C�X
		 * @param ShaderPath �V�F�[�_�̃p�X
		 * @return ����
		*/
		HRESULT CreatePixelShader(ID3D11Device* pDevice, std::string ShaderPath);

		/**
		 * �G���g���|�C���g�ݒ�
		 * @param EntryName �V�F�[�_�̃��C���֐���
		*/
		void SetEntryName(std::string EntryName);

		/**
		 * �V�F�[�_�o�[�W�����ݒ�
		 * @param ShaderVersion �V�F�[�_�̃o�[�W����
		*/
		void SetShaderVersion(std::string ShaderVersion);

		/**
		 * �s�N�Z���V�F�[�_�̃|�C���^��ԋp����
		 * @return �s�N�Z���V�F�[�_�̃|�C���^
		*/
		ID3D11PixelShader* GetPtr();
	};
}