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

using namespace Kodiak;


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