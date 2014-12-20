/**
* @file   IndexBuffer.h
* @brief  �C���f�b�N�X�o�b�t�@
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief �C���f�b�N�X�o�b�t�@�N���X
	*/
	template <typename T>
	class IndexBuffer
	{
	private:
		/**
		* �C���f�b�N�X�o�b�t�@
		*/
		CComPtr<ID3D11Buffer> m_IndexBuffer;

		/**
		* �C���f�b�N�X�o�b�t�@�\����
		*/
		D3D11_BUFFER_DESC m_IndexBufferDesc;

		/**
		* �f�t�H���g�R���X�g���N�^�i�g�p�֎~)
		*/
		IndexBuffer();

	public:
		/**
		* �R���X�g���N�^
		* @param pDevice �f�o�C�X
		*/
		IndexBuffer(CComPtr<ID3D11Device> pDevice, T * pIndex, unsigned int Size);

		/**
		* �f�X�g���N�^
		*/
		~IndexBuffer();

		/**
		* �f�[�^���X�V����
		* @param pDeviceContext �f�o�R��
		* @param pIndexBuffer �f�[�^
		*/
		void Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pIndexBuffer);

		/**
		* �f�[�^���Z�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}