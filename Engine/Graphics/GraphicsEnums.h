//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#pragma once

#if defined(DX12)
#include "Graphics\DX12\GraphicsEnums12.h"
#elif defined(VK)
#include "Graphics\VK\GraphicsEnumsVk.h"
#else
#error "No graphics API specified!"
#endif


enum class ResourceState : uint32_t
{
	Undefined,
	Common,
	VertexBuffer,
	IndexBuffer,
	ConstantBuffer,
	RenderTarget,
	UnorderedAccess,
	DepthWrite,
	DepthRead,
	NonPixelShaderResource,
	PixelShaderResource,
	ShaderResource,
	StreamOut,
	IndirectArgument,
	CopyDest,
	CopySource,
	ResolveDest,
	ResolveSource,
	GenericRead,
	Present,
	Predication,
	PreInitialized,
};


enum class QueryHeapType : uint32_t
{
	Occlusion,
	Timestamp,
	PipelineStats
};


enum class QueryType : uint32_t
{
	Occlusion,
	Timestamp,
	PipelineStats
};


enum class RootParameterType : uint32_t
{
	Invalid,
	DescriptorTable,
	RootConstants,
	RootCBV,
	DynamicRootCBV
};