/**
* @file   ConstantBuffer.h
* @brief  �R���X�^���g�o�b�t�@�����b�p
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once

namespace koz
{
	/**
	* @brief �R���X�^���g�o�b�t�@�N���X
	*/
	template <typename T>
	class ConstantBuffer
	{
	private:
		/**
		* �R���X�^���g�o�b�t�@
		*/
		CComPtr<ID3D11Buffer> m_ConstantBuffer;

		/**
		* �R���X�^���g�o�b�t�@�\����
		*/
		D3D11_BUFFER_DESC m_ConstantBufferDesc;

		/**
		* �f�t�H���g�R���X�g���N�^�i�g�p�֎~)
		*/
		ConstantBuffer();

	public:
		/**
		* �R���X�g���N�^
		* @param pDevice �f�o�C�X
		*/
		ConstantBuffer(CComPtr<ID3D11Device> pDevice);

		/**
		* �f�X�g���N�^
		*/
		~ConstantBuffer();

		/**
		* �f�[�^���X�V����
		* @param pDeviceContext �f�o�R��
		* @param pConstantBuffer �f�[�^
		*/
		void Update(CComPtr<ID3D11DeviceContext> pDeviceContext, T * pConstantBuffer);

		/**
		* ���_�V�F�[�_�ɃZ�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void SetVertexShader(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);

		/**
		* �s�N�Z���V�F�[�_�ɃZ�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void SetPixelShader(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}