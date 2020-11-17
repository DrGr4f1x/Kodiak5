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

namespace Kodiak
{

#define DECLARE_FUNCTION(name) \
PFN_##name name = nullptr


enum class Extension : uint32_t;


class Dispatcher
{
public:
	Dispatcher() = default;
	Dispatcher(PFN_vkGetInstanceProcAddr getInstanceProcAddr);

	void SetApiVersion(uint32_t apiVersion) { m_apiVersion = apiVersion; }
	void Initialize(PFN_vkGetInstanceProcAddr getInstanceProcAddr);
	void Initialize(VkInstance instance);
	void Initialize(VkDevice device);
	void LoadExtension(Extension extension);

	//
	//  CORE VULKAN
	//

	// Base functions (loaded without a VkInstance handle)
	DECLARE_FUNCTION(vkCreateInstance);
	DECLARE_FUNCTION(vkEnumerateInstanceExtensionProperties);
	DECLARE_FUNCTION(vkEnumerateInstanceLayerProperties);
	DECLARE_FUNCTION(vkEnumerateInstanceVersion);
	DECLARE_FUNCTION(vkGetInstanceProcAddr);

	// Vulkan 1.0 instance functions
	DECLARE_FUNCTION(vkCreateDevice);
	DECLARE_FUNCTION(vkDestroyInstance);
	DECLARE_FUNCTION(vkEnumeratePhysicalDevices);
	DECLARE_FUNCTION(vkGetDeviceProcAddr);
	DECLARE_FUNCTION(vkGetPhysicalDeviceFeatures);
	DECLARE_FUNCTION(vkGetPhysicalDeviceFormatProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties);

	// Vulkan 1.1 instance functions
	DECLARE_FUNCTION(vkEnumeratePhysicalDeviceGroups);
	DECLARE_FUNCTION(vkGetPhysicalDeviceExternalBufferProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceExternalFenceProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceExternalSemaphoreProperties);
	DECLARE_FUNCTION(vkGetPhysicalDeviceFeatures2);
	DECLARE_FUNCTION(vkGetPhysicalDeviceFormatProperties2);
	DECLARE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties2);
	DECLARE_FUNCTION(vkGetPhysicalDeviceMemoryProperties2);
	DECLARE_FUNCTION(vkGetPhysicalDeviceProperties2);
	DECLARE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties2);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties2);

	// Vulkan 1.0 device functions
	DECLARE_FUNCTION(vkAllocateCommandBuffers);
	DECLARE_FUNCTION(vkAllocateDescriptorSets);
	DECLARE_FUNCTION(vkAllocateMemory);
	DECLARE_FUNCTION(vkBeginCommandBuffer);
	DECLARE_FUNCTION(vkBindBufferMemory);
	DECLARE_FUNCTION(vkBindImageMemory);
	DECLARE_FUNCTION(vkCmdBeginQuery);
	DECLARE_FUNCTION(vkCmdBeginRenderPass);
	DECLARE_FUNCTION(vkCmdBindDescriptorSets);
	DECLARE_FUNCTION(vkCmdBindIndexBuffer);
	DECLARE_FUNCTION(vkCmdBindPipeline);
	DECLARE_FUNCTION(vkCmdBindVertexBuffers);
	DECLARE_FUNCTION(vkCmdBlitImage);
	DECLARE_FUNCTION(vkCmdClearAttachments);
	DECLARE_FUNCTION(vkCmdClearColorImage);
	DECLARE_FUNCTION(vkCmdClearDepthStencilImage);
	DECLARE_FUNCTION(vkCmdCopyBuffer);
	DECLARE_FUNCTION(vkCmdCopyBufferToImage);
	DECLARE_FUNCTION(vkCmdCopyImage);
	DECLARE_FUNCTION(vkCmdCopyImageToBuffer);
	DECLARE_FUNCTION(vkCmdCopyQueryPoolResults);
	DECLARE_FUNCTION(vkCmdDispatch);
	DECLARE_FUNCTION(vkCmdDispatchIndirect);
	DECLARE_FUNCTION(vkCmdDraw);
	DECLARE_FUNCTION(vkCmdDrawIndexed);
	DECLARE_FUNCTION(vkCmdDrawIndexedIndirect);
	DECLARE_FUNCTION(vkCmdDrawIndirect);
	DECLARE_FUNCTION(vkCmdEndQuery);
	DECLARE_FUNCTION(vkCmdEndRenderPass);
	DECLARE_FUNCTION(vkCmdExecuteCommands);
	DECLARE_FUNCTION(vkCmdFillBuffer);
	DECLARE_FUNCTION(vkCmdNextSubpass);
	DECLARE_FUNCTION(vkCmdPipelineBarrier);
	DECLARE_FUNCTION(vkCmdPushConstants);
	DECLARE_FUNCTION(vkCmdResetEvent);
	DECLARE_FUNCTION(vkCmdResetQueryPool);
	DECLARE_FUNCTION(vkCmdResolveImage);
	DECLARE_FUNCTION(vkCmdSetBlendConstants);
	DECLARE_FUNCTION(vkCmdSetDepthBias);
	DECLARE_FUNCTION(vkCmdSetDepthBounds);
	DECLARE_FUNCTION(vkCmdSetEvent);
	DECLARE_FUNCTION(vkCmdSetLineWidth);
	DECLARE_FUNCTION(vkCmdSetScissor);
	DECLARE_FUNCTION(vkCmdSetStencilCompareMask);
	DECLARE_FUNCTION(vkCmdSetStencilReference);
	DECLARE_FUNCTION(vkCmdSetStencilWriteMask);
	DECLARE_FUNCTION(vkCmdSetViewport);
	DECLARE_FUNCTION(vkCmdUpdateBuffer);
	DECLARE_FUNCTION(vkCmdWaitEvents);
	DECLARE_FUNCTION(vkCmdWriteTimestamp);
	DECLARE_FUNCTION(vkCreateBuffer);
	DECLARE_FUNCTION(vkCreateBufferView);
	DECLARE_FUNCTION(vkCreateCommandPool);
	DECLARE_FUNCTION(vkCreateComputePipelines);
	DECLARE_FUNCTION(vkCreateDescriptorPool);
	DECLARE_FUNCTION(vkCreateDescriptorSetLayout);
	DECLARE_FUNCTION(vkCreateEvent);
	DECLARE_FUNCTION(vkCreateFence);
	DECLARE_FUNCTION(vkCreateFramebuffer);
	DECLARE_FUNCTION(vkCreateGraphicsPipelines);
	DECLARE_FUNCTION(vkCreateImage);
	DECLARE_FUNCTION(vkCreateImageView);
	DECLARE_FUNCTION(vkCreatePipelineCache);
	DECLARE_FUNCTION(vkCreatePipelineLayout);
	DECLARE_FUNCTION(vkCreateQueryPool);
	DECLARE_FUNCTION(vkCreateRenderPass);
	DECLARE_FUNCTION(vkCreateSampler);
	DECLARE_FUNCTION(vkCreateSemaphore);
	DECLARE_FUNCTION(vkCreateShaderModule);
	DECLARE_FUNCTION(vkDestroyBuffer);
	DECLARE_FUNCTION(vkDestroyBufferView);
	DECLARE_FUNCTION(vkDestroyCommandPool);
	DECLARE_FUNCTION(vkDestroyDescriptorPool);
	DECLARE_FUNCTION(vkDestroyDescriptorSetLayout);
	DECLARE_FUNCTION(vkDestroyDevice);
	DECLARE_FUNCTION(vkDestroyEvent);
	DECLARE_FUNCTION(vkDestroyFence);
	DECLARE_FUNCTION(vkDestroyFramebuffer);
	DECLARE_FUNCTION(vkDestroyImage);
	DECLARE_FUNCTION(vkDestroyImageView);
	DECLARE_FUNCTION(vkDestroyPipeline);
	DECLARE_FUNCTION(vkDestroyPipelineCache);
	DECLARE_FUNCTION(vkDestroyPipelineLayout);
	DECLARE_FUNCTION(vkDestroyQueryPool);
	DECLARE_FUNCTION(vkDestroyRenderPass);
	DECLARE_FUNCTION(vkDestroySampler);
	DECLARE_FUNCTION(vkDestroySemaphore);
	DECLARE_FUNCTION(vkDestroyShaderModule);
	DECLARE_FUNCTION(vkDeviceWaitIdle);
	DECLARE_FUNCTION(vkEndCommandBuffer);
	DECLARE_FUNCTION(vkFlushMappedMemoryRanges);
	DECLARE_FUNCTION(vkFreeCommandBuffers);
	DECLARE_FUNCTION(vkFreeDescriptorSets);
	DECLARE_FUNCTION(vkFreeMemory);
	DECLARE_FUNCTION(vkGetBufferMemoryRequirements);
	DECLARE_FUNCTION(vkGetDeviceMemoryCommitment);
	DECLARE_FUNCTION(vkGetDeviceQueue);
	DECLARE_FUNCTION(vkGetEventStatus);
	DECLARE_FUNCTION(vkGetFenceStatus);
	DECLARE_FUNCTION(vkGetImageMemoryRequirements);
	DECLARE_FUNCTION(vkGetImageSparseMemoryRequirements);
	DECLARE_FUNCTION(vkGetImageSubresourceLayout);
	DECLARE_FUNCTION(vkGetPipelineCacheData);
	DECLARE_FUNCTION(vkGetQueryPoolResults);
	DECLARE_FUNCTION(vkGetRenderAreaGranularity);
	DECLARE_FUNCTION(vkInvalidateMappedMemoryRanges);
	DECLARE_FUNCTION(vkMapMemory);
	DECLARE_FUNCTION(vkMergePipelineCaches);
	DECLARE_FUNCTION(vkQueueBindSparse);
	DECLARE_FUNCTION(vkQueueSubmit);
	DECLARE_FUNCTION(vkQueueWaitIdle);
	DECLARE_FUNCTION(vkResetCommandBuffer);
	DECLARE_FUNCTION(vkResetCommandPool);
	DECLARE_FUNCTION(vkResetDescriptorPool);
	DECLARE_FUNCTION(vkResetEvent);
	DECLARE_FUNCTION(vkResetFences);
	DECLARE_FUNCTION(vkSetEvent);
	DECLARE_FUNCTION(vkUnmapMemory);
	DECLARE_FUNCTION(vkUpdateDescriptorSets);
	DECLARE_FUNCTION(vkWaitForFences);

	// Vulkan 1.1 device functions
	DECLARE_FUNCTION(vkBindBufferMemory2);
	DECLARE_FUNCTION(vkBindImageMemory2);
	DECLARE_FUNCTION(vkCreateDescriptorUpdateTemplate);
	DECLARE_FUNCTION(vkCreateSamplerYcbcrConversion);
	DECLARE_FUNCTION(vkDestroyDescriptorUpdateTemplate);
	DECLARE_FUNCTION(vkDestroySamplerYcbcrConversion);
	DECLARE_FUNCTION(vkGetBufferMemoryRequirements2);
	DECLARE_FUNCTION(vkGetDescriptorSetLayoutSupport);
	DECLARE_FUNCTION(vkGetDeviceGroupPeerMemoryFeatures);
	DECLARE_FUNCTION(vkGetDeviceQueue2);
	DECLARE_FUNCTION(vkGetImageMemoryRequirements2);
	DECLARE_FUNCTION(vkGetImageSparseMemoryRequirements2);
	DECLARE_FUNCTION(vkTrimCommandPool);
	DECLARE_FUNCTION(vkUpdateDescriptorSetWithTemplate);

	// Vulkan 1.2 device functions
	DECLARE_FUNCTION(vkCmdBeginRenderPass2);
	DECLARE_FUNCTION(vkCmdDrawIndexedIndirectCount);
	DECLARE_FUNCTION(vkCmdDrawIndirectCount);
	DECLARE_FUNCTION(vkCmdEndRenderPass2);
	DECLARE_FUNCTION(vkCmdNextSubpass2);
	DECLARE_FUNCTION(vkCreateRenderPass2);
	DECLARE_FUNCTION(vkGetBufferDeviceAddress);
	DECLARE_FUNCTION(vkGetBufferOpaqueCaptureAddress);
	DECLARE_FUNCTION(vkGetDeviceMemoryOpaqueCaptureAddress);
	DECLARE_FUNCTION(vkGetSemaphoreCounterValue);
	DECLARE_FUNCTION(vkResetQueryPool);
	DECLARE_FUNCTION(vkSignalSemaphore);
	DECLARE_FUNCTION(vkWaitSemaphores);


	//
	//  VULKAN EXTENSIONS
	//

	// VK_KHR_android_surface
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	DECLARE_FUNCTION(vkCreateAndroidSurfaceKHR);
#endif

	// VK_KHR_copy_commands2
	DECLARE_FUNCTION(vkCmdBlitImage2KHR);
	DECLARE_FUNCTION(vkCmdCopyBuffer2KHR);
	DECLARE_FUNCTION(vkCmdCopyBufferToImage2KHR);
	DECLARE_FUNCTION(vkCmdCopyImage2KHR);
	DECLARE_FUNCTION(vkCmdCopyImageToBuffer2KHR);
	DECLARE_FUNCTION(vkCmdResolveImage2KHR);

	// VK_KHR_display
	DECLARE_FUNCTION(vkCreateDisplayModeKHR);
	DECLARE_FUNCTION(vkCreateDisplayPlaneSurfaceKHR);
	DECLARE_FUNCTION(vkGetDisplayModePropertiesKHR);
	DECLARE_FUNCTION(vkGetDisplayPlaneCapabilitiesKHR);
	DECLARE_FUNCTION(vkGetDisplayPlaneSupportedDisplaysKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceDisplayPropertiesKHR);

	// VK_KHR_display_swapchain
	DECLARE_FUNCTION(vkCreateSharedSwapchainsKHR);

	// VK_KHR_external_fence_fd
	DECLARE_FUNCTION(vkGetFenceFdKHR);
	DECLARE_FUNCTION(vkImportFenceFdKHR);

	// VK_KHR_external_fence_win32
	DECLARE_FUNCTION(vkGetFenceWin32HandleKHR);
	DECLARE_FUNCTION(vkImportFenceWin32HandleKHR);

	// VK_KHR_external_memory_fd
	DECLARE_FUNCTION(vkGetMemoryFdKHR);
	DECLARE_FUNCTION(vkGetMemoryFdPropertiesKHR);

	// VK_KHR_external_memory_win32
	DECLARE_FUNCTION(vkGetMemoryWin32HandleKHR);
	DECLARE_FUNCTION(vkGetMemoryWin32HandlePropertiesKHR);

	// VK_KHR_external_semaphore_fd
	DECLARE_FUNCTION(vkGetSemaphoreFdKHR);
	DECLARE_FUNCTION(vkImportSemaphoreFdKHR);

	// VK_KHR_external_semaphore_win32
	DECLARE_FUNCTION(vkGetSemaphoreWin32HandleKHR);
	DECLARE_FUNCTION(vkImportSemaphoreWin32HandleKHR);

#if 0
	// VK_KHR_fragment_shading_rate
	DECLARE_FUNCTION(vkCmdSetFragmentShadingRateKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceFragmentShadingRatesKHR);
#endif

	// VK_KHR_get_display_properties2
	DECLARE_FUNCTION(vkGetDisplayModeProperties2KHR);
	DECLARE_FUNCTION(vkGetDisplayPlaneCapabilities2KHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceDisplayProperties2KHR);

	// VK_KHR_get_surface_capabilities2
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfaceFormats2KHR);

	// VK_KHR_performance_query
	DECLARE_FUNCTION(vkAcquireProfilingLockKHR);
	DECLARE_FUNCTION(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
	DECLARE_FUNCTION(vkReleaseProfilingLockKHR);

	// VK_KHR_pipeline_executable_properties
	DECLARE_FUNCTION(vkGetPipelineExecutableInternalRepresentationsKHR);
	DECLARE_FUNCTION(vkGetPipelineExecutablePropertiesKHR);
	DECLARE_FUNCTION(vkGetPipelineExecutableStatisticsKHR);

	// VK_KHR_push_descriptor
	DECLARE_FUNCTION(vkCmdPushDescriptorSetKHR);
	DECLARE_FUNCTION(vkCmdPushDescriptorSetWithTemplateKHR);

	// VK_KHR_shared_presentable_image
	DECLARE_FUNCTION(vkGetSwapchainStatusKHR);

	// VK_KHR_surface
	DECLARE_FUNCTION(vkDestroySurfaceKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfaceFormatsKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfacePresentModesKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfaceSupportKHR);

	// VK_KHR_swapchain
	DECLARE_FUNCTION(vkAcquireNextImageKHR);
	DECLARE_FUNCTION(vkCreateSwapchainKHR);
	DECLARE_FUNCTION(vkDestroySwapchainKHR);
	DECLARE_FUNCTION(vkGetSwapchainImagesKHR);
	DECLARE_FUNCTION(vkQueuePresentKHR);

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
	// VK_KHR_wayland_surface
	DECLARE_FUNCTION(vkCreateWaylandSurfaceKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
	// VK_KHR_win32_surface
	DECLARE_FUNCTION(vkCreateWin32SurfaceKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceWin32PresentationSupportKHR);
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
	// VK_KHR_xcb_surface
	DECLARE_FUNCTION(vkCreateXcbSurfaceKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceXcbPresentationSupportKHR);
#endif

#ifdef VK_USE_PLATFORM_XLIB_KHR
	// VK_KHR_xlib_surface
	DECLARE_FUNCTION(vkCreateXlibSurfaceKHR);
	DECLARE_FUNCTION(vkGetPhysicalDeviceXlibPresentationSupportKHR);
#endif

private:
	uint32_t m_apiVersion{ 0 };
	VkInstance m_instance{ VK_NULL_HANDLE };
	VkDevice m_device{ VK_NULL_HANDLE };
};

#undef DECLARE_FUNCTION

extern Dispatcher g_dispatcher;

} // namespace Kodiak


// Base functions
VkResult vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName,	uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
VkResult vkEnumerateInstanceVersion(uint32_t* pApiVersion);
PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char* pName);