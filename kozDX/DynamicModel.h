/**
* @file   DynamicModel.h
* @brief  �A�j���[�V�������f��
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#pragma once
#include "DynamicObject.h"
#include "FbxLoader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "SamplerState.h"
#include "Description.h"

namespace koz
{
	/**
	* @brief ���I���f���N���X
	*/
	class DynamicModel : protected DynamicObject
	{
	public:
		/**
		* @brief ���I���f���N���X�ŗ��p����Mesh�N���X
		*/
		class DynamicMesh
		{
		private:
			/**
			* �R���X�g���N�^�i�g�p�֎~�j
			*/
			DynamicMesh();

		public:
			/**
			* ���_��
			*/
			unsigned int m_VertexesCount;

			/**
			* �C���f�b�N�X��
			*/
			unsigned int m_IndexesCount;
			
			/**
			* ���_�f�[�^
			*/
			DynamicVertex* m_MeshVertex;

			/**
			* �C���f�b�N�X�f�[�^
			*/
			WORD* m_MeshIndex;

			/**
			* �e�N�X�`����
			*/
			std::string m_DiffuseTextureName;

			/**
			* ���_�o�b�t�@
			*/
			std::shared_ptr<VertexBuffer<DynamicVertex>> m_VertexBuffer;

			/**
			* �C���f�b�N�X�o�b�t�@
			*/
			std::shared_ptr<IndexBuffer<WORD>> m_IndexBuffer;

			/**
			* �e�N�X�`���f�[�^
			*/
			std::shared_ptr<Texture> m_Texture;

			/**
			* �T���v��
			*/
			std::shared_ptr<SamplerState> m_SamplerState;

			/**
			* �R���X�g���N�^
			*/
			DynamicMesh(CComPtr<ID3D11Device> pDevice, unsigned int MeshNum, DynamicModel& pModel);

			/**
			* �f�X�g���N�^
			*/
			~DynamicMesh();

			/**
			* �f�o�R���Z�b�g�֐�
			*/
			void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
		};

	private:
		/**
		* FBX���[�_�N���X
		*/
		std::shared_ptr<FBXLoader> m_FbxLoader;

		/**
		* ���b�V���T�C�Y
		*/
		unsigned int m_MeshSize;

		/**
		* ���b�V���̃��X�g
		*/
		std::vector<std::shared_ptr<DynamicMesh>> m_MeshList;

	public:
		/**
		* �R���X�g���N�^
		*/
		DynamicModel();

		/**
		* �R���X�g���N�^
		*/
		DynamicModel(CComPtr<ID3D11Device> pDevice, std::string filename);

		/**
		* �f�X�g���N�^
		*/
		~DynamicModel();

		/**
		* �o�b�t�@���Z�b�g���A�`��܂ōs��
		*/
		void Draw(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}