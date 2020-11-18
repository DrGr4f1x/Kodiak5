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
#ifdef VK_USE_PLATFORM_WIN32_KHR
	DECLARE_FUNCTION(vkGetFenceWin32HandleKHR);
	DECLARE_FUNCTION(vkImportFenceWin32HandleKHR);
#endif

	// VK_KHR_external_memory_fd
	DECLARE_FUNCTION(vkGetMemoryFdKHR);
	DECLARE_FUNCTION(vkGetMemoryFdPropertiesKHR);

	// VK_KHR_external_memory_win32
#ifdef VK_USE_PLATFORM_WIN32_KHR
	DECLARE_FUNCTION(vkGetMemoryWin32HandleKHR);
	DECLARE_FUNCTION(vkGetMemoryWin32HandlePropertiesKHR);
#endif

	// VK_KHR_external_semaphore_fd
	DECLARE_FUNCTION(vkGetSemaphoreFdKHR);
	DECLARE_FUNCTION(vkImportSemaphoreFdKHR);

	// VK_KHR_external_semaphore_win32
#ifdef VK_USE_PLATFORM_WIN32_KHR
	DECLARE_FUNCTION(vkGetSemaphoreWin32HandleKHR);
	DECLARE_FUNCTION(vkImportSemaphoreWin32HandleKHR);
#endif

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

#ifdef VK_USE_PLATFORM_WIN32_KHR
	// VK_EXT_full_screen_exclusive
	DECLARE_FUNCTION(vkAcquireFullScreenExclusiveModeEXT);
	DECLARE_FUNCTION(vkGetDeviceGroupSurfacePresentModes2EXT);
	DECLARE_FUNCTION(vkGetPhysicalDeviceSurfacePresentModes2EXT);
	DECLARE_FUNCTION(vkReleaseFullScreenExclusiveModeEXT);
#endif

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

#ifdef VK_USE_PLATFORM_GGP
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

	// VK_NV_clip_space_w_scaling
	DECLARE_FUNCTION(vkCmdSetViewportWScalingNV);

	// VK_NV_cooperative_matrix
	DECLARE_FUNCTION(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);

	// VK_NV_coverage_reduction_mode
	DECLARE_FUNCTION(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);

	// VK_NV_device_diagnostic_checkpoints
	DECLARE_FUNCTION(vkCmdSetCheckpointNV);
	DECLARE_FUNCTION(vkGetQueueCheckpointDataNV);

	// VK_NV_device_generated_commands
	DECLARE_FUNCTION(vkCmdBindPipelineShaderGroupNV);
	DECLARE_FUNCTION(vkCmdExecuteGeneratedCommandsNV);
	DECLARE_FUNCTION(vkCmdPreprocessGeneratedCommandsNV);
	DECLARE_FUNCTION(vkCreateIndirectCommandsLayoutNV);
	DECLARE_FUNCTION(vkDestroyIndirectCommandsLayoutNV);
	DECLARE_FUNCTION(vkGetGeneratedCommandsMemoryRequirementsNV);

#if 0
	// VK_NV_fragment_shading_rate_enums
	DECLARE_FUNCTION(vkCmdSetFragmentShadingRateEnumNV);
#endif

	// VK_NV_mesh_shader
	DECLARE_FUNCTION(vkCmdDrawMeshTasksIndirectCountNV);
	DECLARE_FUNCTION(vkCmdDrawMeshTasksIndirectNV);
	DECLARE_FUNCTION(vkCmdDrawMeshTasksNV);

	// VK_NV_ray_tracing
	DECLARE_FUNCTION(vkBindAccelerationStructureMemoryNV);
	DECLARE_FUNCTION(vkCmdBuildAccelerationStructureNV);
	DECLARE_FUNCTION(vkCmdCopyAccelerationStructureNV);
	DECLARE_FUNCTION(vkCmdTraceRaysNV);
	DECLARE_FUNCTION(vkCmdWriteAccelerationStructuresPropertiesNV);
	DECLARE_FUNCTION(vkCompileDeferredNV);
	DECLARE_FUNCTION(vkCreateAccelerationStructureNV);
	DECLARE_FUNCTION(vkCreateRayTracingPipelinesNV);
	DECLARE_FUNCTION(vkDestroyAccelerationStructureNV);
	DECLARE_FUNCTION(vkGetAccelerationStructureHandleNV);
	DECLARE_FUNCTION(vkGetAccelerationStructureMemoryRequirementsNV);
	DECLARE_FUNCTION(vkGetRayTracingShaderGroupHandlesNV);

	// VK_NV_scissor_exclusive
	DECLARE_FUNCTION(vkCmdSetExclusiveScissorNV);

	// VK_NV_shading_rate_image
	DECLARE_FUNCTION(vkCmdBindShadingRateImageNV);
	DECLARE_FUNCTION(vkCmdSetCoarseSampleOrderNV);
	DECLARE_FUNCTION(vkCmdSetViewportShadingRatePaletteNV);

	// VK_NVX_image_view_handle
	DECLARE_FUNCTION(vkGetImageViewAddressNVX);
	DECLARE_FUNCTION(vkGetImageViewHandleNVX);

private:
	uint32_t m_apiVersion{ 0 };
	VkInstance m_instance{ VK_NULL_HANDLE };
	VkDevice m_device{ VK_NULL_HANDLE };
};

#undef DECLARE_FUNCTION

extern Dispatcher g_dispatcher;

} // namespace Kodiak


#if VALIDATE_FUNCTION_POINTERS
#define VALIDATE_FUNCTION_POINTER(FPTR) \
assert_msg(Kodiak::g_dispatcher.##FPTR, "Function pointer #FPTR is null")
#else
#define VALIDATE_FUNCTION_POINTER(FPTR) 
#endif


// Base functions
inline KODIAK_NODISCARD VkResult vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{
	VALIDATE_FUNCTION_POINTER(vkCreateInstance);
	return Kodiak::g_dispatcher.vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}
inline KODIAK_NODISCARD VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkEnumerateInstanceExtensionProperties);
	return Kodiak::g_dispatcher.vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}
inline KODIAK_NODISCARD VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkEnumerateInstanceLayerProperties);
	return Kodiak::g_dispatcher.vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}
inline KODIAK_NODISCARD VkResult vkEnumerateInstanceVersion(uint32_t* pApiVersion)
{
	VALIDATE_FUNCTION_POINTER(vkEnumerateInstanceVersion);
	return Kodiak::g_dispatcher.vkEnumerateInstanceVersion(pApiVersion);
}
inline PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char* pName)
{
	VALIDATE_FUNCTION_POINTER(vkGetInstanceProcAddr);
	return Kodiak::g_dispatcher.vkGetInstanceProcAddr(instance, pName);
}


// Vulkan 1.0 instance functions
inline KODIAK_NODISCARD VkResult vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDevice);
	return Kodiak::g_dispatcher.vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
}
inline void vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyInstance);
	Kodiak::g_dispatcher.vkDestroyInstance(instance, pAllocator);
}
inline KODIAK_NODISCARD VkResult vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices)
{
	VALIDATE_FUNCTION_POINTER(vkEnumeratePhysicalDevices);
	return Kodiak::g_dispatcher.vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
}
inline KODIAK_NODISCARD PFN_vkVoidFunction vkGetDeviceProcAddr(VkDevice device, const char* pName)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceProcAddr);
	return Kodiak::g_dispatcher.vkGetDeviceProcAddr(device, pName);
}
inline void vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceFeatures);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}
inline void vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceFormatProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceImageFormatProperties);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
}
inline void vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceMemoryProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}
inline void vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
}
inline void vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceQueueFamilyProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
inline void vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSparseImageFormatProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}


// Vulkan 1.1 instance functions
inline KODIAK_NODISCARD VkResult vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
	VALIDATE_FUNCTION_POINTER(vkEnumeratePhysicalDeviceGroups);
	return Kodiak::g_dispatcher.vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
}
inline void vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceExternalBufferProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
inline void vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceExternalFenceProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
inline void vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceExternalSemaphoreProperties);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
inline void vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceFeatures2);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}
inline void vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceFormatProperties2);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceImageFormatProperties2);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}
inline void vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceMemoryProperties2);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
}
inline void vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceProperties2);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
}
inline void vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceQueueFamilyProperties2);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
inline void vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSparseImageFormatProperties2);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}


// Vulkan 1.0 device functions
inline KODIAK_NODISCARD VkResult vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
{
	VALIDATE_FUNCTION_POINTER(vkAllocateCommandBuffers);
	return Kodiak::g_dispatcher.vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
}
inline KODIAK_NODISCARD VkResult vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets)
{
	VALIDATE_FUNCTION_POINTER(vkAllocateDescriptorSets);
	return Kodiak::g_dispatcher.vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}
inline KODIAK_NODISCARD VkResult vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory)
{
	VALIDATE_FUNCTION_POINTER(vkAllocateMemory);
	return Kodiak::g_dispatcher.vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}
inline KODIAK_NODISCARD VkResult vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo)
{
	VALIDATE_FUNCTION_POINTER(vkBeginCommandBuffer);
	return Kodiak::g_dispatcher.vkBeginCommandBuffer(commandBuffer, pBeginInfo);
}
inline KODIAK_NODISCARD VkResult vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	VALIDATE_FUNCTION_POINTER(vkBindBufferMemory);
	return Kodiak::g_dispatcher.vkBindBufferMemory(device, buffer, memory, memoryOffset);
}
inline KODIAK_NODISCARD VkResult vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	VALIDATE_FUNCTION_POINTER(vkBindImageMemory);
	return Kodiak::g_dispatcher.vkBindImageMemory(device, image, memory, memoryOffset);
}
inline void vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginQuery);
	Kodiak::g_dispatcher.vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
}
inline void vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginRenderPass);
	Kodiak::g_dispatcher.vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
inline void vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindDescriptorSets);
	Kodiak::g_dispatcher.vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
inline void vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindIndexBuffer);
	Kodiak::g_dispatcher.vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
inline void vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindPipeline);
	Kodiak::g_dispatcher.vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}
inline void vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindVertexBuffers);
	Kodiak::g_dispatcher.vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
inline void vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBlitImage);
	Kodiak::g_dispatcher.vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
inline void vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects)
{
	VALIDATE_FUNCTION_POINTER(vkCmdClearAttachments);
	Kodiak::g_dispatcher.vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
inline void vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
	VALIDATE_FUNCTION_POINTER(vkCmdClearColorImage);
	Kodiak::g_dispatcher.vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
inline void vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges)
{
	VALIDATE_FUNCTION_POINTER(vkCmdClearDepthStencilImage);
	Kodiak::g_dispatcher.vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
inline void vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyBuffer);
	Kodiak::g_dispatcher.vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
inline void vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyBufferToImage);
	Kodiak::g_dispatcher.vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
inline void vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyImage);
	Kodiak::g_dispatcher.vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
inline void vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyImageToBuffer);
	Kodiak::g_dispatcher.vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
inline void vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyQueryPoolResults);
	Kodiak::g_dispatcher.vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
inline void vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDispatch);
	Kodiak::g_dispatcher.vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
inline void vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDispatchIndirect);
	Kodiak::g_dispatcher.vkCmdDispatchIndirect(commandBuffer, buffer, offset);
}
inline void vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDraw);
	Kodiak::g_dispatcher.vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
inline void vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawIndexed);
	Kodiak::g_dispatcher.vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
inline void vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawIndexedIndirect);
	Kodiak::g_dispatcher.vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
inline void vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawIndirect);
	Kodiak::g_dispatcher.vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
inline void vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndQuery);
	Kodiak::g_dispatcher.vkCmdEndQuery(commandBuffer, queryPool, query);
}
inline void vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndRenderPass);
	Kodiak::g_dispatcher.vkCmdEndRenderPass(commandBuffer);
}
inline void vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
	VALIDATE_FUNCTION_POINTER(vkCmdExecuteCommands);
	Kodiak::g_dispatcher.vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
inline void vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
	VALIDATE_FUNCTION_POINTER(vkCmdFillBuffer);
	Kodiak::g_dispatcher.vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
inline void vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
{
	VALIDATE_FUNCTION_POINTER(vkCmdNextSubpass);
	Kodiak::g_dispatcher.vkCmdNextSubpass(commandBuffer, contents);
}
inline void vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
	VALIDATE_FUNCTION_POINTER(vkCmdPipelineBarrier);
	Kodiak::g_dispatcher.vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
inline void vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues)
{
	VALIDATE_FUNCTION_POINTER(vkCmdPushConstants);
	Kodiak::g_dispatcher.vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
inline void vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
	VALIDATE_FUNCTION_POINTER(vkCmdResetEvent);
	Kodiak::g_dispatcher.vkCmdResetEvent(commandBuffer, event, stageMask);
}
inline void vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
	VALIDATE_FUNCTION_POINTER(vkCmdResetQueryPool);
	Kodiak::g_dispatcher.vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
inline void vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions)
{
	VALIDATE_FUNCTION_POINTER(vkCmdResolveImage);
	Kodiak::g_dispatcher.vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
inline void vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4])
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetBlendConstants);
	Kodiak::g_dispatcher.vkCmdSetBlendConstants(commandBuffer, blendConstants);
}
inline void vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDepthBias);
	Kodiak::g_dispatcher.vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
inline void vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDepthBounds);
	Kodiak::g_dispatcher.vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
inline void vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetEvent);
	Kodiak::g_dispatcher.vkCmdSetEvent(commandBuffer, event, stageMask);
}
inline void vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetLineWidth);
	Kodiak::g_dispatcher.vkCmdSetLineWidth(commandBuffer, lineWidth);
}
inline void vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetScissor);
	Kodiak::g_dispatcher.vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
inline void vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetStencilCompareMask);
	Kodiak::g_dispatcher.vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
inline void vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetStencilReference);
	Kodiak::g_dispatcher.vkCmdSetStencilReference(commandBuffer, faceMask, reference);
}
inline void vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetStencilWriteMask);
	Kodiak::g_dispatcher.vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
inline void vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetViewport);
	Kodiak::g_dispatcher.vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
inline void vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkCmdUpdateBuffer);
	Kodiak::g_dispatcher.vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
inline void vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
	VALIDATE_FUNCTION_POINTER(vkCmdWaitEvents);
	Kodiak::g_dispatcher.vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
inline void vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
{
	VALIDATE_FUNCTION_POINTER(vkCmdWriteTimestamp);
	Kodiak::g_dispatcher.vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
inline KODIAK_NODISCARD VkResult vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
{
	VALIDATE_FUNCTION_POINTER(vkCreateBuffer);
	return Kodiak::g_dispatcher.vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}
inline KODIAK_NODISCARD VkResult vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView)
{
	VALIDATE_FUNCTION_POINTER(vkCreateBufferView);
	return Kodiak::g_dispatcher.vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
}
inline KODIAK_NODISCARD VkResult vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool)
{
	VALIDATE_FUNCTION_POINTER(vkCreateCommandPool);
	return Kodiak::g_dispatcher.vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}
inline KODIAK_NODISCARD VkResult vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
	VALIDATE_FUNCTION_POINTER(vkCreateComputePipelines);
	return Kodiak::g_dispatcher.vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
inline KODIAK_NODISCARD VkResult vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDescriptorPool);
	return Kodiak::g_dispatcher.vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}
inline KODIAK_NODISCARD VkResult vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDescriptorSetLayout);
	return Kodiak::g_dispatcher.vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}
inline KODIAK_NODISCARD VkResult vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
{
	VALIDATE_FUNCTION_POINTER(vkCreateEvent);
	return Kodiak::g_dispatcher.vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
}
inline KODIAK_NODISCARD VkResult vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
	VALIDATE_FUNCTION_POINTER(vkCreateFence);
	return Kodiak::g_dispatcher.vkCreateFence(device, pCreateInfo, pAllocator, pFence);
}
inline KODIAK_NODISCARD VkResult vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
{
	VALIDATE_FUNCTION_POINTER(vkCreateFramebuffer);
	return Kodiak::g_dispatcher.vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}
inline KODIAK_NODISCARD VkResult vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
	VALIDATE_FUNCTION_POINTER(vkCreateGraphicsPipelines);
	return Kodiak::g_dispatcher.vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
inline KODIAK_NODISCARD VkResult vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage)
{
	VALIDATE_FUNCTION_POINTER(vkCreateImage);
	return Kodiak::g_dispatcher.vkCreateImage(device, pCreateInfo, pAllocator, pImage);
}
inline KODIAK_NODISCARD VkResult vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView)
{
	VALIDATE_FUNCTION_POINTER(vkCreateImageView);
	return Kodiak::g_dispatcher.vkCreateImageView(device, pCreateInfo, pAllocator, pView);
}
inline KODIAK_NODISCARD VkResult vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache)
{
	VALIDATE_FUNCTION_POINTER(vkCreatePipelineCache);
	return Kodiak::g_dispatcher.vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
}
inline KODIAK_NODISCARD VkResult vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout)
{
	VALIDATE_FUNCTION_POINTER(vkCreatePipelineLayout);
	return Kodiak::g_dispatcher.vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}
inline KODIAK_NODISCARD VkResult vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
{
	VALIDATE_FUNCTION_POINTER(vkCreateQueryPool);
	return Kodiak::g_dispatcher.vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
}
inline KODIAK_NODISCARD VkResult vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
	VALIDATE_FUNCTION_POINTER(vkCreateRenderPass);
	return Kodiak::g_dispatcher.vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}
inline KODIAK_NODISCARD VkResult vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler)
{
	VALIDATE_FUNCTION_POINTER(vkCreateSampler);
	return Kodiak::g_dispatcher.vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
}
inline KODIAK_NODISCARD VkResult vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
{
	VALIDATE_FUNCTION_POINTER(vkCreateSemaphore);
	return Kodiak::g_dispatcher.vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
}
inline KODIAK_NODISCARD VkResult vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule)
{
	VALIDATE_FUNCTION_POINTER(vkCreateShaderModule);
	return Kodiak::g_dispatcher.vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}
inline void vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyBuffer);
	Kodiak::g_dispatcher.vkDestroyBuffer(device, buffer, pAllocator);
}
inline void vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyBufferView);
	Kodiak::g_dispatcher.vkDestroyBufferView(device, bufferView, pAllocator);
}
inline void vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyCommandPool);
	Kodiak::g_dispatcher.vkDestroyCommandPool(device, commandPool, pAllocator);
}
inline void vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyDescriptorPool);
	Kodiak::g_dispatcher.vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
}
inline void vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyDescriptorSetLayout);
	Kodiak::g_dispatcher.vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}
inline void vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyDevice);
	Kodiak::g_dispatcher.vkDestroyDevice(device, pAllocator);
}
inline void vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyEvent);
	Kodiak::g_dispatcher.vkDestroyEvent(device, event, pAllocator);
}
inline void vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyFence);
	Kodiak::g_dispatcher.vkDestroyFence(device, fence, pAllocator);
}
inline void vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyFramebuffer);
	Kodiak::g_dispatcher.vkDestroyFramebuffer(device, framebuffer, pAllocator);
}
inline void vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyImage);
	Kodiak::g_dispatcher.vkDestroyImage(device, image, pAllocator);
}
inline void vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyImageView);
	Kodiak::g_dispatcher.vkDestroyImageView(device, imageView, pAllocator);
}
inline void vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyPipeline);
	Kodiak::g_dispatcher.vkDestroyPipeline(device, pipeline, pAllocator);
}
inline void vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyPipelineCache);
	Kodiak::g_dispatcher.vkDestroyPipelineCache(device, pipelineCache, pAllocator);
}
inline void vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyPipelineLayout);
	Kodiak::g_dispatcher.vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
}
inline void vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyQueryPool);
	Kodiak::g_dispatcher.vkDestroyQueryPool(device, queryPool, pAllocator);
}
inline void vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyRenderPass);
	Kodiak::g_dispatcher.vkDestroyRenderPass(device, renderPass, pAllocator);
}
inline void vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroySampler);
	Kodiak::g_dispatcher.vkDestroySampler(device, sampler, pAllocator);
}
inline void vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroySemaphore);
	Kodiak::g_dispatcher.vkDestroySemaphore(device, semaphore, pAllocator);
}
inline void vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyShaderModule);
	Kodiak::g_dispatcher.vkDestroyShaderModule(device, shaderModule, pAllocator);
}
inline KODIAK_NODISCARD VkResult vkDeviceWaitIdle(VkDevice device)
{
	VALIDATE_FUNCTION_POINTER(vkDeviceWaitIdle);
	return Kodiak::g_dispatcher.vkDeviceWaitIdle(device);
}
inline KODIAK_NODISCARD VkResult vkEndCommandBuffer(VkCommandBuffer commandBuffer)
{
	VALIDATE_FUNCTION_POINTER(vkEndCommandBuffer);
	return Kodiak::g_dispatcher.vkEndCommandBuffer(commandBuffer);
}
inline KODIAK_NODISCARD VkResult vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
	VALIDATE_FUNCTION_POINTER(vkFlushMappedMemoryRanges);
	return Kodiak::g_dispatcher.vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}
inline void vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
	VALIDATE_FUNCTION_POINTER(vkFreeCommandBuffers);
	Kodiak::g_dispatcher.vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}
inline KODIAK_NODISCARD VkResult vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
	VALIDATE_FUNCTION_POINTER(vkFreeDescriptorSets);
	Kodiak::g_dispatcher.vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}
inline void vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkFreeMemory);
	Kodiak::g_dispatcher.vkFreeMemory(device, memory, pAllocator);
}
inline void vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetBufferMemoryRequirements);
	Kodiak::g_dispatcher.vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}
inline void vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceMemoryCommitment);
	Kodiak::g_dispatcher.vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}
inline void vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceQueue);
	Kodiak::g_dispatcher.vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}
inline KODIAK_NODISCARD VkResult vkGetEventStatus(VkDevice device, VkEvent event)
{
	VALIDATE_FUNCTION_POINTER(vkGetEventStatus);
	return Kodiak::g_dispatcher.vkGetEventStatus(device, event);
}
inline KODIAK_NODISCARD VkResult vkGetFenceStatus(VkDevice device, VkFence fence)
{
	VALIDATE_FUNCTION_POINTER(vkGetEventStatus);
	return Kodiak::g_dispatcher.vkGetFenceStatus(device, fence);
}
inline void vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageMemoryRequirements);
	Kodiak::g_dispatcher.vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
}
inline void vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageSparseMemoryRequirements);
	Kodiak::g_dispatcher.vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
inline void vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageSubresourceLayout);
	Kodiak::g_dispatcher.vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
}
inline KODIAK_NODISCARD VkResult vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkGetPipelineCacheData);
	return Kodiak::g_dispatcher.vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
}
inline KODIAK_NODISCARD VkResult vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkGetQueryPoolResults);
	return Kodiak::g_dispatcher.vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}
inline void vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity)
{
	VALIDATE_FUNCTION_POINTER(vkGetRenderAreaGranularity);
	Kodiak::g_dispatcher.vkGetRenderAreaGranularity(device, renderPass, pGranularity);
}
inline KODIAK_NODISCARD VkResult vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
	VALIDATE_FUNCTION_POINTER(vkInvalidateMappedMemoryRanges);
	return Kodiak::g_dispatcher.vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}
inline KODIAK_NODISCARD VkResult vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{
	VALIDATE_FUNCTION_POINTER(vkMapMemory);
	return Kodiak::g_dispatcher.vkMapMemory(device, memory, offset, size, flags, ppData);
}
inline KODIAK_NODISCARD VkResult vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches)
{
	VALIDATE_FUNCTION_POINTER(vkMergePipelineCaches);
	return Kodiak::g_dispatcher.vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
}
inline KODIAK_NODISCARD VkResult vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence)
{
	VALIDATE_FUNCTION_POINTER(vkQueueBindSparse);
	return Kodiak::g_dispatcher.vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}
inline KODIAK_NODISCARD VkResult vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
{
	VALIDATE_FUNCTION_POINTER(vkQueueSubmit);
	return Kodiak::g_dispatcher.vkQueueSubmit(queue, submitCount, pSubmits, fence);
}
inline KODIAK_NODISCARD VkResult vkQueueWaitIdle(VkQueue queue)
{
	VALIDATE_FUNCTION_POINTER(vkQueueWaitIdle);
	return Kodiak::g_dispatcher.vkQueueWaitIdle(queue);
}
inline KODIAK_NODISCARD VkResult vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkResetCommandBuffer);
	return Kodiak::g_dispatcher.vkResetCommandBuffer(commandBuffer, flags);
}
inline KODIAK_NODISCARD VkResult vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkResetCommandPool);
	return Kodiak::g_dispatcher.vkResetCommandPool(device, commandPool, flags);
}
inline KODIAK_NODISCARD VkResult vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkResetDescriptorPool);
	return Kodiak::g_dispatcher.vkResetDescriptorPool(device, descriptorPool, flags);
}
inline KODIAK_NODISCARD VkResult vkResetEvent(VkDevice device, VkEvent event)
{
	VALIDATE_FUNCTION_POINTER(vkResetEvent);
	return Kodiak::g_dispatcher.vkResetEvent(device, event);
}
inline KODIAK_NODISCARD VkResult vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences)
{
	VALIDATE_FUNCTION_POINTER(vkResetFences);
	return Kodiak::g_dispatcher.vkResetFences(device, fenceCount, pFences);
}
inline KODIAK_NODISCARD VkResult vkSetEvent(VkDevice device, VkEvent event)
{
	VALIDATE_FUNCTION_POINTER(vkSetEvent);
	return Kodiak::g_dispatcher.vkSetEvent(device, event);
}
inline void vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
	VALIDATE_FUNCTION_POINTER(vkUnmapMemory);
	Kodiak::g_dispatcher.vkUnmapMemory(device, memory);
}
inline void vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies)
{
	VALIDATE_FUNCTION_POINTER(vkUpdateDescriptorSets);
	Kodiak::g_dispatcher.vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}
inline KODIAK_NODISCARD VkResult vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
	VALIDATE_FUNCTION_POINTER(vkWaitForFences);
	return Kodiak::g_dispatcher.vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}


// Vulkan 1.1 device functions
inline KODIAK_NODISCARD VkResult vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos)
{
	VALIDATE_FUNCTION_POINTER(vkBindBufferMemory2);
	return Kodiak::g_dispatcher.vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
}
inline KODIAK_NODISCARD VkResult vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos)
{
	VALIDATE_FUNCTION_POINTER(vkBindImageMemory2);
	return Kodiak::g_dispatcher.vkBindImageMemory2(device, bindInfoCount, pBindInfos);
}
inline KODIAK_NODISCARD VkResult vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDescriptorUpdateTemplate);
	return Kodiak::g_dispatcher.vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}
inline KODIAK_NODISCARD VkResult vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion)
{
	VALIDATE_FUNCTION_POINTER(vkCreateSamplerYcbcrConversion);
	return Kodiak::g_dispatcher.vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
}
inline void vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyDescriptorUpdateTemplate);
	Kodiak::g_dispatcher.vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
}
inline void vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroySamplerYcbcrConversion);
	Kodiak::g_dispatcher.vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
}
inline void vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetBufferMemoryRequirements2);
	Kodiak::g_dispatcher.vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
inline void vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport)
{
	VALIDATE_FUNCTION_POINTER(vkGetDescriptorSetLayoutSupport);
	Kodiak::g_dispatcher.vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
}
inline void vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceGroupPeerMemoryFeatures);
	Kodiak::g_dispatcher.vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
inline void vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceQueue2);
	Kodiak::g_dispatcher.vkGetDeviceQueue2(device, pQueueInfo, pQueue);
}
inline void vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageMemoryRequirements2);
	Kodiak::g_dispatcher.vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
inline void vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageSparseMemoryRequirements2);
	Kodiak::g_dispatcher.vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
inline void vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
	VALIDATE_FUNCTION_POINTER(vkTrimCommandPool);
	Kodiak::g_dispatcher.vkTrimCommandPool(device, commandPool, flags);
}
inline void vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkUpdateDescriptorSetWithTemplate);
	Kodiak::g_dispatcher.vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
}


// Vulkan 1.2 device functions
inline void vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginRenderPass2);
	Kodiak::g_dispatcher.vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
inline void vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawIndexedIndirectCount);
	Kodiak::g_dispatcher.vkCmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
inline void vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawIndirectCount);
	Kodiak::g_dispatcher.vkCmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
inline void vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndRenderPass2);
	Kodiak::g_dispatcher.vkCmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
inline void vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdNextSubpass2);
	Kodiak::g_dispatcher.vkCmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
inline KODIAK_NODISCARD VkResult vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{
	VALIDATE_FUNCTION_POINTER(vkCreateRenderPass2);
	return Kodiak::g_dispatcher.vkCreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
}
inline KODIAK_NODISCARD VkDeviceAddress vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
	VALIDATE_FUNCTION_POINTER(vkGetBufferDeviceAddress);
	return Kodiak::g_dispatcher.vkGetBufferDeviceAddress(device, pInfo);
}
inline KODIAK_NODISCARD uint64_t vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo)
{
	VALIDATE_FUNCTION_POINTER(vkGetBufferOpaqueCaptureAddress);
	return Kodiak::g_dispatcher.vkGetBufferOpaqueCaptureAddress(device, pInfo);
}
inline KODIAK_NODISCARD uint64_t vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceMemoryOpaqueCaptureAddress);
	return Kodiak::g_dispatcher.vkGetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
}
inline KODIAK_NODISCARD VkResult vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue)
{
	VALIDATE_FUNCTION_POINTER(vkGetSemaphoreCounterValue);
	return Kodiak::g_dispatcher.vkGetSemaphoreCounterValue(device, semaphore, pValue);
}
inline void vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
	VALIDATE_FUNCTION_POINTER(vkResetQueryPool);
	Kodiak::g_dispatcher.vkResetQueryPool(device, queryPool, firstQuery, queryCount);
}
inline KODIAK_NODISCARD VkResult vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo)
{
	VALIDATE_FUNCTION_POINTER(vkSignalSemaphore);
	return Kodiak::g_dispatcher.vkSignalSemaphore(device, pSignalInfo);
}
inline KODIAK_NODISCARD VkResult vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout)
{
	VALIDATE_FUNCTION_POINTER(vkWaitSemaphores);
	return Kodiak::g_dispatcher.vkWaitSemaphores(device, pWaitInfo, timeout);
}


// VK_KHR_android_surface
#ifdef VK_USE_PLATFORM_ANDROID_KHR
inline KODIAK_NODISCARD VkResult vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateAndroidSurfaceKHR);
	return Kodiak::g_dispatcher.vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
#endif

// VK_KHR_copy_commands2
inline void vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBlitImage2KHR);
	Kodiak::g_dispatcher.vkCmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
inline void vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyBuffer2KHR);
	Kodiak::g_dispatcher.vkCmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
inline void vkCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyBufferToImage2KHR);
	Kodiak::g_dispatcher.vkCmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
inline void vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyImage2KHR);
	Kodiak::g_dispatcher.vkCmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
inline void vkCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyImageToBuffer2KHR);
	Kodiak::g_dispatcher.vkCmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
inline void vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdResolveImage2KHR);
	Kodiak::g_dispatcher.vkCmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}


// VK_KHR_display
inline KODIAK_NODISCARD VkResult vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDisplayModeKHR);
	return Kodiak::g_dispatcher.vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
}
inline KODIAK_NODISCARD VkResult vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDisplayPlaneSurfaceKHR);
	return Kodiak::g_dispatcher.vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
inline KODIAK_NODISCARD VkResult vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetDisplayModePropertiesKHR);
	return Kodiak::g_dispatcher.vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
}
inline KODIAK_NODISCARD VkResult vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities)
{
	VALIDATE_FUNCTION_POINTER(vkGetDisplayPlaneCapabilitiesKHR);
	return Kodiak::g_dispatcher.vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
}
inline KODIAK_NODISCARD VkResult vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays)
{
	VALIDATE_FUNCTION_POINTER(vkGetDisplayPlaneSupportedDisplaysKHR);
	return Kodiak::g_dispatcher.vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceDisplayPropertiesKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}


// VK_KHR_display_swapchain
inline KODIAK_NODISCARD VkResult vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains)
{
	VALIDATE_FUNCTION_POINTER(vkCreateSharedSwapchainsKHR);
	return Kodiak::g_dispatcher.vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
}


// VK_KHR_external_fence_fd
inline KODIAK_NODISCARD VkResult vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd)
{
	VALIDATE_FUNCTION_POINTER(vkGetFenceFdKHR);
	return Kodiak::g_dispatcher.vkGetFenceFdKHR(device, pGetFdInfo, pFd);
}
inline KODIAK_NODISCARD VkResult vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo)
{
	VALIDATE_FUNCTION_POINTER(vkImportFenceFdKHR);
	return Kodiak::g_dispatcher.vkImportFenceFdKHR(device, pImportFenceFdInfo);
}


// VK_KHR_external_fence_win32
#ifdef VK_USE_PLATFORM_WIN32_KHR
inline KODIAK_NODISCARD VkResult vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
	VALIDATE_FUNCTION_POINTER(vkGetFenceWin32HandleKHR);
	return Kodiak::g_dispatcher.vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}
inline KODIAK_NODISCARD VkResult vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo)
{
	VALIDATE_FUNCTION_POINTER(vkImportFenceWin32HandleKHR);
	return Kodiak::g_dispatcher.vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
}
#endif


// VK_KHR_external_memory_fd
inline KODIAK_NODISCARD VkResult vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd)
{
	VALIDATE_FUNCTION_POINTER(vkGetMemoryFdKHR);
	return Kodiak::g_dispatcher.vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
}
inline KODIAK_NODISCARD VkResult vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetMemoryFdPropertiesKHR);
	return Kodiak::g_dispatcher.vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
}

// VK_KHR_external_memory_win32
#ifdef VK_USE_PLATFORM_WIN32_KHR
inline KODIAK_NODISCARD VkResult vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
	VALIDATE_FUNCTION_POINTER(vkGetMemoryWin32HandleKHR);
	return Kodiak::g_dispatcher.vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}
inline KODIAK_NODISCARD VkResult vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetMemoryWin32HandlePropertiesKHR);
	return Kodiak::g_dispatcher.vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
}
#endif


// VK_KHR_external_semaphore_fd
inline KODIAK_NODISCARD VkResult vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd)
{
	VALIDATE_FUNCTION_POINTER(vkGetSemaphoreFdKHR);
	return Kodiak::g_dispatcher.vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
}
inline KODIAK_NODISCARD VkResult vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo)
{
	VALIDATE_FUNCTION_POINTER(vkImportSemaphoreFdKHR);
	return Kodiak::g_dispatcher.vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
}


// VK_KHR_external_semaphore_win32
#ifdef VK_USE_PLATFORM_WIN32_KHR
inline KODIAK_NODISCARD VkResult vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle)
{
	VALIDATE_FUNCTION_POINTER(vkGetSemaphoreWin32HandleKHR);
	return Kodiak::g_dispatcher.vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}
inline KODIAK_NODISCARD VkResult vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo)
{
	VALIDATE_FUNCTION_POINTER(vkImportSemaphoreWin32HandleKHR);
	return Kodiak::g_dispatcher.vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
}
#endif


// VK_KHR_get_display_properties2
inline KODIAK_NODISCARD VkResult vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetDisplayModeProperties2KHR);
	return Kodiak::g_dispatcher.vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
}
inline KODIAK_NODISCARD VkResult vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities)
{
	VALIDATE_FUNCTION_POINTER(vkGetDisplayPlaneCapabilities2KHR);
	return Kodiak::g_dispatcher.vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
}


// VK_KHR_get_surface_capabilities2
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfaceFormats2KHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
}


// VK_KHR_performance_query
inline KODIAK_NODISCARD VkResult vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo)
{
	VALIDATE_FUNCTION_POINTER(vkAcquireProfilingLockKHR);
	return Kodiak::g_dispatcher.vkAcquireProfilingLockKHR(device, pInfo);
}
inline KODIAK_NODISCARD VkResult vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions)
{
	VALIDATE_FUNCTION_POINTER(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
	return Kodiak::g_dispatcher.vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
}
inline void vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}
inline void vkReleaseProfilingLockKHR(VkDevice device)
{
	VALIDATE_FUNCTION_POINTER(vkReleaseProfilingLockKHR);
	Kodiak::g_dispatcher.vkReleaseProfilingLockKHR(device);
}


// VK_KHR_pipeline_executable_properties
inline KODIAK_NODISCARD VkResult vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations)
{
	VALIDATE_FUNCTION_POINTER(vkGetPipelineExecutableInternalRepresentationsKHR);
	return Kodiak::g_dispatcher.vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
}
inline KODIAK_NODISCARD VkResult vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPipelineExecutablePropertiesKHR);
	return Kodiak::g_dispatcher.vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
}
inline KODIAK_NODISCARD VkResult vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics)
{
	VALIDATE_FUNCTION_POINTER(vkGetPipelineExecutableStatisticsKHR);
	return Kodiak::g_dispatcher.vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
}


// VK_KHR_push_descriptor
inline void vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites)
{
	VALIDATE_FUNCTION_POINTER(vkCmdPushDescriptorSetKHR);
	Kodiak::g_dispatcher.vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
inline void vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkCmdPushDescriptorSetWithTemplateKHR);
	Kodiak::g_dispatcher.vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}


// VK_KHR_shared_presentable_image
inline KODIAK_NODISCARD VkResult vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain)
{
	VALIDATE_FUNCTION_POINTER(vkGetSwapchainStatusKHR);
	Kodiak::g_dispatcher.vkGetSwapchainStatusKHR(device, swapchain);
}


// VK_KHR_surface
inline void vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroySurfaceKHR);
	Kodiak::g_dispatcher.vkDestroySurfaceKHR(instance, surface, pAllocator);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfaceFormatsKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfacePresentModesKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfaceSupportKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
}


// VK_KHR_swapchain
inline KODIAK_NODISCARD VkResult vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
{
	VALIDATE_FUNCTION_POINTER(vkAcquireNextImageKHR);
	return Kodiak::g_dispatcher.vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
}
inline KODIAK_NODISCARD VkResult vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
{
	VALIDATE_FUNCTION_POINTER(vkCreateSwapchainKHR);
	return Kodiak::g_dispatcher.vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
}
inline void vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroySwapchainKHR);
	Kodiak::g_dispatcher.vkDestroySwapchainKHR(device, swapchain, pAllocator);
}
inline KODIAK_NODISCARD VkResult vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
{
	VALIDATE_FUNCTION_POINTER(vkGetSwapchainImagesKHR);
	return Kodiak::g_dispatcher.vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
}
inline KODIAK_NODISCARD VkResult vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
{
	VALIDATE_FUNCTION_POINTER(vkQueuePresentKHR);
	return Kodiak::g_dispatcher.vkQueuePresentKHR(queue, pPresentInfo);
}


#ifdef VK_USE_PLATFORM_WAYLAND_KHR
// VK_KHR_wayland_surface
inline KODIAK_NODISCARD VkResult vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateWaylandSurfaceKHR);
	return Kodiak::g_dispatcher.vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
inline KODIAK_NODISCARD VkBool32 vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
	return Kodiak::g_dispathcer.vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
}
#endif


#ifdef VK_USE_PLATFORM_WIN32_KHR
// VK_KHR_win32_surface
inline KODIAK_NODISCARD VkResult vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateWin32SurfaceKHR);
	return Kodiak::g_dispatcher.vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
inline KODIAK_NODISCARD VkBool32 vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceWin32PresentationSupportKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
}
#endif


#ifdef VK_USE_PLATFORM_XCB_KHR
// VK_KHR_xcb_surface
inline KODIAK_NODISCARD VkResult vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateXcbSurfaceKHR);
	return Kodiak::g_dispatcher.vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
inline KODIAK_NODISCARD VkBool32 vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceXcbPresentationSupportKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
}
#endif


#ifdef VK_USE_PLATFORM_XLIB_KHR
// VK_KHR_xlib_surface
inline KODIAK_NODISCARD VkResult vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateXlibSurfaceKHR);
	return Kodiak::g_dispatcher.vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}
inline KODIAK_NODISCARD VkBool32 vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceXlibPresentationSupportKHR);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
}
#endif


#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
// VK_EXT_acquire_xlib_display
inline KODIAK_NODISCARD VkResult vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display)
{
	VALIDATE_FUNCTION_POINTER(vkAcquireXlibDisplayEXT);
	return Kodiak::g_dispatcher.vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
}
inline KODIAK_NODISCARD VkResult vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay)
{
	VALIDATE_FUNCTION_POINTER(vkGetRandROutputDisplayEXT);
	return Kodiak::g_dispatcher.vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
}
#endif


// VK_EXT_calibrated_timestamps
inline KODIAK_NODISCARD VkResult vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation)
{
	VALIDATE_FUNCTION_POINTER(vkGetCalibratedTimestampsEXT);
	return Kodiak::g_dispatcher.vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainEXT* pTimeDomains)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
}


// VK_EXT_conditional_rendering
inline void vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginConditionalRenderingEXT);
	Kodiak::g_dispatcher.vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
inline void vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndConditionalRenderingEXT);
	Kodiak::g_dispatcher.vkCmdEndConditionalRenderingEXT(commandBuffer);
}


// VK_EXT_debug_utils
inline void vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginDebugUtilsLabelEXT);
	Kodiak::g_dispatcher.vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
inline void vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndDebugUtilsLabelEXT);
	Kodiak::g_dispatcher.vkCmdEndDebugUtilsLabelEXT(commandBuffer);
}
inline void vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdInsertDebugUtilsLabelEXT);
	Kodiak::g_dispatcher.vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
inline KODIAK_NODISCARD VkResult vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDebugUtilsMessengerEXT);
	return Kodiak::g_dispatcher.vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
}
inline void vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyDebugUtilsMessengerEXT);
	Kodiak::g_dispatcher.vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
}
inline void vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)
{
	VALIDATE_FUNCTION_POINTER(vkQueueBeginDebugUtilsLabelEXT);
	Kodiak::g_dispatcher.vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
}
inline void vkQueueEndDebugUtilsLabelEXT(VkQueue queue)
{
	VALIDATE_FUNCTION_POINTER(vkQueueEndDebugUtilsLabelEXT);
	Kodiak::g_dispatcher.vkQueueEndDebugUtilsLabelEXT(queue);
}
inline void vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo)
{
	VALIDATE_FUNCTION_POINTER(vkQueueInsertDebugUtilsLabelEXT);
	Kodiak::g_dispatcher.vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
}
inline KODIAK_NODISCARD VkResult vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo)
{
	VALIDATE_FUNCTION_POINTER(vkSetDebugUtilsObjectNameEXT);
	return Kodiak::g_dispatcher.vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
}
inline KODIAK_NODISCARD VkResult vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo)
{
	VALIDATE_FUNCTION_POINTER(vkSetDebugUtilsObjectTagEXT);
	return Kodiak::g_dispatcher.vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
}
inline void vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
	VALIDATE_FUNCTION_POINTER(vkSubmitDebugUtilsMessageEXT);
	Kodiak::g_dispatcher.vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
}


// VK_EXT_direct_mode_display
inline KODIAK_NODISCARD VkResult vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
	VALIDATE_FUNCTION_POINTER(vkReleaseDisplayEXT);
	return Kodiak::g_dispatcher.vkReleaseDisplayEXT(physicalDevice, display);
}


#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
// VK_EXT_directfb_surface
inline KODIAK_NODISCARD VkResult vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateDirectFBSurfaceEXT);
	return Kodiak::g_dispatcher.vkCreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
}
#endif

// VK_EXT_discard_rectangles
inline void vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDiscardRectangleEXT);
	Kodiak::g_dispatcher.vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}


// VK_EXT_display_control
inline KODIAK_NODISCARD VkResult vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo)
{
	VALIDATE_FUNCTION_POINTER(vkDisplayPowerControlEXT);
	return Kodiak::g_dispatcher.vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
}
inline KODIAK_NODISCARD VkResult vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue)
{
	VALIDATE_FUNCTION_POINTER(vkGetSwapchainCounterEXT);
	return Kodiak::g_dispatcher.vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
}
inline KODIAK_NODISCARD VkResult vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
	VALIDATE_FUNCTION_POINTER(vkRegisterDeviceEventEXT);
	return Kodiak::g_dispatcher.vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
}
inline KODIAK_NODISCARD VkResult vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence)
{
	VALIDATE_FUNCTION_POINTER(vkRegisterDisplayEventEXT);
	return Kodiak::g_dispatcher.vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
}


// VK_EXT_display_surface_counter
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfaceCapabilities2EXT);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
}


// VK_EXT_extended_dynamic_state
inline void vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindVertexBuffers2EXT);
	Kodiak::g_dispatcher.vkCmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
inline void vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetCullModeEXT);
	Kodiak::g_dispatcher.vkCmdSetCullModeEXT(commandBuffer, cullMode);
}
inline void vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDepthBoundsTestEnableEXT);
	Kodiak::g_dispatcher.vkCmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
inline void vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDepthCompareOpEXT);
	Kodiak::g_dispatcher.vkCmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
inline void vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDepthTestEnableEXT);
	Kodiak::g_dispatcher.vkCmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
inline void vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetDepthWriteEnableEXT);
	Kodiak::g_dispatcher.vkCmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
inline void vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetFrontFaceEXT);
	Kodiak::g_dispatcher.vkCmdSetFrontFaceEXT(commandBuffer, frontFace);
}
inline void vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetPrimitiveTopologyEXT);
	Kodiak::g_dispatcher.vkCmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
inline void vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetScissorWithCountEXT);
	Kodiak::g_dispatcher.vkCmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
inline void vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetStencilOpEXT);
	Kodiak::g_dispatcher.vkCmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
inline void vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetStencilTestEnableEXT);
	Kodiak::g_dispatcher.vkCmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
inline void vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetViewportWithCountEXT);
	Kodiak::g_dispatcher.vkCmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}


// VK_EXT_external_memory_host
inline KODIAK_NODISCARD VkResult vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetMemoryHostPointerPropertiesEXT);
	return Kodiak::g_dispatcher.vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
}


// VK_EXT_full_screen_exclusive
#ifdef VK_USE_PLATFORM_WIN32_KHR
inline KODIAK_NODISCARD VkResult vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain)
{
	VALIDATE_FUNCTION_POINTER(vkAcquireFullScreenExclusiveModeEXT);
	return Kodiak::g_dispatcher.vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
}
inline KODIAK_NODISCARD VkResult vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes)
{
	VALIDATE_FUNCTION_POINTER(vkGetDeviceGroupSurfacePresentModes2EXT);
	return Kodiak::g_dispatcher.vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
}
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSurfacePresentModes2EXT);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
}
inline KODIAK_NODISCARD VkResult vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain)
{
	VALIDATE_FUNCTION_POINTER(vkReleaseFullScreenExclusiveModeEXT);
	return Kodiak::g_dispatcher.vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
}
#endif


// VK_EXT_hdr_metadata
inline void vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata)
{
	VALIDATE_FUNCTION_POINTER(vkSetHdrMetadataEXT);
	Kodiak::g_dispatcher.vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
}


// VK_EXT_headless_surface
inline KODIAK_NODISCARD VkResult vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateHeadlessSurfaceEXT);
	return Kodiak::g_dispatcher.vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}

// VK_EXT_image_drm_format_modifier
inline KODIAK_NODISCARD VkResult vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageDrmFormatModifierPropertiesEXT);
	return Kodiak::g_dispatcher.vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
}


// VK_EXT_line_rasterization
inline void vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetLineStippleEXT);
	Kodiak::g_dispatcher.vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}


#ifdef VK_USE_PLATFORM_METAL_EXT
// VK_EXT_metal_surface
inline KODIAK_NODISCARD VkResult vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateMetalSurfaceEXT);
	return Kodiak::g_dispatcher.vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}
#endif


// VK_EXT_private_data
inline KODIAK_NODISCARD VkResult vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlotEXT* pPrivateDataSlot)
{
	VALIDATE_FUNCTION_POINTER(vkCreatePrivateDataSlotEXT);
	return Kodiak::g_dispatcher.vkCreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
}
inline void vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlotEXT privateDataSlot, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyPrivateDataSlotEXT);
	Kodiak::g_dispatcher.vkDestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
}
inline void vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t* pData)
{
	VALIDATE_FUNCTION_POINTER(vkGetPrivateDataEXT);
	Kodiak::g_dispatcher.vkGetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
}
inline KODIAK_NODISCARD VkResult vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlotEXT privateDataSlot, uint64_t data)
{
	VALIDATE_FUNCTION_POINTER(vkSetPrivateDataEXT);
	return Kodiak::g_dispatcher.vkSetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
}


// VK_EXT_sample_locations
inline void vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetSampleLocationsEXT);
	Kodiak::g_dispatcher.vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
inline void vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceMultisamplePropertiesEXT);
	Kodiak::g_dispatcher.vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
}


// VK_EXT_tooling_info
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceToolPropertiesEXT);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
}


// VK_EXT_transform_feedback
inline void vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginQueryIndexedEXT);
	Kodiak::g_dispatcher.vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
inline void vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBeginTransformFeedbackEXT);
	Kodiak::g_dispatcher.vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
inline void vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindTransformFeedbackBuffersEXT);
	Kodiak::g_dispatcher.vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
inline void vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawIndirectByteCountEXT);
	Kodiak::g_dispatcher.vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
inline void vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndQueryIndexedEXT);
	Kodiak::g_dispatcher.vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
inline void vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets)
{
	VALIDATE_FUNCTION_POINTER(vkCmdEndTransformFeedbackEXT);
	Kodiak::g_dispatcher.vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}


// VK_EXT_validation_cache
inline KODIAK_NODISCARD VkResult vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache)
{
	VALIDATE_FUNCTION_POINTER(vkCreateValidationCacheEXT);
	return Kodiak::g_dispatcher.vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
}
inline void vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyValidationCacheEXT);
	Kodiak::g_dispatcher.vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
}
inline KODIAK_NODISCARD VkResult vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkGetValidationCacheDataEXT);
	return Kodiak::g_dispatcher.vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
}
inline KODIAK_NODISCARD VkResult vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches)
{
	VALIDATE_FUNCTION_POINTER(vkMergeValidationCachesEXT);
	return Kodiak::g_dispatcher.vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
}


// VK_AMD_buffer_marker
inline void vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)
{
	VALIDATE_FUNCTION_POINTER(vkCmdWriteBufferMarkerAMD);
	Kodiak::g_dispatcher.vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}


// VK_AMD_display_native_hdr
inline void vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
	VALIDATE_FUNCTION_POINTER(vkSetLocalDimmingAMD);
	Kodiak::g_dispatcher.vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
}


// VK_AMD_shader_info
inline KODIAK_NODISCARD VkResult vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo)
{
	VALIDATE_FUNCTION_POINTER(vkGetShaderInfoAMD);
	return Kodiak::g_dispatcher.vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
}


#ifdef VK_USE_PLATFORM_ANDROID_KHR
// VK_ANDROID_external_memory_android_hardware_buffer
inline KODIAK_NODISCARD VkResult vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetAndroidHardwareBufferPropertiesANDROID);
	return Kodiak::g_dispatcher.vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
}
inline KODIAK_NODISCARD VkResult vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer)
{
	VALIDATE_FUNCTION_POINTER(vkGetMemoryAndroidHardwareBufferANDROID);
	return Kodiak::g_dispatcher.vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
}
#endif

#ifdef VK_USE_PLATFORM_FUSCHIA
// VK_FUSCHIA_imagepipe_surface
inline KODIAK_NODISCARD VkResult vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateImagePipeSurfaceFUCHSIA);
	return Kodiak::g_dispatcher.vkCreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
}
#endif

#ifdef VK_USE_PLATFORM_GGP
// VK_GGP_stream_descriptor_surface
inline KODIAK_NODISCARD VkResult vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateStreamDescriptorSurfaceGGP);
	return Kodiak::g_dispatcher.vkCreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
}
#endif


// VK_GOOGLE_display_timing
inline KODIAK_NODISCARD VkResult vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings)
{
	VALIDATE_FUNCTION_POINTER(vkGetPastPresentationTimingGOOGLE);
	return Kodiak::g_dispatcher.vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
}
inline KODIAK_NODISCARD VkResult vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetRefreshCycleDurationGOOGLE);
	return Kodiak::g_dispatcher.vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
}


// VK_INTEL_performance_query
inline KODIAK_NODISCARD VkResult vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration)
{
	VALIDATE_FUNCTION_POINTER(vkAcquirePerformanceConfigurationINTEL);
	return Kodiak::g_dispatcher.vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
}
inline KODIAK_NODISCARD VkResult vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetPerformanceMarkerINTEL);
	return Kodiak::g_dispatcher.vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
}
inline KODIAK_NODISCARD VkResult vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetPerformanceOverrideINTEL);
	return Kodiak::g_dispatcher.vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
}
inline KODIAK_NODISCARD VkResult vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetPerformanceStreamMarkerINTEL);
	return Kodiak::g_dispatcher.vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
}
inline KODIAK_NODISCARD VkResult vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue)
{
	VALIDATE_FUNCTION_POINTER(vkGetPerformanceParameterINTEL);
	return Kodiak::g_dispatcher.vkGetPerformanceParameterINTEL(device, parameter, pValue);
}
inline KODIAK_NODISCARD VkResult vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo)
{
	VALIDATE_FUNCTION_POINTER(vkInitializePerformanceApiINTEL);
	return Kodiak::g_dispatcher.vkInitializePerformanceApiINTEL(device, pInitializeInfo);
}
inline KODIAK_NODISCARD VkResult vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration)
{
	VALIDATE_FUNCTION_POINTER(vkQueueSetPerformanceConfigurationINTEL);
	return Kodiak::g_dispatcher.vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
}
inline KODIAK_NODISCARD VkResult vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration)
{
	VALIDATE_FUNCTION_POINTER(vkReleasePerformanceConfigurationINTEL);
	return Kodiak::g_dispatcher.vkReleasePerformanceConfigurationINTEL(device, configuration);
}
inline void vkUninitializePerformanceApiINTEL(VkDevice device)
{
	VALIDATE_FUNCTION_POINTER(vkUninitializePerformanceApiINTEL);
	Kodiak::g_dispatcher.vkUninitializePerformanceApiINTEL(device);
}


#ifdef VK_USE_PLATFORM_VI_NN
// VK_NN_vi_surface
inline KODIAK_NODISCARD VkResult vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{
	VALIDATE_FUNCTION_POINTER(vkCreateViSurfaceNN);
	return Kodiak::g_dispatcher.vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
}
#endif


// VK_NV_clip_space_w_scaling
inline void vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetViewportWScalingNV);
	Kodiak::g_dispatcher.vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}


// VK_NV_cooperative_matrix
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
}


// VK_NV_coverage_reduction_mode
inline KODIAK_NODISCARD VkResult vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations)
{
	VALIDATE_FUNCTION_POINTER(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
	return Kodiak::g_dispatcher.vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
}


// VK_NV_device_diagnostic_checkpoints
inline void vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetCheckpointNV);
	Kodiak::g_dispatcher.vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
inline void vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData)
{
	VALIDATE_FUNCTION_POINTER(vkGetQueueCheckpointDataNV);
	Kodiak::g_dispatcher.vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
}


// VK_NV_device_generated_commands
inline void vkCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindPipelineShaderGroupNV);
	Kodiak::g_dispatcher.vkCmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
inline void vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdExecuteGeneratedCommandsNV);
	Kodiak::g_dispatcher.vkCmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
inline void vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
	VALIDATE_FUNCTION_POINTER(vkCmdPreprocessGeneratedCommandsNV);
	Kodiak::g_dispatcher.vkCmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
inline KODIAK_NODISCARD VkResult vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout)
{
	VALIDATE_FUNCTION_POINTER(vkCreateIndirectCommandsLayoutNV);
	return Kodiak::g_dispatcher.vkCreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
}
inline void vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyIndirectCommandsLayoutNV);
	Kodiak::g_dispatcher.vkDestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
}
inline void vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetGeneratedCommandsMemoryRequirementsNV);
	Kodiak::g_dispatcher.vkGetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}


// VK_NV_mesh_shader
inline void vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawMeshTasksIndirectCountNV);
	Kodiak::g_dispatcher.vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
inline void vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawMeshTasksIndirectNV);
	Kodiak::g_dispatcher.vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
inline void vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
	VALIDATE_FUNCTION_POINTER(vkCmdDrawMeshTasksNV);
	Kodiak::g_dispatcher.vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}


// VK_NV_ray_tracing
inline KODIAK_NODISCARD VkResult vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoKHR* pBindInfos)
{
	VALIDATE_FUNCTION_POINTER(vkBindAccelerationStructureMemoryNV);
	return Kodiak::g_dispatcher.vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
}
inline void vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureKHR dst, VkAccelerationStructureKHR src, VkBuffer scratch, VkDeviceSize scratchOffset)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBuildAccelerationStructureNV);
	Kodiak::g_dispatcher.vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
inline void vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureKHR dst, VkAccelerationStructureKHR src, VkCopyAccelerationStructureModeKHR mode)
{
	VALIDATE_FUNCTION_POINTER(vkCmdCopyAccelerationStructureNV);
	Kodiak::g_dispatcher.vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
inline void vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth)
{
	VALIDATE_FUNCTION_POINTER(vkCmdTraceRaysNV);
	Kodiak::g_dispatcher.vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
inline void vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
	VALIDATE_FUNCTION_POINTER(vkCmdWriteAccelerationStructuresPropertiesNV);
	Kodiak::g_dispatcher.vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
inline KODIAK_NODISCARD VkResult vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader)
{
	VALIDATE_FUNCTION_POINTER(vkCompileDeferredNV);
	return Kodiak::g_dispatcher.vkCompileDeferredNV(device, pipeline, shader);
}
inline KODIAK_NODISCARD VkResult vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure)
{
	VALIDATE_FUNCTION_POINTER(vkCreateAccelerationStructureNV);
	return Kodiak::g_dispatcher.vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
}
inline KODIAK_NODISCARD VkResult vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{
	VALIDATE_FUNCTION_POINTER(vkCreateRayTracingPipelinesNV);
	return Kodiak::g_dispatcher.vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}
inline void vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator)
{
	VALIDATE_FUNCTION_POINTER(vkDestroyAccelerationStructureNV);
	Kodiak::g_dispatcher.vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
}
inline KODIAK_NODISCARD VkResult vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureKHR accelerationStructure, size_t dataSize, void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkGetAccelerationStructureHandleNV);
	return Kodiak::g_dispatcher.vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
}
inline void vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements)
{
	VALIDATE_FUNCTION_POINTER(vkGetAccelerationStructureMemoryRequirementsNV);
	Kodiak::g_dispatcher.vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
inline KODIAK_NODISCARD VkResult vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
	VALIDATE_FUNCTION_POINTER(vkGetRayTracingShaderGroupHandlesNV);
	return Kodiak::g_dispatcher.vkGetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
}


// VK_NV_scissor_exclusive
inline void vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetExclusiveScissorNV);
	Kodiak::g_dispatcher.vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}


// VK_NV_shading_rate_image
inline void vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
	VALIDATE_FUNCTION_POINTER(vkCmdBindShadingRateImageNV);
	Kodiak::g_dispatcher.vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
inline void vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetCoarseSampleOrderNV);
	Kodiak::g_dispatcher.vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
inline void vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes)
{
	VALIDATE_FUNCTION_POINTER(vkCmdSetViewportShadingRatePaletteNV);
	Kodiak::g_dispatcher.vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}


// VK_NVX_image_view_handle
inline KODIAK_NODISCARD VkResult vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageViewAddressNVX);
	return Kodiak::g_dispatcher.vkGetImageViewAddressNVX(device, imageView, pProperties);
}
inline KODIAK_NODISCARD uint32_t vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo)
{
	VALIDATE_FUNCTION_POINTER(vkGetImageViewHandleNVX);
	return Kodiak::g_dispatcher.vkGetImageViewHandleNVX(device, pInfo);
}

#undef VALIDATE_FUNCTION_POINTER