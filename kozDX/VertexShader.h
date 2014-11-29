/**
 * @file   VertexShader.h
 * @brief  ���_�V�F�[�_�����b�v
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
	 * @brief ���_�V�F�[�_�̃��b�p�N���X
	*/
	class VertexShader
	{
	private:
		/**
		 * ���_�V�F�[�_�̃X�}�|
		*/
		CComPtr<ID3D11VertexShader> m_VertexShader;

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
		VertexShader();

		/**
		 * �f�X�g���N�^
		*/
		~VertexShader();

		/**
		 * ���_�V�F�[�_���쐬����
		 * @param pDevice �f�o�C�X
		 * @param ShaderPath �V�F�[�_�̃p�X
		*/
		HRESULT CreateVertexShader(ID3D11Device* pDevice, std::string ShaderPath);

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
		 * ���_�V�F�[�_�̃|�C���^��ԋp����
		 * @return ���_�V�F�[�_�̃|�C���^
		*/
		ID3D11VertexShader* GetPtr();
	};
}