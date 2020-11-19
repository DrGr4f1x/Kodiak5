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
	std::vector<VkExtensionProperties> extensionProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkEnumerateInstanceExtensionProperties(pLayerName, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && propertyCount != 0)
		{
			extensionProperties.resize(propertyCount);
			result = vkEnumerateInstanceExtensionProperties(pLayerName, &propertyCount, extensionProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= extensionProperties.size());
		extensionProperties.resize(propertyCount);
	}
	return extensionProperties;
}


inline KODIAK_NODISCARD std::vector<VkLayerProperties> vkEnumerateInstanceLayerProperties()
{
	std::vector<VkLayerProperties> layerProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkEnumerateInstanceLayerProperties(&propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			layerProperties.resize(propertyCount);
			result = vkEnumerateInstanceLayerProperties(&propertyCount, layerProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= layerProperties.size());
		layerProperties.resize(propertyCount);
	}
	return layerProperties;
}


// Vulkan 1.0 instance functions (extended)
inline KODIAK_NODISCARD std::vector<VkPhysicalDevice> vkEnumeratePhysicalDevices(VkInstance instance)
{
	std::vector<VkPhysicalDevice> physicalDevices;
	uint32_t deviceCount = 0;
	VkResult result;
	do
	{
		result = vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
		if ((result == VK_SUCCESS) && (deviceCount != 0))
		{
			physicalDevices.resize(deviceCount);
			result = vkEnumeratePhysicalDevices(instance, &deviceCount, physicalDevices.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(deviceCount <= physicalDevices.size());
		physicalDevices.resize(deviceCount);
	}
	return physicalDevices;
}


inline KODIAK_NODISCARD std::vector<VkQueueFamilyProperties> vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice)
{
	std::vector<VkQueueFamilyProperties> queueFamilyProperties;
	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &propertyCount, nullptr);
	queueFamilyProperties.resize(propertyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &propertyCount, queueFamilyProperties.data());
	return queueFamilyProperties;
}


inline KODIAK_NODISCARD std::vector<VkSparseImageFormatProperties> vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling)
{
	std::vector<VkSparseImageFormatProperties> sparseImageFormatProperties;
	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, &propertyCount, nullptr);
	sparseImageFormatProperties.resize(propertyCount);
	vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, &propertyCount, sparseImageFormatProperties.data());
	return sparseImageFormatProperties;
}


// Vulkan 1.1 instance functions (extended)
inline KODIAK_NODISCARD std::vector<VkPhysicalDeviceGroupProperties> vkEnumeratePhysicalDeviceGroups(VkInstance instance)
{
	std::vector<VkPhysicalDeviceGroupProperties> physicalDeviceGroupProperties;
	uint32_t groupCount = 0;
	VkResult result;
	do
	{
		result = vkEnumeratePhysicalDeviceGroups(instance, &groupCount, nullptr);
		if ((result == VK_SUCCESS) && (groupCount != 0))
		{
			physicalDeviceGroupProperties.resize(groupCount);
			result = vkEnumeratePhysicalDeviceGroups(instance, &groupCount, physicalDeviceGroupProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(groupCount <= physicalDeviceGroupProperties.size());
		physicalDeviceGroupProperties.resize(groupCount);
	}
	return physicalDeviceGroupProperties;
}


inline KODIAK_NODISCARD std::vector<VkQueueFamilyProperties2> vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice)
{
	std::vector<VkQueueFamilyProperties2> queueFamilyProperties;
	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &propertyCount, nullptr);
	queueFamilyProperties.resize(propertyCount);
	vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &propertyCount, queueFamilyProperties.data());
	return queueFamilyProperties;
}


inline KODIAK_NODISCARD std::vector<VkSparseImageFormatProperties2> vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo)
{
	std::vector<VkSparseImageFormatProperties2> sparseImageFormatProperties;
	uint32_t propertyCount = 0;
	vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, &propertyCount, nullptr);
	sparseImageFormatProperties.resize(propertyCount);
	vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, &propertyCount, sparseImageFormatProperties.data());
	return sparseImageFormatProperties;
}


// Vulkan 1.0 device functions (extended)
inline KODIAK_NODISCARD std::vector<VkSparseImageMemoryRequirements> vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image)
{
	std::vector<VkSparseImageMemoryRequirements> sparseImageMemoryRequirements;
	uint32_t requirementsCount = 0;
	vkGetImageSparseMemoryRequirements(device, image, &requirementsCount, nullptr);
	sparseImageMemoryRequirements.resize(requirementsCount);
	vkGetImageSparseMemoryRequirements(device, image, &requirementsCount, sparseImageMemoryRequirements.data());
	return sparseImageMemoryRequirements;
}


// Vulkan 1.1 device functions (extended)
inline KODIAK_NODISCARD std::vector<VkSparseImageMemoryRequirements2> vkGetImageSparseMemoryRequirements(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo)
{
	std::vector<VkSparseImageMemoryRequirements2> imageSparseMemoryRequirements;
	uint32_t requirementsCount = 0;
	vkGetImageSparseMemoryRequirements2(device, pInfo, &requirementsCount, nullptr);
	imageSparseMemoryRequirements.resize(requirementsCount);
	vkGetImageSparseMemoryRequirements2(device, pInfo, &requirementsCount, imageSparseMemoryRequirements.data());
	return imageSparseMemoryRequirements;
}


// VK_KHR_display
inline KODIAK_NODISCARD std::vector<VkDisplayModePropertiesKHR> vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
	std::vector<VkDisplayModePropertiesKHR> displayModeProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetDisplayModePropertiesKHR(physicalDevice, display, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			displayModeProperties.resize(propertyCount);
			result = vkGetDisplayModePropertiesKHR(physicalDevice, display, &propertyCount, displayModeProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= displayModeProperties.size());
		displayModeProperties.resize(propertyCount);
	}
	return displayModeProperties;
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
	std::vector<VkDisplayPlanePropertiesKHR> displayPlaneProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			displayPlaneProperties.resize(propertyCount);
			result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, &propertyCount, displayPlaneProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= displayPlaneProperties.size());
		displayPlaneProperties.resize(propertyCount);
	}
	return displayPlaneProperties;
}


inline KODIAK_NODISCARD std::vector<VkDisplayPropertiesKHR> vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice)
{
	std::vector<VkDisplayPropertiesKHR> displayProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			displayProperties.resize(propertyCount);
			result = vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, &propertyCount, displayProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= displayProperties.size());
		displayProperties.resize(propertyCount);
	}
	return displayProperties;
}


// VK_KHR_get_display_properties2
inline KODIAK_NODISCARD std::vector<VkDisplayModeProperties2KHR> vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
	std::vector<VkDisplayModeProperties2KHR> displayModeProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkGetDisplayModeProperties2KHR(physicalDevice, display, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			displayModeProperties.resize(propertyCount);
			result = vkGetDisplayModeProperties2KHR(physicalDevice, display, &propertyCount, displayModeProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= displayModeProperties.size());
		displayModeProperties.resize(propertyCount);
	}
	return displayModeProperties;
}


inline KODIAK_NODISCARD std::vector<VkDisplayPlaneProperties2KHR> vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice)
{
	std::vector<VkDisplayPlaneProperties2KHR> displayPlaneProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do
	{
		result = vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			displayPlaneProperties.resize(propertyCount);
			result = vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, &propertyCount, displayPlaneProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= displayPlaneProperties.size());
		displayPlaneProperties.resize(propertyCount);
	}
	return displayPlaneProperties;
}


// VK_KHR_pipeline_executable_properties
inline KODIAK_NODISCARD std::vector<VkPipelineExecutableStatisticKHR> vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo)
{
	std::vector<VkPipelineExecutableStatisticKHR> pipelineExecutableStatistics;
	uint32_t statisticCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, &statisticCount, nullptr);
		if ((result == VK_SUCCESS) && (statisticCount != 0))
		{
			pipelineExecutableStatistics.resize(statisticCount);
			result = vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, &statisticCount, pipelineExecutableStatistics.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(statisticCount <= pipelineExecutableStatistics.size());
		pipelineExecutableStatistics.resize(statisticCount);
	}
	return pipelineExecutableStatistics;
}


// VK_KHR_surface
inline KODIAK_NODISCARD std::vector<VkSurfaceFormatKHR> vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface)
{
	std::vector<VkSurfaceFormatKHR> surfaceFormats;
	uint32_t formatCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, nullptr);
		if ((result == VK_SUCCESS) && (formatCount != 0))
		{
			surfaceFormats.resize(formatCount);
			result = vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, surfaceFormats.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(formatCount <= surfaceFormats.size());
		surfaceFormats.resize(formatCount);
	}
	return surfaceFormats;
}


inline KODIAK_NODISCARD std::vector<VkPresentModeKHR> vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface)
{
	std::vector<VkPresentModeKHR> presentModes;
	uint32_t modeCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &modeCount, nullptr);
		if ((result == VK_SUCCESS) && (modeCount != 0))
		{
			presentModes.resize(modeCount);
			result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &modeCount, presentModes.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(modeCount <= presentModes.size());
		presentModes.resize(modeCount);
	}
	return presentModes;
}


// VK_KHR_swapchain
inline KODIAK_NODISCARD std::vector<VkImage> vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain)
{
	std::vector<VkImage> images;
	uint32_t imageCount = 0;
	VkResult result;
	do 
	{
		result = vkGetSwapchainImagesKHR(device, swapchain, &imageCount, nullptr);
		if ((result == VK_SUCCESS) && (imageCount != 0))
		{
			images.resize(imageCount);
			result = vkGetSwapchainImagesKHR(device, swapchain, &imageCount, images.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(imageCount <= images.size());
		images.resize(imageCount);
	}
	return images;
}


// VK_EXT_calibrated_timestamps
inline KODIAK_NODISCARD std::vector<VkTimeDomainEXT> vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice)
{
	std::vector<VkTimeDomainEXT> timeDomains;
	uint32_t domainCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, &domainCount, nullptr);
		if ((result == VK_SUCCESS) && (domainCount != 0))
		{
			timeDomains.resize(domainCount);
			result = vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, &domainCount, timeDomains.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(domainCount <= timeDomains.size());
		timeDomains.resize(domainCount);
	}
	return timeDomains;
}


// VK_EXT_full_screen_exclusive
inline KODIAK_NODISCARD std::vector<VkPresentModeKHR> vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo)
{
	std::vector<VkPresentModeKHR> presentModes;
	uint32_t modeCount = 0;
	VkResult result;
	do
	{
		result = vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, &modeCount, nullptr);
		if ((result == VK_SUCCESS) && (modeCount != 0))
		{
			presentModes.resize(modeCount);
			result = vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, &modeCount, presentModes.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(modeCount <= presentModes.size());
		presentModes.resize(modeCount);
	}
	return presentModes;
}


// VK_EXT_tooling_info
inline KODIAK_NODISCARD std::vector<VkPhysicalDeviceToolPropertiesEXT> vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice)
{
	std::vector<VkPhysicalDeviceToolPropertiesEXT> toolProperties;
	uint32_t propertyCount = 0;
	VkResult result;
	do 
	{
		result = vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, &propertyCount, nullptr);
		if ((result == VK_SUCCESS) && (propertyCount != 0))
		{
			toolProperties.resize(propertyCount);
			result = vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, &propertyCount, toolProperties.data());
		}
	} while (result == VK_INCOMPLETE);
	if (result == VK_SUCCESS)
	{
		assert(propertyCount <= toolProperties.size());
		toolProperties.resize(propertyCount);
	}
	return toolProperties;
}