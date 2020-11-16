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

#define FORCE_VULKAN_VALIDATION 0
#define ENABLE_VULKAN_VALIDATION (_DEBUG || FORCE_VULKAN_VALIDATION)

#define FORCE_VULKAN_DEBUG_MARKUP 0
#define ENABLE_VULKAN_DEBUG_MARKUP (_DEBUG || _PROFILE || FORCE_VULKAN_DEBUG_MARKUP)

#define VK_USE_PLATFORM_WIN32_KHR 1
#include <vulkan\vulkan.h>

#pragma comment(lib, "vulkan-1.lib")

// Constant strings
const std::string s_apiName = "Vulkan";
const std::string s_apiPrefixString = "[Vulkan]";
const std::string s_defaultShaderPath = "Shaders\\SPIR-V";

inline void ThrowIfFailed(VkResult res)
{
	if (res != VK_SUCCESS)
	{
		throw;
	}
}

// Engine headers
#include "DynamicDispatchVk.h"
#include "RefCountingVk.h"
#include "StructureChainVk.h"