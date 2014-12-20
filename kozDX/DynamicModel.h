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
#include <string>

namespace koz
{
	/**
	* ���_�\����
	*/
	struct DynamicVertex
	{
		DirectX::XMFLOAT3 Pos;
		DirectX::XMFLOAT2 Tex;
		DirectX::XMFLOAT3 Norm;
		uint32_t boneIndex[4];
		DirectX::XMFLOAT4 boneWeight;
	};

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
		public:
			unsigned int m_VertexesCount;
			unsigned int m_IndexesCount;
			
			DynamicVertex* m_MeshVertex;
			WORD* m_MeshIndex;
			std::string m_DiffuseTextureName;

			std::shared_ptr<VertexBuffer<DynamicVertex>> m_VertexBuffer;
			std::shared_ptr<IndexBuffer<WORD>> m_IndexBuffer;
			std::shared_ptr<Texture> m_Texture;

			void Create(CComPtr<ID3D11Device> pDevice, unsigned int MeshNum, DynamicModel& pModel);
			~DynamicMesh();
		};

	private:
		FBXLoader* m_FbxLoader;
		unsigned int m_MeshSize;
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