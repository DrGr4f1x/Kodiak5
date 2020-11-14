//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#include "Stdafx.h"

#include "GraphicsEnumsVk.h"

#include <unordered_map>


using namespace Kodiak;
using namespace std;


vk::PrimitiveTopology Kodiak::PrimitiveTopologyToVulkan(PrimitiveTopology topology)
{
	switch (topology)
	{
	case PrimitiveTopology::PointList:
		return vk::PrimitiveTopology::ePointList;

	case PrimitiveTopology::LineList:
		return vk::PrimitiveTopology::eLineList;

	case PrimitiveTopology::LineStrip:
		return vk::PrimitiveTopology::eLineStrip;

	case PrimitiveTopology::TriangleList:
		return vk::PrimitiveTopology::eTriangleList;

	case PrimitiveTopology::TriangleStrip:
		return vk::PrimitiveTopology::eTriangleStrip;

	case PrimitiveTopology::LineListWithAdjacency:
		return vk::PrimitiveTopology::eLineListWithAdjacency;

	case PrimitiveTopology::LineStripWithAdjacency:
		return vk::PrimitiveTopology::eLineStripWithAdjacency;

	case PrimitiveTopology::TriangleListWithAdjacency:
		return vk::PrimitiveTopology::eTriangleListWithAdjacency;

	case PrimitiveTopology::TriangleStripWithAdjacency:
		return vk::PrimitiveTopology::eTriangleStripWithAdjacency;

	default:
		return vk::PrimitiveTopology::ePatchList;
	}
}


uint32_t Kodiak::GetControlPointCount(PrimitiveTopology topology)
{
	switch (topology)
	{
	case PrimitiveTopology::Patch_1_ControlPoint:	return 1;
	case PrimitiveTopology::Patch_2_ControlPoint:	return 2;
	case PrimitiveTopology::Patch_3_ControlPoint:	return 3;
	case PrimitiveTopology::Patch_4_ControlPoint:	return 4;
	case PrimitiveTopology::Patch_5_ControlPoint:	return 5;
	case PrimitiveTopology::Patch_6_ControlPoint:	return 6;
	case PrimitiveTopology::Patch_7_ControlPoint:	return 7;
	case PrimitiveTopology::Patch_8_ControlPoint:	return 8;
	case PrimitiveTopology::Patch_9_ControlPoint:	return 9;
	case PrimitiveTopology::Patch_10_ControlPoint:	return 10;
	case PrimitiveTopology::Patch_11_ControlPoint:	return 11;
	case PrimitiveTopology::Patch_12_ControlPoint:	return 12;
	case PrimitiveTopology::Patch_13_ControlPoint:	return 13;
	case PrimitiveTopology::Patch_14_ControlPoint:	return 14;
	case PrimitiveTopology::Patch_15_ControlPoint:	return 15;
	case PrimitiveTopology::Patch_16_ControlPoint:	return 16;
	case PrimitiveTopology::Patch_17_ControlPoint:	return 17;
	case PrimitiveTopology::Patch_18_ControlPoint:	return 18;
	case PrimitiveTopology::Patch_19_ControlPoint:	return 19;
	case PrimitiveTopology::Patch_20_ControlPoint:	return 20;
	case PrimitiveTopology::Patch_21_ControlPoint:	return 21;
	case PrimitiveTopology::Patch_22_ControlPoint:	return 22;
	case PrimitiveTopology::Patch_23_ControlPoint:	return 23;
	case PrimitiveTopology::Patch_24_ControlPoint:	return 24;
	case PrimitiveTopology::Patch_25_ControlPoint:	return 25;
	case PrimitiveTopology::Patch_26_ControlPoint:	return 26;
	case PrimitiveTopology::Patch_27_ControlPoint:	return 27;
	case PrimitiveTopology::Patch_28_ControlPoint:	return 28;
	case PrimitiveTopology::Patch_29_ControlPoint:	return 29;
	case PrimitiveTopology::Patch_30_ControlPoint:	return 30;
	case PrimitiveTopology::Patch_31_ControlPoint:	return 31;
	case PrimitiveTopology::Patch_32_ControlPoint:	return 32;
	default:
		return 0;
	}
}


vk::DescriptorType Kodiak::DescriptorTypeToVulkan(DescriptorType type)
{
	switch (type)
	{
	case DescriptorType::CBV:
		return vk::DescriptorType::eUniformBuffer;

	case DescriptorType::DynamicCBV:
		return vk::DescriptorType::eUniformBufferDynamic;

	case DescriptorType::Sampler:
		return vk::DescriptorType::eSampler;

	case DescriptorType::TextureSRV:
		return vk::DescriptorType::eSampledImage;

	case DescriptorType::StructuredBufferSRV:
	case DescriptorType::StructuredBufferUAV:
		return vk::DescriptorType::eStorageBuffer;

	case DescriptorType::TextureUAV:
		return vk::DescriptorType::eStorageImage;

	case DescriptorType::TypedBufferSRV:
		return vk::DescriptorType::eUniformTexelBuffer;

	case DescriptorType::TypedBufferUAV:
		return vk::DescriptorType::eStorageTexelBuffer;

	default:
		assert(false);
		return vk::DescriptorType::eCombinedImageSampler;
	}
}


Format Kodiak::VulkanFormatToEngine(vk::Format format)
{
	static bool initialized = false;
	static unordered_map<vk::Format, Format> remapTable;

	if (!initialized)
	{
		remapTable[vk::Format::eB4G4R4A4UnormPack16] = Format::B4G4R4A4_UNorm;
		remapTable[vk::Format::eB5G6R5UnormPack16] = Format::B5G6R5_UNorm;
		remapTable[vk::Format::eB5G5R5A1UnormPack16] = Format::B5G5R5A1_UNorm;
		remapTable[vk::Format::eB8G8R8A8Unorm] = Format::B8G8R8A8_UNorm;
		remapTable[vk::Format::eR8Unorm] = Format::R8_UNorm;
		remapTable[vk::Format::eR8Snorm] = Format::R8_SNorm;
		remapTable[vk::Format::eR8Uint] = Format::R8_UInt;
		remapTable[vk::Format::eR8Sint] = Format::R8_SInt;
		remapTable[vk::Format::eR8G8Unorm] = Format::R8G8_UNorm;
		remapTable[vk::Format::eR8G8Snorm] = Format::R8G8_SNorm;
		remapTable[vk::Format::eR8G8Uint] = Format::R8G8_UInt;
		remapTable[vk::Format::eR8G8Sint] = Format::R8G8_SInt;
		remapTable[vk::Format::eR8G8B8A8Unorm] = Format::R8G8B8A8_UNorm;
		remapTable[vk::Format::eR8G8B8A8Snorm] = Format::R8G8B8A8_SNorm;
		remapTable[vk::Format::eR8G8B8A8Uint] = Format::R8G8B8A8_UInt;
		remapTable[vk::Format::eR8G8B8A8Sint] = Format::R8G8B8A8_SInt;
		remapTable[vk::Format::eR16Unorm] = Format::R16_UNorm;
		remapTable[vk::Format::eR16Snorm] = Format::R16_SNorm;
		remapTable[vk::Format::eR16Uint] = Format::R16_UInt;
		remapTable[vk::Format::eR16Sint] = Format::R16_SInt;
		remapTable[vk::Format::eR16Sfloat] = Format::R16_Float;
		remapTable[vk::Format::eR16G16Unorm] = Format::R16G16_UNorm;
		remapTable[vk::Format::eR16G16Snorm] = Format::R16G16_SNorm;
		remapTable[vk::Format::eR16G16Uint] = Format::R16G16_UInt;
		remapTable[vk::Format::eR16G16Sint] = Format::R16G16_SInt;
		remapTable[vk::Format::eR16G16Sfloat] = Format::R16G16_Float;
		remapTable[vk::Format::eR16G16B16A16Unorm] = Format::R16G16B16A16_UNorm;
		remapTable[vk::Format::eR16G16B16A16Snorm] = Format::R16G16B16A16_SNorm;
		remapTable[vk::Format::eR16G16B16A16Uint] = Format::R16G16B16A16_UInt;
		remapTable[vk::Format::eR16G16B16A16Sint] = Format::R16G16B16A16_SInt;
		remapTable[vk::Format::eR16G16B16A16Sfloat] = Format::R16G16B16A16_Float;
		remapTable[vk::Format::eR32Uint] = Format::R32_UInt;
		remapTable[vk::Format::eR32Sint] = Format::R32_SInt;
		remapTable[vk::Format::eR32Sfloat] = Format::R32_Float;
		remapTable[vk::Format::eR32G32Uint] = Format::R32G32_UInt;
		remapTable[vk::Format::eR32G32Sint] = Format::R32G32_SInt;
		remapTable[vk::Format::eR32G32Sfloat] = Format::R32G32_Float;
		remapTable[vk::Format::eR32G32B32Uint] = Format::R32G32B32_UInt;
		remapTable[vk::Format::eR32G32B32Sint] = Format::R32G32B32_SInt;
		remapTable[vk::Format::eR32G32B32Sfloat] = Format::R32G32B32_Float;
		remapTable[vk::Format::eR32G32B32A32Uint] = Format::R32G32B32A32_UInt;
		remapTable[vk::Format::eR32G32B32A32Sint] = Format::R32G32B32A32_SInt;
		remapTable[vk::Format::eR32G32B32A32Sfloat] = Format::R32G32B32A32_Float;
		remapTable[vk::Format::eB10G11R11UfloatPack32] = Format::R11G11B10_Float;
		remapTable[vk::Format::eA2B10G10R10UnormPack32] = Format::R10G10B10A2_UNorm;

		remapTable[vk::Format::eD16Unorm] = Format::D16_UNorm;
		remapTable[vk::Format::eD24UnormS8Uint] = Format::D24S8;
		remapTable[vk::Format::eD32Sfloat] = Format::D32_Float;
		remapTable[vk::Format::eD32SfloatS8Uint] = Format::D32_Float_S8_UInt;

		remapTable[vk::Format::eBc1RgbaUnormBlock] = Format::BC1_UNorm;
		remapTable[vk::Format::eBc1RgbaSrgbBlock] = Format::BC1_UNorm_SRGB;
		remapTable[vk::Format::eBc2UnormBlock] = Format::BC2_UNorm;
		remapTable[vk::Format::eBc2SrgbBlock] = Format::BC2_UNorm_SRGB;
		remapTable[vk::Format::eBc3UnormBlock] = Format::BC3_UNorm;
		remapTable[vk::Format::eBc3SrgbBlock] = Format::BC3_UNorm_SRGB;
		remapTable[vk::Format::eBc4UnormBlock] = Format::BC4_UNorm;
		remapTable[vk::Format::eBc4SnormBlock] = Format::BC4_SNorm;
		remapTable[vk::Format::eBc5UnormBlock] = Format::BC5_UNorm;
		remapTable[vk::Format::eBc5SnormBlock] = Format::BC5_SNorm;
		remapTable[vk::Format::eBc6HSfloatBlock] = Format::BC6H_Float;
		remapTable[vk::Format::eBc6HUfloatBlock] = Format::BC6H_UFloat;
		remapTable[vk::Format::eBc7UnormBlock] = Format::BC7_UNorm;
		remapTable[vk::Format::eBc7SrgbBlock] = Format::BC7_UNorm_SRGB;

		initialized = true;
	}

	auto res = remapTable.find(format);
	if (res != remapTable.end())
	{
		return res->second;
	}

	return Format::Unknown;
}