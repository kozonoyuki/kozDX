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
#include "SamplerState.h"
#include "Description.h"

namespace koz
{
	

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
		private:
			DynamicMesh();
		public:
			unsigned int m_VertexesCount;
			unsigned int m_IndexesCount;
			
			DynamicVertex* m_MeshVertex;
			WORD* m_MeshIndex;
			std::string m_DiffuseTextureName;

			std::shared_ptr<VertexBuffer<DynamicVertex>> m_VertexBuffer;
			std::shared_ptr<IndexBuffer<WORD>> m_IndexBuffer;
			std::shared_ptr<Texture> m_Texture;
			std::shared_ptr<SamplerState> m_SamplerState;

			DynamicMesh(CComPtr<ID3D11Device> pDevice, unsigned int MeshNum, DynamicModel& pModel);
			~DynamicMesh();

			void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
		};

	private: 
		std::shared_ptr<FBXLoader> m_FbxLoader;
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