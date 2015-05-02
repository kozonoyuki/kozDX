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
			/**
			* コンストラクタ（使用禁止）
			*/
			DynamicMesh();

		public:
			/**
			* 頂点数
			*/
			unsigned int m_VertexesCount;

			/**
			* インデックス数
			*/
			unsigned int m_IndexesCount;
			
			/**
			* 頂点データ
			*/
			DynamicVertex* m_MeshVertex;

			/**
			* インデックスデータ
			*/
			WORD* m_MeshIndex;

			/**
			* テクスチャ名
			*/
			std::string m_DiffuseTextureName;

			/**
			* 頂点バッファ
			*/
			std::shared_ptr<VertexBuffer<DynamicVertex>> m_VertexBuffer;

			/**
			* インデックスバッファ
			*/
			std::shared_ptr<IndexBuffer<WORD>> m_IndexBuffer;

			/**
			* テクスチャデータ
			*/
			std::shared_ptr<Texture> m_Texture;

			/**
			* サンプラ
			*/
			std::shared_ptr<SamplerState> m_SamplerState;

			/**
			* コンストラクタ
			*/
			DynamicMesh(CComPtr<ID3D11Device> pDevice, unsigned int MeshNum, DynamicModel& pModel);

			/**
			* デストラクタ
			*/
			~DynamicMesh();

			/**
			* デバコンセット関数
			*/
			void Set(CComPtr<ID3D11DeviceContext> pDeviceContext);
		};

	private:
		/**
		* FBXローダクラス
		*/
		std::shared_ptr<FBXLoader> m_FbxLoader;

		/**
		* メッシュサイズ
		*/
		unsigned int m_MeshSize;

		/**
		* メッシュのリスト
		*/
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