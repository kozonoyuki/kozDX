/**
* @file   VertexBuffer.h
* @brief  ���_�o�b�t�@
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief ���_�o�b�t�@�N���X
	*/
	template <typename T>
	class VertexBuffer
	{
	private:
		/**
		* ���_�o�b�t�@
		*/
		CComPtr<ID3D11Buffer> m_VertexBuffer;

		/**
		* ���_�o�b�t�@�\����
		*/
		D3D11_BUFFER_DESC m_VertexBufferDesc;

		/**
		* �f�t�H���g�R���X�g���N�^�i�g�p�֎~)
		*/
		VertexBuffer();

	public:
		/**
		* �R���X�g���N�^
		* @param pDevice �f�o�C�X
		*/
		VertexBuffer(CComPtr<ID3D11Device> pDevice, T * pVertex, unsigned int Size);

		/**
		* �f�X�g���N�^
		*/
		~VertexBuffer();

		/**
		* �f�[�^���X�V����
		* @param pDeviceContext �f�o�R��
		* @param pVertexBuffer �f�[�^
		*/
		void Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pVertexBuffer);

		/**
		* �f�[�^���Z�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}