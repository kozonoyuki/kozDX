/**
* @file   ConstantBuffer.h
* @brief  コンスタントバッファをラッパ
* @author kozonoyuki
* @date   12/19に書き始め
*/

#pragma once

#include <d3d11_1.h>
#include <atlbase.h>

namespace koz
{
	/**
	* @brief コンスタントバッファクラス
	*/
	class ConstantBuffer
	{
	private:
		CComPtr<ID3D11Buffer> m_ConstantBuffer;

	public:

	};
}