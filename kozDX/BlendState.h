/**
* @file   BlendState.h
* @brief  �u�����h�X�e�[�g�ݒ�p�N���X
* @author kozonoyuki
* @date   12/13�ɏ����n��
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
	/**
	* @brief �u�����h�X�e�[�g�ݒ�p�N���X
	*/
	class BlendState
	{
	private:
		/**
		* �u�����h�X�e�[�g
		*/
		CComPtr<ID3D11BlendState> m_BlendState;

		/**
		* �u�����h�X�e�[�g�\����
		*/
		D3D11_BLEND_DESC m_BlendDesc;

		/**
		* �����_�[�^�[�Q�b�g�ԍ�
		*/
		unsigned char m_RenderTargetNumber;

	public:
		/**
		* �R���X�g���N�^
		*/
		BlendState();

		/**
		* �f�X�g���N�^
		*/
		~BlendState();

		/**
		* �u�����h�X�e�[�g���쐬����
		* @param pDevice �f�o�C�X
		* @param RenderTargetNumber �ǂ̃^�[�Q�b�g�̃u�����h���s���� 0~7
		* @param AlphaToCoverageEnable TRUE�̏ꍇ�A�}���`�T���v�����O�ɂ����āA�`��^�[�Q�b�g�Ƀs�N�Z���l��ݒ肷��Ƃ����l���g��
		* @param IndependentBlendEnable FALSE�̏ꍇ�ARenderTarget[0]�̐ݒ�݂̂��g���A1~7�̐ݒ肪���������
		* @param BlendEnable TRUE�̏ꍇ�A�u�����f�B���O��L���ɂ���
		* @param SrcBlend �\�[�X��RGB�l��I��
		* @param DestBlend �f�B�X�e�B�l�[�V������RGB�l��I��
		* @param BlendOp RGB�l�̃u�����h�ݒ�
		* @param SrcBlendAlpha �\�[�X�̃��l��I������
		* @param DestBlendAlpha �f�B�X�e�B�l�[�V�����̃��l��I��
		* @param BlendOpAlpha ���̃u�����h�ݒ�
		* @param RenderTargetWriteMask RGBA�l�̂����A�������ޒl���w�肷��
		* @return ����
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			unsigned short RenderTargetNumber,
			BOOL AlphaToCoverageEnable,
			BOOL IndependentBlendEnable,
			BOOL BlendEnable,
			D3D11_BLEND SrcBlend,
			D3D11_BLEND DestBlend,
			D3D11_BLEND_OP BlendOp,
			D3D11_BLEND SrcBlendAlpha,
			D3D11_BLEND DestBlendAlpha,
			D3D11_BLEND_OP BlendOpAlpha,
			UINT8 RenderTargetWriteMask
		);

		/**
		* �u�����h�X�e�[�g���Z�b�g����
		* @param pDeviceContext �f�o�R��
		* @param factorR �萔�lR
		* @param factorG �萔�lG
		* @param factorB �萔�lB
		* @param factorA �萔�lA
		* @param SampleMask �T���v���p�}�X�N
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext, FLOAT factorR, FLOAT factorG, FLOAT factorB, FLOAT factorA, UINT SampleMask);
	};
}