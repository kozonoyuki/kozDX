/**
* @file   DynamicModel.h
* @brief  アニメーションモデル
* @author kozonoyuki
* @date   12/19に書き始め
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
	* 頂点構造体
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
	* @brief 動的モデルクラス
	*/
	class DynamicModel : protected DynamicObject
	{
	public:
		/**
		* @brief 動的モデルクラスで利用するMeshクラス
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
		* コンストラクタ
		*/
		DynamicModel();

		/**
		* コンストラクタ
		*/
		DynamicModel(CComPtr<ID3D11Device> pDevice, std::string filename);

		/**
		* デストラクタ
		*/
		~DynamicModel();

		/**
		* バッファをセットし、描画まで行う
		*/
		void Draw(CComPtr<ID3D11DeviceContext> pDeviceContext);
	};
}