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

#undef VALIDATE_FUNCTION_POINTER