/**
* @file   SamplerState.h
* @brief  �T���v���[�X�e�[�g
* @author kozonoyuki
* @date   12/20�ɏ����n��
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief �T���v���[�X�e�[�g�ݒ�p�N���X
	*/
	class SamplerState
	{
	private:
		/**
		* �T���v���[�X�e�[�g
		*/
		CComPtr<ID3D11SamplerState> m_SamplerState;

		/**
		* �T���v���[�X�e�[�g�\����
		*/
		D3D11_SAMPLER_DESC m_SamplerDesc;

	public:
		/**
		* �R���X�g���N�^
		*/
		SamplerState();

		/**
		* �f�X�g���N�^
		*/
		~SamplerState();

		/**
		* �T���v���[�X�e�[�g���쐬����
		* @param pDevice �f�o�C�X
		* @param Filter �e�N�X�`���T���v�����O�Ŏg���t�B���^
		* @param AddressU U���W�A�h���b�V���O�E���[�h
		* @param AddressV V���W�A�h���b�V���O�E���[�h
		* @param AddressW W���W�A�h���b�V���O�E���[�h
		* @param MipLODBias �~�b�v�}�b�v���x��=�v�Z���ꂽLOD+MipLODBias
		* @param MaxAnisotropy �ٕ����t�B���^�����O�̂Ƃ��̎��� 1~16
		* @param ComparisonFunc �T���v���Ƃ̔�r�֐�
		* @param BorderColorR ���E�FR
		* @param BorderColorG ���E�FG
		* @param BorderColorB ���E�FB
		* @param BorderCOlorA ���E�FA
		* @param MinLOD �~�b�v�}�b�v�͈͂̉����l 0���ő�ōł��ڍ�
		* @param MaxLOD �~�b�v�}�b�v�͈͂̏���l MaxLOD >= MinLOD ����Ȃ����D3D11_FLOAT32_MAX�̂悤�Ȓl��ݒ肷��
		* @return ����
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			D3D11_FILTER Filter,
			D3D11_TEXTURE_ADDRESS_MODE AddressU,
			D3D11_TEXTURE_ADDRESS_MODE AddressV,
			D3D11_TEXTURE_ADDRESS_MODE AddressW,
			FLOAT MipLODBias,
			UINT MaxAnisotropy,
			D3D11_COMPARISON_FUNC ComparisonFunc,
			FLOAT BorderColorR,
			FLOAT BorderColorG,
			FLOAT BorderColorB,
			FLOAT BorderColorA,
			FLOAT MinLOD,
			FLOAT MaxLOD
		);

		/**
		* �T���v���[�X�e�[�g��VS�ɃZ�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void SetVS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);

		/**
		* �T���v���[�X�e�[�g��GS�ɃZ�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void SetGS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);

		/**
		* �T���v���[�X�e�[�g��PS�ɃZ�b�g����
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void SetPS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}