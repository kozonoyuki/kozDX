/**
* @file   DepthStencilTexture.h
* @brief  �f�v�X�X�e���V���e�N�X�`���i�����_�����O���ʁj
* @author kozonoyuki
* @date   1/11�ɏ����n��
*/

namespace koz
{
	/**
	* @brief �f�v�X�X�e���V���e�N�X�`���N���X
	*/
	class DepthStencilTexture
	{
	private:
		/**
		* �f�v�X�X�e���V���e�N�X�`��
		*/
		CComPtr<ID3D11Texture2D> m_DepthStencilTexture;

		/**
		* �f�v�X�X�e���V���e�N�X�`���\����
		*/
		D3D11_TEXTURE2D_DESC m_DepthStencilTextureDesc;

		/**
		* �f�v�X�X�e���V���r���[
		*/
		CComPtr<ID3D11DepthStencilView> m_DepthStencilView;

		/**
		* �f�v�X�X�e���V���r���[�\����
		*/
		D3D11_DEPTH_STENCIL_VIEW_DESC m_DepthStencilViewDesc;

		/**
		* �V�F�[�_���\�[�X�r���[
		*/
		CComPtr<ID3D11ShaderResourceView> m_ShaderResourceView;

		/**
		* �V�F�[�_���\�[�X�r���[�\����
		*/
		D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc;

	public:
		/**
		* �R���X�g���N�^
		*/
		DepthStencilTexture();

		/**
		* �f�X�g���N�^
		*/
		~DepthStencilTexture();

		/**
		* �f�v�X�X�e���V���e�N�X�`�����쐬����
		* @param pDevice �f�o�C�X
		* @param Width �e�N�X�`���̕�
		* @param Height �e�N�X�`���̍���
		* @param MipLevels �~�b�v�}�b�v���x���� 0�Ǝw�肷��Ɗ��S�ȃ~�b�v�}�b�v�`�F�C���������
		* @param ArraySize �e�N�X�`���z��̗v�f��
		* @param Format �e�N�Z���̃t�H�[�}�b�g
		* @param SampleDescCount �}���`�E�T���v�����O�̐ݒ�
		* @param SampleDescQuality �}���`�E�T���v�����O�̕i��
		* @param Usage �e�N�X�`�����\�[�X�̎g�p�@
		* @param BindFlags �e�N�X�`�����p�C�v���C���Ƀo�C���h������@
		* @param CPUAccessFlags CPU�A�N�Z�X�̎��CPU����A�N�Z�X���Ȃ��ꍇ��0
		* @param MiscFlags ���̑��̃t���O
		* @return ����
		*/
		HRESULT Create2DTexture(
			CComPtr<ID3D11Device> pDevice,
			UINT Width,
			UINT Height,
			UINT MipLevels,
			UINT ArraySize,
			DXGI_FORMAT Format,
			UINT SampleDescCount,
			UINT SampleDescQuality,
			D3D11_USAGE Usage,
			UINT BindFlags,
			UINT CPUAccessFlags,
			UINT MiscFlags
		);

		/**
		* �f�v�X�X�e���V���r���[���쐬����
		* @param pDevice �f�o�C�X
		* @param Format �t�H�[�}�b�g ���̂��Âꂩ<br>
		*               DXGI_FORMAT_D16_UNORM<br>
		*               DXGI_FORMAT_D24_UNORM_S8_UINT<br>
		*               DXGI_FORMAT_D32_FLOAT<br>
		*               DXGI_FORMAT_D32_FLOAT_S8X24_UINT
		* @param ViewDimension ���\�[�X�̎��
		* @param Flags �e�N�X�`�����ǂݎ���p�łȂ�0 ��pD3D11_DSV_READ_ONLY_DEPTH or _STENCIL
		* @param MipSlice 2D�e�N�X�`���̐ݒ�
		* @return ����
		*/
		HRESULT Create2DDepthStencilView(
			CComPtr<ID3D11Device> pDevice,
			DXGI_FORMAT Format,
			D3D11_DSV_DIMENSION ViewDimension,
			UINT Flags,
			UINT MipSlice
		);

		/**
		* �V�F�[�_���\�[�X�r���[���쐬����
		* @param pDevice �f�o�C�X
		* @param Format �t�H�[�}�b�g 
		* @param ViewDimension ���\�[�X�̎��
		* @param MostDetailedMip �ł��ڍׂȃ~�b�v�}�b�v�E���x��
		* @param MipLevels �S�Ẵ~�b�v�}�b�v�E���x��
		* @return ����
		*/
		HRESULT Create2DShaderResourceView(
			CComPtr<ID3D11Device> pDevice,
			DXGI_FORMAT Format,
			D3D11_SRV_DIMENSION ViewDeimension,
			UINT MostDetailedMip,
			UINT MipLevels
		);

		/**
		* �f�v�X�X�e���V���r���[���Z�b�g����
		* @param pDeviceContext �f�o�R��
		* @param pRenderTargetView �����_�[�^�[�Q�b�g�r���[
		*/
		void SetTarget(CComPtr<ID3D11DeviceContext> pDeviceContext, CComPtr<ID3D11RenderTargetView> pRenderTargetView);

		/**
		* �e�N�X�`�����V�F�[�_�ɐݒ肷��
		* @param pDeviceContext �f�o�R��
		* @param Slot �X���b�g�ԍ�
		*/
		void SetPS(CComPtr<ID3D11DeviceContext> pDeviceContext, UINT Slot);
	};
}