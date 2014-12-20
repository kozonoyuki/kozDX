/**
* @file   DynamicModel.cpp
* @brief  FBXアニメーションモデル
* @author kozonoyuki
* @date   12/19に書き始め
*/

#include "stdafx.h"
#include "DynamicModel.h"

void koz::DynamicModel::DynamicMesh::Create(CComPtr<ID3D11Device> pDevice, unsigned int MeshNum, DynamicModel& pModel)
{
	auto diffusename = pModel.m_FbxLoader->GetMaterial(pModel.m_FbxLoader->GetMaterialId(pModel.m_FbxLoader->GetMesh(MeshNum).materialNameList[0])).diffuseTextureName;
	auto slash_pos = diffusename.find_last_of('\\');
	diffusename = diffusename.substr(slash_pos + 1, diffusename.length());
	auto dot_pos = diffusename.find_last_of('.');
	this->m_DiffuseTextureName = diffusename.substr(0, dot_pos).append(".dds");

	auto mesh = pModel.m_FbxLoader->GetMesh(MeshNum);
	this->m_VertexesCount = mesh.vertexList.size();
	this->m_IndexesCount = mesh.indexList.size();
	this->m_MeshVertex = new DynamicVertex[this->m_VertexesCount];
	this->m_MeshIndex = new WORD[this->m_IndexesCount];
	for (unsigned int i = 0; i < this->m_VertexesCount; ++i)
	{
		this->m_MeshVertex[i].Pos = mesh.vertexList[i].position;
		this->m_MeshVertex[i].Norm = mesh.vertexList[i].normal;
		this->m_MeshVertex[i].Tex = mesh.vertexList[i].uv[0];
		for (int j = 0; j < 4; ++j)
		{
			this->m_MeshVertex[i].boneIndex[j] = mesh.vertexList[i].boneIndex[j];
		}
		this->m_MeshVertex[i].boneWeight = mesh.vertexList[i].boneWeight;
	}
	int idx_flag = 0;
	for (unsigned int i = 0; i < this->m_IndexesCount; ++i)
	{
		int offset = i / 3;
		int swap = 2 - i % 3;
		this->m_MeshIndex[offset * 3 + swap] = mesh.indexList[i];
	}

	this->m_VertexBuffer = std::make_shared<VertexBuffer<DynamicVertex>>(pDevice, this->m_MeshVertex, this->m_VertexesCount);
	this->m_IndexBuffer = std::make_shared<IndexBuffer<WORD>>(pDevice, this->m_MeshIndex, this->m_IndexesCount);
	this->m_Texture = std::make_shared<Texture>(pDevice, this->m_DiffuseTextureName);
}

koz::DynamicModel::DynamicMesh::~DynamicMesh()
{
	delete[] this->m_MeshVertex;
	delete[] this->m_MeshIndex;
}

koz::DynamicModel::DynamicModel()
{
	
}

koz::DynamicModel::~DynamicModel()
{

}

koz::DynamicModel::DynamicModel(CComPtr<ID3D11Device> pDevice, std::string filename)
{
	this->m_WVPConstantBuffer = std::make_shared<ConstantBuffer<DescWVP>>(pDevice);
	this->m_DynamicConstantBuffer = std::make_shared<ConstantBuffer<DescDynamic>>(pDevice);
	this->m_AnimationConstantBuffer = std::make_shared<ConstantBuffer<DescAnimation>>(pDevice);

	this->m_FbxLoader->Initialize(filename.c_str());
	this->m_MeshSize = this->m_FbxLoader->GetMeshCount();
	for (unsigned int i = 0; i < m_MeshSize; ++i)
	{
		
		std::shared_ptr<DynamicMesh> dmesh = std::make_shared<DynamicMesh>();
		dmesh->Create(pDevice, i, *this);
		this->m_MeshList.push_back(dmesh);
	}
}

void koz::DynamicModel::Draw()
{

}