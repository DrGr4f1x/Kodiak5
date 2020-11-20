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

// Base functions (extended)
inline KODIAK_NODISCARD std::vector<VkExtensionProperties> vkEnumerateInstanceExtensionProperties(const char* pLayerName)
{
	std::vector<VkExtensionProperties> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkEnumerateInstanceExtensionProperties(pLayerName, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && propertyCount != 0)
		{
			properties.resize(propertyCount);
			result = vkEnumerateInstanceExtensionProperties(pLayerName, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


inline KODIAK_NODISCARD std::vector<VkLayerProperties> vkEnumerateInstanceLayerProperties()
{
	std::vector<VkLayerProperties> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkEnumerateInstanceLayerProperties(&propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkEnumerateInstanceLayerProperties(&propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


// Vulkan 1.0 instance functions (extended)
inline KODIAK_NODISCARD std::vector<VkPhysicalDevice> vkEnumeratePhysicalDevices(VkInstance instance)
{
	std::vector<VkPhysicalDevice> physicalDevices;
	uint32_t physicalDeviceCount = 0;
	VkResult result;
	do
	{
		result = vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr);
		if ((result == VK_SUCCESS) && (physicalDeviceCount != 0))
		{
			physicalDevices.resize(physicalDeviceCount);
			result = vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(physicalDeviceCount <= physicalDevices.size());
		physicalDevices.resize(physicalDeviceCount);
	}
	return physicalDevices;
}


inline KODIAK_NODISCARD std::vector<VkQueueFamilyProperties> vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice)
{
	std::vector<VkQueueFamilyProperties> queueFamilyProperties;
	uint32_t queueFamilyPropertyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyPropertyCount, nullptr);
	queueFamilyProperties.resize(queueFamilyPropertyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyPropertyCount, queueFamilyProperties.data());
	return queueFamilyProperties;
}


inline KODIAK_NODISCARD std::vector<VkSparseImageFormatProperties> vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling)
{
	std::vector<VkSparseImageFormatProperties> properties;
	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, &propertyCount, nullptr);
	properties.resize(propertyCount);
	vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, &propertyCount, properties.data());
	return properties;
}


// Vulkan 1.1 instance functions (extended)
inline KODIAK_NODISCARD std::vector<VkPhysicalDeviceGroupProperties> vkEnumeratePhysicalDeviceGroups(VkInstance instance)
{
	std::vector<VkPhysicalDeviceGroupProperties> physicalDeviceGroupProperties;
	uint32_t physicalDeviceGroupCount = 0;
	VkResult result;
	do
	{
		result = vkEnumeratePhysicalDeviceGroups(instance, &physicalDeviceGroupCount, nullptr);
		if ((result == VK_SUCCESS) && (physicalDeviceGroupCount != 0))
		{
			physicalDeviceGroupProperties.resize(physicalDeviceGroupCount);
			result = vkEnumeratePhysicalDeviceGroups(instance, &physicalDeviceGroupCount, physicalDeviceGroupProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(physicalDeviceGroupCount <= physicalDeviceGroupProperties.size());
		physicalDeviceGroupProperties.resize(physicalDeviceGroupCount);
	}
	return physicalDeviceGroupProperties;
}


inline KODIAK_NODISCARD std::vector<VkQueueFamilyProperties2> vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice)
{
	std::vector<VkQueueFamilyProperties2> queueFamilyProperties;
	uint32_t queueFamilyPropertyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &queueFamilyPropertyCount, nullptr);
	queueFamilyProperties.resize(queueFamilyPropertyCount);
	vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &queueFamilyPropertyCount, queueFamilyProperties.data());
	return queueFamilyProperties;
}


inline KODIAK_NODISCARD std::vector<VkSparseImageFormatProperties2> vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo)
{
	std::vector<VkSparseImageFormatProperties2> properties;
	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, &propertyCount, nullptr);
	properties.resize(propertyCount);
	vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, &propertyCount, properties.data());
	return properties;
}


// Vulkan 1.0 device functions (extended)
inline KODIAK_NODISCARD std::vector<VkSparseImageMemoryRequirements> vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image)
{
	std::vector<VkSparseImageMemoryRequirements> sparseMemoryRequirements;
	uint32_t sparseMemoryRequirementCount = 0;
	vkGetImageSparseMemoryRequirements(device, image, &sparseMemoryRequirementCount, nullptr);
	sparseMemoryRequirements.resize(sparseMemoryRequirementCount);
	vkGetImageSparseMemoryRequirements(device, image, &sparseMemoryRequirementCount, sparseMemoryRequirements.data());
	return sparseMemoryRequirements;
}


// Vulkan 1.1 device functions (extended)
inline KODIAK_NODISCARD std::vector<VkSparseImageMemoryRequirements2> vkGetImageSparseMemoryRequirements(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo)
{
	std::vector<VkSparseImageMemoryRequirements2> sparseMemoryRequirements;
	uint32_t sparseMemoryRequirementCount = 0;
	vkGetImageSparseMemoryRequirements2(device, pInfo, &sparseMemoryRequirementCount, nullptr);
	sparseMemoryRequirements.resize(sparseMemoryRequirementCount);
	vkGetImageSparseMemoryRequirements2(device, pInfo, &sparseMemoryRequirementCount, sparseMemoryRequirements.data());
	return sparseMemoryRequirements;
}


// VK_KHR_display
inline KODIAK_NODISCARD std::vector<VkDisplayModePropertiesKHR> vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
	std::vector<VkDisplayModePropertiesKHR> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetDisplayModePropertiesKHR(physicalDevice, display, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetDisplayModePropertiesKHR(physicalDevice, display, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


inline KODIAK_NODISCARD std::vector<VkDisplayKHR> vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex)
{
	std::vector<VkDisplayKHR> displays;
	uint32_t displayCount = 0;
	VkResult result;
	do 
	{
		result = vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, &displayCount, nullptr);
		if ((result == VK_SUCCESS) && (displayCount != 0))
		{
			displays.resize(displayCount);
			result = vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, &displayCount, displays.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(displayCount <= displays.size());
		displays.resize(displayCount);
	}
	return displays;
}


inline KODIAK_NODISCARD std::vector<VkDisplayPlanePropertiesKHR> vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice)
{
	std::vector<VkDisplayPlanePropertiesKHR> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


inline KODIAK_NODISCARD std::vector<VkDisplayPropertiesKHR> vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice)
{
	std::vector<VkDisplayPropertiesKHR> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


// VK_KHR_get_display_properties2
inline KODIAK_NODISCARD std::vector<VkDisplayModeProperties2KHR> vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
	std::vector<VkDisplayModeProperties2KHR> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkGetDisplayModeProperties2KHR(physicalDevice, display, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetDisplayModeProperties2KHR(physicalDevice, display, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


inline KODIAK_NODISCARD std::vector<VkDisplayPlaneProperties2KHR> vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice)
{
	std::vector<VkDisplayPlaneProperties2KHR> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


// VK_KHR_pipeline_executable_properties
inline KODIAK_NODISCARD std::vector<VkPipelineExecutableInternalRepresentationKHR> vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo)
{
	std::vector<VkPipelineExecutableInternalRepresentationKHR> internalRepresentations;
	uint32_t internalRepresentationCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, &internalRepresentationCount, nullptr);
		if ((result == VK_SUCCESS) && (internalRepresentationCount != 0))
		{
			internalRepresentations.resize(internalRepresentationCount);
			result = vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, &internalRepresentationCount, internalRepresentations.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(internalRepresentationCount <= internalRepresentations.size());
		internalRepresentations.resize(internalRepresentationCount);
	}
	return internalRepresentations;
}


inline KODIAK_NODISCARD std::vector<VkPipelineExecutablePropertiesKHR> vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo)
{
	std::vector<VkPipelineExecutablePropertiesKHR> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


inline KODIAK_NODISCARD std::vector<VkPipelineExecutableStatisticKHR> vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo)
{
	std::vector<VkPipelineExecutableStatisticKHR> statistics;
	uint32_t statisticCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, &statisticCount, nullptr);
		if ((result == VK_SUCCESS) && (statisticCount != 0))
		{
			statistics.resize(statisticCount);
			result = vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, &statisticCount, statistics.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(statisticCount <= statistics.size());
		statistics.resize(statisticCount);
	}
	return statistics;
}


// VK_KHR_surface
inline KODIAK_NODISCARD std::vector<VkSurfaceFormatKHR> vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface)
{
	std::vector<VkSurfaceFormatKHR> surfaceFormats;
	uint32_t surfaceFormatCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &surfaceFormatCount, nullptr);
		if ((result == VK_SUCCESS) && (surfaceFormatCount != 0))
		{
			surfaceFormats.resize(surfaceFormatCount);
			result = vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &surfaceFormatCount, surfaceFormats.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(surfaceFormatCount <= surfaceFormats.size());
		surfaceFormats.resize(surfaceFormatCount);
	}
	return surfaceFormats;
}


inline KODIAK_NODISCARD std::vector<VkPresentModeKHR> vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface)
{
	std::vector<VkPresentModeKHR> presentModes;
	uint32_t presentModeCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, nullptr);
		if ((result == VK_SUCCESS) && (presentModeCount != 0))
		{
			presentModes.resize(presentModeCount);
			result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, presentModes.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(presentModeCount <= presentModes.size());
		presentModes.resize(presentModeCount);
	}
	return presentModes;
}


// VK_KHR_swapchain
inline KODIAK_NODISCARD std::vector<VkImage> vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain)
{
	std::vector<VkImage> swapchainImages;
	uint32_t swapchainImageCount = 0;
	VkResult result;
	do 
	{
		result = vkGetSwapchainImagesKHR(device, swapchain, &swapchainImageCount, nullptr);
		if ((result == VK_SUCCESS) && (swapchainImageCount != 0))
		{
			swapchainImages.resize(swapchainImageCount);
			result = vkGetSwapchainImagesKHR(device, swapchain, &swapchainImageCount, swapchainImages.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(swapchainImageCount <= swapchainImages.size());
		swapchainImages.resize(swapchainImageCount);
	}
	return swapchainImages;
}


// VK_EXT_calibrated_timestamps
inline KODIAK_NODISCARD std::vector<VkTimeDomainEXT> vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice)
{
	std::vector<VkTimeDomainEXT> timeDomains;
	uint32_t timeDomainCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, &timeDomainCount, nullptr);
		if ((result == VK_SUCCESS) && (timeDomainCount != 0))
		{
			timeDomains.resize(timeDomainCount);
			result = vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, &timeDomainCount, timeDomains.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(timeDomainCount <= timeDomains.size());
		timeDomains.resize(timeDomainCount);
	}
	return timeDomains;
}


// VK_EXT_full_screen_exclusive
inline KODIAK_NODISCARD std::vector<VkPresentModeKHR> vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo)
{
	std::vector<VkPresentModeKHR> presentModes;
	uint32_t presentModeCount = 0;
	VkResult result;
	do
	{
		result = vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, &presentModeCount, nullptr);
		if ((result == VK_SUCCESS) && (presentModeCount != 0))
		{
			presentModes.resize(presentModeCount);
			result = vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, &presentModeCount, presentModes.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(presentModeCount <= presentModes.size());
		presentModes.resize(presentModeCount);
	}
	return presentModes;
}


// VK_EXT_tooling_info
inline KODIAK_NODISCARD std::vector<VkPhysicalDeviceToolPropertiesEXT> vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice)
{
	std::vector<VkPhysicalDeviceToolPropertiesEXT> toolProperties;
	uint32_t toolCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, &toolCount, nullptr);
		if ((result == VK_SUCCESS) && (toolCount != 0))
		{
			toolProperties.resize(toolCount);
			result = vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, &toolCount, toolProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(toolCount <= toolProperties.size());
		toolProperties.resize(toolCount);
	}
	return toolProperties;
}


// VK_GOOGLE_display_timing
inline KODIAK_NODISCARD std::vector<VkPastPresentationTimingGOOGLE> vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain)
{
	std::vector<VkPastPresentationTimingGOOGLE> presentationTimings;
	uint32_t presentationTimingCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPastPresentationTimingGOOGLE(device, swapchain, &presentationTimingCount, nullptr);
		if ((result == VK_SUCCESS) && (presentationTimingCount != 0))
		{
			presentationTimings.resize(presentationTimingCount);
			result = vkGetPastPresentationTimingGOOGLE(device, swapchain, &presentationTimingCount, presentationTimings.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(presentationTimingCount <= presentationTimings.size());
		presentationTimings.resize(presentationTimingCount);
	}
	return presentationTimings;
}


// VK_NV_cooperative_matrix
inline KODIAK_NODISCARD std::vector<VkCooperativeMatrixPropertiesNV> vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice)
{
	std::vector<VkCooperativeMatrixPropertiesNV> properties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			properties.resize(propertyCount);
			result = vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, &propertyCount, properties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= properties.size());
		properties.resize(propertyCount);
	}
	return properties;
}


// VK_NV_coverage_reduction_mode
inline KODIAK_NODISCARD std::vector<VkFramebufferMixedSamplesCombinationNV> vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice)
{
	std::vector<VkFramebufferMixedSamplesCombinationNV> combinations;
	uint32_t combinationCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, &combinationCount, nullptr);
		if ((result == VK_SUCCESS) && (combinationCount != 0))
		{
			combinations.resize(combinationCount);
			result = vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, &combinationCount, combinations.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(combinationCount <= combinations.size());
		combinations.resize(combinationCount);
	}
	return combinations;
}


// VK_NV_device_diagnostic_checkpoints
inline KODIAK_NODISCARD std::vector<VkCheckpointDataNV> vkGetQueueCheckpointDataNV(VkQueue queue)
{
	std::vector<VkCheckpointDataNV> checkpointData;
	uint32_t checkpointDataCount = 0;
	vkGetQueueCheckpointDataNV(queue, &checkpointDataCount, nullptr);
	checkpointData.resize(checkpointDataCount);
	vkGetQueueCheckpointDataNV(queue, &checkpointDataCount, checkpointData.data());
	return checkpointData;
}