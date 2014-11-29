/**
 * @file   RasterizerState.h
 * @brief  ���X�^���C�U�ݒ�p�N���X
 * @author kozonoyuki
 * @date   11/29�ɏ����n��
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
	/**
	 * @brief ���X�^���C�U�X�e�[�g�ݒ�p�N���X
	*/
	class RasterizerState
	{
	private:
		/**
		 * ���X�^���C�U�X�e�[�g
		*/
		CComPtr<ID3D11RasterizerState> m_RasterizerState;

		/**
		* ���X�^���C�U�X�e�[�g�\����
		*/
		D3D11_RASTERIZER_DESC m_RasterizerDesc;

	public:
		/**
		* �R���X�g���N�^
		*/
		RasterizerState();

		/**
		 * �f�X�g���N�^
		*/
		~RasterizerState();

		/**
		 * ���X�^���C�U�X�e�[�g���쐬����
		 * @param pDevice �f�o�C�X
		 * @param FillMode �t�B�����[�h��ݒ肷��<br>
		 *                 D3D11_FILL_WIREFRAME ���C���t���[����`��<br>
		 *                 D3D11_FILL_SOLID     �O�p�`��h��Ԃ�
		 * @param CullMode ���ʏ�����ݒ肷��<br>
		 *                 D3D11_CULL_NONE   �S�Ă̎O�p�`��`��<br>
		 *                 D3D11_CULL_FRONT  �\�������Ă���O�p�`��`�悵�Ȃ�<br>
		 *                 D3D11_CULL_BACK   ���������Ă���O�p�`��`�悵�Ȃ�
		 * @param FrontCounterClockwise �O�p�`�̗��\�����߂钸�_�̕��я�<br>
		 *                              TRUE   �����v��肪�\<br>
		 *                              FALSE  ���v��肪�\
		 * @param DepthBias �[�x�l�ɉ�����o�C�A�X
		 * @param DepthBiasClamp �[�x�l�ɉ�����o�C�A�X�̍ő�l
		 * @param SlopeScaledDepthBias �^����o�C�A�X�̌��z
		 * @param DepthClipEnable TRUE�Ȃ�[�x�l�ɂ��N���b�s���O��L���ɂ���
		 * @param ScissorEnable �V�U�[��`�ɂ��J�����O��L���ɂ���
		 * @param MultisampleEnable �}���`�E�T���v���ɂ��A���`�G�C���A�V���O��L���ɂ���
		 * @param AntialiasedLineEnable ���̃A���`�G�C���A�V���O��L���ɂ���
		 * @return ����
		*/
		HRESULT Create(
			CComPtr<ID3D11Device> pDevice,
			D3D11_FILL_MODE FillMode,
			D3D11_CULL_MODE CullMode,
			BOOL FrontCounterClockwise,
			INT DepthBias,
			FLOAT DepthBiasClamp,
			FLOAT SlopeScaledDepthBias,
			BOOL DepthClipEnable,
			BOOL ScissorEnable,
			BOOL MultisampleEnable,
			BOOL AnitialiasedLineEnable
		);

		/**
		 * ���X�^���C�U�X�e�[�g���Z�b�g����
		 * @param pDeviceContext �f�o�R��
		*/
		void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}