/**
* @file   DynamicModel.cpp
* @brief  �A�j���[�V�������f��
* @author kozonoyuki
* @date   12/19�ɏ����n��
*/

#include "stdafx.h"
#include "DynamicModel.h"

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
}

void koz::DynamicModel::Draw()
{

}