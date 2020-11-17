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

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
	// VK_EXT_acquire_xlib_display
	DECLARE_FUNCTION(vkAcquireXlibDisplayEXT);
	DECLARE_FUNCTION(vkGetRandROutputDisplayEXT);
#endif

	// VK_EXT_calibrated_timestamps
	DECLARE_FUNCTION(vkGetCalibratedTimestampsEXT);
	DECLARE_FUNCTION(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);

	// VK_EXT_conditional_rendering
	DECLARE_FUNCTION(vkCmdBeginConditionalRenderingEXT);
	DECLARE_FUNCTION(vkCmdEndConditionalRenderingEXT);

	// VK_EXT_debug_utils
	DECLARE_FUNCTION(vkCmdBeginDebugUtilsLabelEXT);
	DECLARE_FUNCTION(vkCmdEndDebugUtilsLabelEXT);
	DECLARE_FUNCTION(vkCmdInsertDebugUtilsLabelEXT);
	DECLARE_FUNCTION(vkCreateDebugUtilsMessengerEXT);
	DECLARE_FUNCTION(vkDestroyDebugUtilsMessengerEXT);
	DECLARE_FUNCTION(vkQueueBeginDebugUtilsLabelEXT);
	DECLARE_FUNCTION(vkQueueEndDebugUtilsLabelEXT);
	DECLARE_FUNCTION(vkQueueInsertDebugUtilsLabelEXT);
	DECLARE_FUNCTION(vkSetDebugUtilsObjectNameEXT);
	DECLARE_FUNCTION(vkSetDebugUtilsObjectTagEXT);
	DECLARE_FUNCTION(vkSubmitDebugUtilsMessageEXT);

	// VK_EXT_direct_mode_display
	DECLARE_FUNCTION(vkReleaseDisplayEXT);

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
	// VK_EXT_directfb_surface
	DECLARE_FUNCTION(vkCreateDirectFBSurfaceEXT);
	DECLARE_FUNCTION(vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
#endif

	// VK_EXT_discard_rectangles
	DECLARE_FUNCTION(vkCmdSetDiscardRectangleEXT);

	// VK_EXT_display_control
	DECLARE_FUNCTION(vkDisplayPowerControlEXT);
	DECLARE_FUNCTION(vkGetSwapchainCounterEXT);
	DECLARE_FUNCTION(vkRegisterDeviceEventEXT);
	DECLARE_FUNCTION(vkRegisterDisplayEventEXT);

	// VK_EXT_display_surface_counter
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfaceCapabilities2EXT);

	// VK_EXT_extended_dynamic_state
	DECLARE_FUNCTION(vkCmdBindVertexBuffers2EXT);
	DECLARE_FUNCTION(vkCmdSetCullModeEXT);
	DECLARE_FUNCTION(vkCmdSetDepthBoundsTestEnableEXT);
	DECLARE_FUNCTION(vkCmdSetDepthCompareOpEXT);
	DECLARE_FUNCTION(vkCmdSetDepthTestEnableEXT);
	DECLARE_FUNCTION(vkCmdSetDepthWriteEnableEXT);
	DECLARE_FUNCTION(vkCmdSetFrontFaceEXT);
	DECLARE_FUNCTION(vkCmdSetPrimitiveTopologyEXT);
	DECLARE_FUNCTION(vkCmdSetScissorWithCountEXT);
	DECLARE_FUNCTION(vkCmdSetStencilOpEXT);
	DECLARE_FUNCTION(vkCmdSetStencilTestEnableEXT);
	DECLARE_FUNCTION(vkCmdSetViewportWithCountEXT);

	// VK_EXT_external_memory_host
	DECLARE_FUNCTION(vkGetMemoryHostPointerPropertiesEXT);

	// VK_EXT_full_screen_exclusive
	DECLARE_FUNCTION(vkAcquireFullScreenExclusiveModeEXT);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfacePresentModes2EXT);
	DECLARE_FUNCTION(vkReleaseFullScreenExclusiveModeEXT);

	// VK_EXT_hdr_metadata
	DECLARE_FUNCTION(vkSetHdrMetadataEXT);

	// VK_EXT_headless_surface
	DECLARE_FUNCTION(vkCreateHeadlessSurfaceEXT);

	// VK_EXT_image_drm_format_modifier
	DECLARE_FUNCTION(vkGetImageDrmFormatModifierPropertiesEXT);

	// VK_EXT_line_rasterization
	DECLARE_FUNCTION(vkCmdSetLineStippleEXT);

#ifdef VK_USE_PLATFORM_METAL_EXT
	// VK_EXT_metal_surface
	DECLARE_FUNCTION(vkCreateMetalSurfaceEXT);
#endif

	// VK_EXT_private_data
	DECLARE_FUNCTION(vkCreatePrivateDataSlotEXT);
	DECLARE_FUNCTION(vkDestroyPrivateDataSlotEXT);
	DECLARE_FUNCTION(vkGetPrivateDataEXT);
	DECLARE_FUNCTION(vkSetPrivateDataEXT);

	// VK_EXT_sample_locations
	DECLARE_FUNCTION(vkCmdSetSampleLocationsEXT);
	DECLARE_FUNCTION(vkGetPhysicalDeviceMultisamplePropertiesEXT);

	// VK_EXT_tooling_info
	DECLARE_FUNCTION(vkGetPhysicalDeviceToolPropertiesEXT);

	// VK_EXT_transform_feedback
	DECLARE_FUNCTION(vkCmdBeginQueryIndexedEXT);
	DECLARE_FUNCTION(vkCmdBeginTransformFeedbackEXT);
	DECLARE_FUNCTION(vkCmdBindTransformFeedbackBuffersEXT);
	DECLARE_FUNCTION(vkCmdDrawIndirectByteCountEXT);
	DECLARE_FUNCTION(vkCmdEndQueryIndexedEXT);
	DECLARE_FUNCTION(vkCmdEndTransformFeedbackEXT);

	// VK_EXT_validation_cache
	DECLARE_FUNCTION(vkCreateValidationCacheEXT);
	DECLARE_FUNCTION(vkDestroyValidationCacheEXT);
	DECLARE_FUNCTION(vkGetValidationCacheDataEXT);
	DECLARE_FUNCTION(vkMergeValidationCachesEXT);

	// VK_AMD_buffer_marker
	DECLARE_FUNCTION(vkCmdWriteBufferMarkerAMD);

	// VK_AMD_display_native_hdr
	DECLARE_FUNCTION(vkSetLocalDimmingAMD);

	// VK_AMD_shader_info
	DECLARE_FUNCTION(vkGetShaderInfoAMD);

#ifdef VK_USE_PLATFORM_ANDROID_KHR
	// VK_ANDROID_external_memory_android_hardware_buffer
	DECLARE_FUNCTION(vkGetAndroidHardwareBufferPropertiesANDROID);
	DECLARE_FUNCTION(vkGetMemoryAndroidHardwareBufferANDROID);
#endif

#ifdef VK_USE_PLATFORM_FUSCHIA
	// VK_FUSCHIA_imagepipe_surface
	DECLARE_FUNCTION(vkCreateImagePipeSurfaceFUCHSIA);
#endif

#if 0
	// VK_GGP_stream_descriptor_surface
	DECLARE_FUNCTION(vkCreateStreamDescriptorSurfaceGGP);
#endif

	// VK_GOOGLE_display_timing
	DECLARE_FUNCTION(vkGetPastPresentationTimingGOOGLE);
	DECLARE_FUNCTION(vkGetRefreshCycleDurationGOOGLE);

	// VK_INTEL_performance_query
	DECLARE_FUNCTION(vkAcquirePerformanceConfigurationINTEL);
	DECLARE_FUNCTION(vkCmdSetPerformanceMarkerINTEL);
	DECLARE_FUNCTION(vkCmdSetPerformanceOverrideINTEL);
	DECLARE_FUNCTION(vkCmdSetPerformanceStreamMarkerINTEL);
	DECLARE_FUNCTION(vkGetPerformanceParameterINTEL);
	DECLARE_FUNCTION(vkInitializePerformanceApiINTEL);
	DECLARE_FUNCTION(vkQueueSetPerformanceConfigurationINTEL);
	DECLARE_FUNCTION(vkReleasePerformanceConfigurationINTEL);
	DECLARE_FUNCTION(vkUninitializePerformanceApiINTEL);

#ifdef VK_USE_PLATFORM_VI_NN
	// VK_NN_vi_surface
	DECLARE_FUNCTION(vkCreateViSurfaceNN);
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