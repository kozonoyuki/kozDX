/**
* @file   DynamicModel.cpp
* @brief  FBXアニメーションモデル
* @author kozonoyuki
* @date   12/19に書き始め
*/

#include "stdafx.h"
#include "DynamicModel.h"

koz::DynamicModel::DynamicMesh::DynamicMesh() { }

koz::DynamicModel::DynamicMesh::DynamicMesh(CComPtr<ID3D11Device> pDevice, unsigned int MeshNum, DynamicModel& pModel)
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
	this->m_SamplerState = std::make_shared<SamplerState>();
	this->m_SamplerState->Create(pDevice,
		D3D11_FILTER_ANISOTROPIC,
		D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_WRAP,
		0.0f,
		2,
		D3D11_COMPARISON_NEVER,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		-D3D11_FLOAT32_MAX,
		D3D11_FLOAT32_MAX);
}

koz::DynamicModel::DynamicMesh::~DynamicMesh()
{
	delete[] this->m_MeshVertex;
	delete[] this->m_MeshIndex;
}

void koz::DynamicModel::DynamicMesh::Set(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	this->m_VertexBuffer->Set(pDeviceContext);
	this->m_IndexBuffer->Set(pDeviceContext);
	this->m_Texture->Set(pDeviceContext, 0);
	this->m_SamplerState->SetPS(pDeviceContext, 0);
}

koz::DynamicModel::DynamicModel() { }

koz::DynamicModel::~DynamicModel() { }

koz::DynamicModel::DynamicModel(CComPtr<ID3D11Device> pDevice, std::string filename)
{
	this->m_WVPConstantBuffer = std::make_shared<ConstantBuffer<DescWVP>>(pDevice);
	this->m_DynamicConstantBuffer = std::make_shared<ConstantBuffer<DescDynamic>>(pDevice);
	this->m_AnimationConstantBuffer = std::make_shared<ConstantBuffer<DescAnimation>>(pDevice);

	this->m_FbxLoader->Initialize(filename.c_str());
	this->m_MeshSize = this->m_FbxLoader->GetMeshCount();
	for (unsigned int i = 0; i < m_MeshSize; ++i)
	{
		std::shared_ptr<DynamicMesh> dmesh = std::make_shared<DynamicMesh>(pDevice, i, *this);
		this->m_MeshList.push_back(dmesh);
	}
}

void koz::DynamicModel::Draw(CComPtr<ID3D11DeviceContext> pDeviceContext)
{
	for (unsigned int i = 0; i < this->m_MeshSize; ++i)
	{
		this->m_MeshList[i]->Set(pDeviceContext);
		pDeviceContext->DrawIndexed(this->m_MeshList[i]->m_IndexesCount, 0, 0);
	}
}
