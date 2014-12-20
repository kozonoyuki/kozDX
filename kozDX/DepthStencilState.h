/**
* @file   DepthStencilState.h
* @brief  �[�x�X�e���V���ݒ�p�N���X
* @author kozonoyuki
* @date   12/13�ɏ����n��
*/

#pragma once

#include "Utility.h"

namespace koz
{
	/**
	* @brief �[�x�X�e���V���X�e�[�g�ݒ�p�N���X
	*/
	class DepthStencilState
	{
	private:
		/**
		* �[�x�X�e���V���X�e�[�g
		*/
		CComPtr<ID3D11DepthStencilState> m_DepthStencilState;

		/**
		* �[�x�X�e���V���X�e�[�g�\����
		*/
		D3D11_DEPTH_STENCIL_DESC m_DepthStencilDesc;

	public:
		/**
		* �R���X�g���N�^
		*/
		DepthStencilState();

		/**
		* �f�X�g���N�^
		*/
		~DepthStencilState();

		/**
		* �[�x�X�e���V���X�e�[�g���쐬����
		* @param pDevice �f�o�C�X
		* @param DepthEnable TRUE�Ő[�x�e�X�g�L���@FALSE�Ŗ���
		* @param DepthWriteMask �[�x�l�̏������݃}�X�N
		* @param DepthFunc �[�x�e�X�g���s���֐�
		* @param StencilEnable TRUE�ŃX�e���V���e�X�g���L���@FALSE�Ŗ���
		* @param StencilReadMask �X�e���V���l�̓ǂݍ��݃}�X�N
		* @param StencilWriteMask �X�e���V���l�̏������݃}�X�N
		* @param FrontStencilFailOp �O�� : �X�e���V���e�X�g�Ɏ��s�����Ƃ��̓���
		* @param FrontStencilDepthFailOp �O�� : �X�e���V���e�X�g�ɐ������āA�[�x�e�X�g�Ɏ��s�����Ƃ��̓���
		* @param FrontStencilPassOp �O�� : �X�e���V���e�X�g�A�[�x�e�X�g�����ɐ��������Ƃ��̓���
		* @param FrontStencilFunc �O�� : �X�e���V���e�X�g���s���֐�
		* @param BackStencilFailOp ��� : �X�e���V���e�X�g�Ɏ��s�����Ƃ��̓���
		* @param BackStencilDepthFailOp ��� : �X�e���V���e�X�g�ɐ������āA�[�x�e�X�g�Ɏ��s�����Ƃ��̓���
		* @param BackStencilPassOp ��� : �X�e���V���e�X�g�A�[�x�e�X�g�����ɐ��������Ƃ��̓���
		* @param BackStencilFunc ��� : �X�e���V���e�X�g���s���֐�
		* @return ����
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			BOOL DepthEnable,
			D3D11_DEPTH_WRITE_MASK DepthWriteMask,
			D3D11_COMPARISON_FUNC DepthFunc,
			BOOL StencilEnable,
			UINT8 StencilReadMask,
			UINT8 StencilWriteMask,
			D3D11_STENCIL_OP FrontStencilFailOp,
			D3D11_STENCIL_OP FrontStencilDepthFailOp,
			D3D11_STENCIL_OP FrontStencilPassOp,
			D3D11_COMPARISON_FUNC FrontStencilFunc,
			D3D11_STENCIL_OP BackStencilFailOp,
			D3D11_STENCIL_OP BackStencilDepthFailOp,
			D3D11_STENCIL_OP BackStencilPassOp,
			D3D11_COMPARISON_FUNC BackStencilFunc
		);

		/**
		* �[�x�X�e���V���X�e�[�g���Z�b�g����
		* @param pDeviceContext �f�o�R��
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT StencilRef);
	};
}