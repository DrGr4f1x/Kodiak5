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
using namespace std;


namespace Kodiak
{

Dispatcher g_dispatcher;


Dispatcher::Dispatcher(PFN_vkGetInstanceProcAddr getInstanceProcAddr)
{
	Initialize(getInstanceProcAddr);
}


void Dispatcher::Initialize(PFN_vkGetInstanceProcAddr getInstanceProcAddr)
{
	vkGetInstanceProcAddr = getInstanceProcAddr;

	#define LOAD(name) \
	name = PFN_##name(vkGetInstanceProcAddr(nullptr, #name))

	// Base functions
	LOAD(vkCreateInstance);
	LOAD(vkEnumerateInstanceExtensionProperties);
	LOAD(vkEnumerateInstanceLayerProperties);
	LOAD(vkEnumerateInstanceVersion);

	#undef LOAD
}


void Dispatcher::Initialize(VkInstance instance)
{
	m_instance = instance;

	#define LOAD(name) \
	name = PFN_##name(vkGetInstanceProcAddr(m_instance, #name))

	// Vulkan 1.0 instance functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_0)
	{
		LOAD(vkCreateDevice);
		LOAD(vkDestroyInstance);
		LOAD(vkEnumeratePhysicalDevices);
		LOAD(vkGetDeviceProcAddr);
		LOAD(vkGetPhysicalDeviceFeatures);
		LOAD(vkGetPhysicalDeviceFormatProperties);
		LOAD(vkGetPhysicalDeviceImageFormatProperties);
		LOAD(vkGetPhysicalDeviceMemoryProperties);
		LOAD(vkGetPhysicalDeviceProperties);
		LOAD(vkGetPhysicalDeviceQueueFamilyProperties);
		LOAD(vkGetPhysicalDeviceSparseImageFormatProperties);
	}

	// Vulkan 1.1 instance functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_1)
	{
		LOAD(vkEnumeratePhysicalDeviceGroups);
		LOAD(vkGetPhysicalDeviceExternalBufferProperties);
		LOAD(vkGetPhysicalDeviceExternalFenceProperties);
		LOAD(vkGetPhysicalDeviceExternalSemaphoreProperties);
		LOAD(vkGetPhysicalDeviceFeatures2);
		LOAD(vkGetPhysicalDeviceFormatProperties2);
		LOAD(vkGetPhysicalDeviceImageFormatProperties2);
		LOAD(vkGetPhysicalDeviceMemoryProperties2);
		LOAD(vkGetPhysicalDeviceProperties2);
		LOAD(vkGetPhysicalDeviceQueueFamilyProperties2);
		LOAD(vkGetPhysicalDeviceSparseImageFormatProperties2);
	}
	
	// Vulkan 1.0 device functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_0)
	{
		LOAD(vkAllocateCommandBuffers);
		LOAD(vkAllocateDescriptorSets);
		LOAD(vkAllocateMemory);
		LOAD(vkBeginCommandBuffer);
		LOAD(vkBindBufferMemory);
		LOAD(vkBindImageMemory);
		LOAD(vkCmdBeginQuery);
		LOAD(vkCmdBeginRenderPass);
		LOAD(vkCmdBindDescriptorSets);
		LOAD(vkCmdBindIndexBuffer);
		LOAD(vkCmdBindPipeline);
		LOAD(vkCmdBindVertexBuffers);
		LOAD(vkCmdBlitImage);
		LOAD(vkCmdClearAttachments);
		LOAD(vkCmdClearColorImage);
		LOAD(vkCmdClearDepthStencilImage);
		LOAD(vkCmdCopyBuffer);
		LOAD(vkCmdCopyBufferToImage);
		LOAD(vkCmdCopyImage);
		LOAD(vkCmdCopyImageToBuffer);
		LOAD(vkCmdCopyQueryPoolResults);
		LOAD(vkCmdDispatch);
		LOAD(vkCmdDispatchIndirect);
		LOAD(vkCmdDraw);
		LOAD(vkCmdDrawIndexed);
		LOAD(vkCmdDrawIndexedIndirect);
		LOAD(vkCmdDrawIndirect);
		LOAD(vkCmdEndQuery);
		LOAD(vkCmdEndRenderPass);
		LOAD(vkCmdExecuteCommands);
		LOAD(vkCmdFillBuffer);
		LOAD(vkCmdNextSubpass);
		LOAD(vkCmdPipelineBarrier);
		LOAD(vkCmdPushConstants);
		LOAD(vkCmdResetEvent);
		LOAD(vkCmdResetQueryPool);
		LOAD(vkCmdResolveImage);
		LOAD(vkCmdSetBlendConstants);
		LOAD(vkCmdSetDepthBias);
		LOAD(vkCmdSetDepthBounds);
		LOAD(vkCmdSetEvent);
		LOAD(vkCmdSetLineWidth);
		LOAD(vkCmdSetScissor);
		LOAD(vkCmdSetStencilCompareMask);
		LOAD(vkCmdSetStencilReference);
		LOAD(vkCmdSetStencilWriteMask);
		LOAD(vkCmdSetViewport);
		LOAD(vkCmdUpdateBuffer);
		LOAD(vkCmdWaitEvents);
		LOAD(vkCmdWriteTimestamp);
		LOAD(vkCreateBuffer);
		LOAD(vkCreateBufferView);
		LOAD(vkCreateCommandPool);
		LOAD(vkCreateComputePipelines);
		LOAD(vkCreateDescriptorPool);
		LOAD(vkCreateDescriptorSetLayout);
		LOAD(vkCreateEvent);
		LOAD(vkCreateFence);
		LOAD(vkCreateFramebuffer);
		LOAD(vkCreateGraphicsPipelines);
		LOAD(vkCreateImage);
		LOAD(vkCreateImageView);
		LOAD(vkCreatePipelineCache);
		LOAD(vkCreatePipelineLayout);
		LOAD(vkCreateQueryPool);
		LOAD(vkCreateRenderPass);
		LOAD(vkCreateSampler);
		LOAD(vkCreateSemaphore);
		LOAD(vkCreateShaderModule);
		LOAD(vkDestroyBuffer);
		LOAD(vkDestroyBufferView);
		LOAD(vkDestroyCommandPool);
		LOAD(vkDestroyDescriptorPool);
		LOAD(vkDestroyDescriptorSetLayout);
		LOAD(vkDestroyDevice);
		LOAD(vkDestroyEvent);
		LOAD(vkDestroyFence);
		LOAD(vkDestroyFramebuffer);
		LOAD(vkDestroyImage);
		LOAD(vkDestroyImageView);
		LOAD(vkDestroyPipeline);
		LOAD(vkDestroyPipelineCache);
		LOAD(vkDestroyPipelineLayout);
		LOAD(vkDestroyQueryPool);
		LOAD(vkDestroyRenderPass);
		LOAD(vkDestroySampler);
		LOAD(vkDestroySemaphore);
		LOAD(vkDestroyShaderModule);
		LOAD(vkDeviceWaitIdle);
		LOAD(vkEndCommandBuffer);
		LOAD(vkFlushMappedMemoryRanges);
		LOAD(vkFreeCommandBuffers);
		LOAD(vkFreeDescriptorSets);
		LOAD(vkFreeMemory);
		LOAD(vkGetBufferMemoryRequirements);
		LOAD(vkGetDeviceMemoryCommitment);
		LOAD(vkGetDeviceQueue);
		LOAD(vkGetEventStatus);
		LOAD(vkGetFenceStatus);
		LOAD(vkGetImageMemoryRequirements);
		LOAD(vkGetImageSparseMemoryRequirements);
		LOAD(vkGetImageSubresourceLayout);
		LOAD(vkGetPipelineCacheData);
		LOAD(vkGetQueryPoolResults);
		LOAD(vkGetRenderAreaGranularity);
		LOAD(vkInvalidateMappedMemoryRanges);
		LOAD(vkMapMemory);
		LOAD(vkMergePipelineCaches);
		LOAD(vkQueueBindSparse);
		LOAD(vkQueueSubmit);
		LOAD(vkQueueWaitIdle);
		LOAD(vkResetCommandBuffer);
		LOAD(vkResetCommandPool);
		LOAD(vkResetDescriptorPool);
		LOAD(vkResetEvent);
		LOAD(vkResetFences);
		LOAD(vkSetEvent);
		LOAD(vkUnmapMemory);
		LOAD(vkUpdateDescriptorSets);
		LOAD(vkWaitForFences);
	}

	// Vulkan 1.1 device functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_1)
	{
		LOAD(vkBindBufferMemory2);
		LOAD(vkBindImageMemory2);
		LOAD(vkCreateDescriptorUpdateTemplate);
		LOAD(vkCreateSamplerYcbcrConversion);
		LOAD(vkDestroyDescriptorUpdateTemplate);
		LOAD(vkDestroySamplerYcbcrConversion);
		LOAD(vkGetBufferMemoryRequirements2);
		LOAD(vkGetDescriptorSetLayoutSupport);
		LOAD(vkGetDeviceGroupPeerMemoryFeatures);
		LOAD(vkGetDeviceQueue2);
		LOAD(vkGetImageMemoryRequirements2);
		LOAD(vkGetImageSparseMemoryRequirements2);
		LOAD(vkTrimCommandPool);
		LOAD(vkUpdateDescriptorSetWithTemplate);
	}

	// Vulkan 1.2 device functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_2)
	{
		LOAD(vkCmdBeginRenderPass2);
		LOAD(vkCmdDrawIndexedIndirectCount);
		LOAD(vkCmdDrawIndirectCount);
		LOAD(vkCmdEndRenderPass2);
		LOAD(vkCmdNextSubpass2);
		LOAD(vkCreateRenderPass2);
		LOAD(vkGetBufferDeviceAddress);
		LOAD(vkGetBufferOpaqueCaptureAddress);
		LOAD(vkGetDeviceMemoryOpaqueCaptureAddress);
		LOAD(vkGetSemaphoreCounterValue);
		LOAD(vkResetQueryPool);
		LOAD(vkSignalSemaphore);
		LOAD(vkWaitSemaphores);
	}

	#undef LOAD
}

void Dispatcher::Initialize(VkDevice device)
{
	m_device = device;

	#define LOAD(name) \
	name = PFN_##name(vkGetDeviceProcAddr(m_device, #name))

	// Vulkan 1.0 device functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_0)
	{
		LOAD(vkAllocateCommandBuffers);
		LOAD(vkAllocateDescriptorSets);
		LOAD(vkAllocateMemory);
		LOAD(vkBeginCommandBuffer);
		LOAD(vkBindBufferMemory);
		LOAD(vkBindImageMemory);
		LOAD(vkCmdBeginQuery);
		LOAD(vkCmdBeginRenderPass);
		LOAD(vkCmdBindDescriptorSets);
		LOAD(vkCmdBindIndexBuffer);
		LOAD(vkCmdBindPipeline);
		LOAD(vkCmdBindVertexBuffers);
		LOAD(vkCmdBlitImage);
		LOAD(vkCmdClearAttachments);
		LOAD(vkCmdClearColorImage);
		LOAD(vkCmdClearDepthStencilImage);
		LOAD(vkCmdCopyBuffer);
		LOAD(vkCmdCopyBufferToImage);
		LOAD(vkCmdCopyImage);
		LOAD(vkCmdCopyImageToBuffer);
		LOAD(vkCmdCopyQueryPoolResults);
		LOAD(vkCmdDispatch);
		LOAD(vkCmdDispatchIndirect);
		LOAD(vkCmdDraw);
		LOAD(vkCmdDrawIndexed);
		LOAD(vkCmdDrawIndexedIndirect);
		LOAD(vkCmdDrawIndirect);
		LOAD(vkCmdEndQuery);
		LOAD(vkCmdEndRenderPass);
		LOAD(vkCmdExecuteCommands);
		LOAD(vkCmdFillBuffer);
		LOAD(vkCmdNextSubpass);
		LOAD(vkCmdPipelineBarrier);
		LOAD(vkCmdPushConstants);
		LOAD(vkCmdResetEvent);
		LOAD(vkCmdResetQueryPool);
		LOAD(vkCmdResolveImage);
		LOAD(vkCmdSetBlendConstants);
		LOAD(vkCmdSetDepthBias);
		LOAD(vkCmdSetDepthBounds);
		LOAD(vkCmdSetEvent);
		LOAD(vkCmdSetLineWidth);
		LOAD(vkCmdSetScissor);
		LOAD(vkCmdSetStencilCompareMask);
		LOAD(vkCmdSetStencilReference);
		LOAD(vkCmdSetStencilWriteMask);
		LOAD(vkCmdSetViewport);
		LOAD(vkCmdUpdateBuffer);
		LOAD(vkCmdWaitEvents);
		LOAD(vkCmdWriteTimestamp);
		LOAD(vkCreateBuffer);
		LOAD(vkCreateBufferView);
		LOAD(vkCreateCommandPool);
		LOAD(vkCreateComputePipelines);
		LOAD(vkCreateDescriptorPool);
		LOAD(vkCreateDescriptorSetLayout);
		LOAD(vkCreateEvent);
		LOAD(vkCreateFence);
		LOAD(vkCreateFramebuffer);
		LOAD(vkCreateGraphicsPipelines);
		LOAD(vkCreateImage);
		LOAD(vkCreateImageView);
		LOAD(vkCreatePipelineCache);
		LOAD(vkCreatePipelineLayout);
		LOAD(vkCreateQueryPool);
		LOAD(vkCreateRenderPass);
		LOAD(vkCreateSampler);
		LOAD(vkCreateSemaphore);
		LOAD(vkCreateShaderModule);
		LOAD(vkDestroyBuffer);
		LOAD(vkDestroyBufferView);
		LOAD(vkDestroyCommandPool);
		LOAD(vkDestroyDescriptorPool);
		LOAD(vkDestroyDescriptorSetLayout);
		LOAD(vkDestroyDevice);
		LOAD(vkDestroyEvent);
		LOAD(vkDestroyFence);
		LOAD(vkDestroyFramebuffer);
		LOAD(vkDestroyImage);
		LOAD(vkDestroyImageView);
		LOAD(vkDestroyPipeline);
		LOAD(vkDestroyPipelineCache);
		LOAD(vkDestroyPipelineLayout);
		LOAD(vkDestroyQueryPool);
		LOAD(vkDestroyRenderPass);
		LOAD(vkDestroySampler);
		LOAD(vkDestroySemaphore);
		LOAD(vkDestroyShaderModule);
		LOAD(vkDeviceWaitIdle);
		LOAD(vkEndCommandBuffer);
		LOAD(vkFlushMappedMemoryRanges);
		LOAD(vkFreeCommandBuffers);
		LOAD(vkFreeDescriptorSets);
		LOAD(vkFreeMemory);
		LOAD(vkGetBufferMemoryRequirements);
		LOAD(vkGetDeviceMemoryCommitment);
		LOAD(vkGetDeviceQueue);
		LOAD(vkGetEventStatus);
		LOAD(vkGetFenceStatus);
		LOAD(vkGetImageMemoryRequirements);
		LOAD(vkGetImageSparseMemoryRequirements);
		LOAD(vkGetImageSubresourceLayout);
		LOAD(vkGetPipelineCacheData);
		LOAD(vkGetQueryPoolResults);
		LOAD(vkGetRenderAreaGranularity);
		LOAD(vkInvalidateMappedMemoryRanges);
		LOAD(vkMapMemory);
		LOAD(vkMergePipelineCaches);
		LOAD(vkQueueBindSparse);
		LOAD(vkQueueSubmit);
		LOAD(vkQueueWaitIdle);
		LOAD(vkResetCommandBuffer);
		LOAD(vkResetCommandPool);
		LOAD(vkResetDescriptorPool);
		LOAD(vkResetEvent);
		LOAD(vkResetFences);
		LOAD(vkSetEvent);
		LOAD(vkUnmapMemory);
		LOAD(vkUpdateDescriptorSets);
		LOAD(vkWaitForFences);
	}

	// Vulkan 1.1 device functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_1)
	{
		LOAD(vkBindBufferMemory2);
		LOAD(vkBindImageMemory2);
		LOAD(vkCreateDescriptorUpdateTemplate);
		LOAD(vkCreateSamplerYcbcrConversion);
		LOAD(vkDestroyDescriptorUpdateTemplate);
		LOAD(vkDestroySamplerYcbcrConversion);
		LOAD(vkGetBufferMemoryRequirements2);
		LOAD(vkGetDescriptorSetLayoutSupport);
		LOAD(vkGetDeviceGroupPeerMemoryFeatures);
		LOAD(vkGetDeviceQueue2);
		LOAD(vkGetImageMemoryRequirements2);
		LOAD(vkGetImageSparseMemoryRequirements2);
		LOAD(vkTrimCommandPool);
		LOAD(vkUpdateDescriptorSetWithTemplate);
	}

	// Vulkan 1.2 device functions
	if (m_apiVersion == 0 || m_apiVersion >= VK_VERSION_1_2)
	{
		LOAD(vkCmdBeginRenderPass2);
		LOAD(vkCmdDrawIndexedIndirectCount);
		LOAD(vkCmdDrawIndirectCount);
		LOAD(vkCmdEndRenderPass2);
		LOAD(vkCmdNextSubpass2);
		LOAD(vkCreateRenderPass2);
		LOAD(vkGetBufferDeviceAddress);
		LOAD(vkGetBufferOpaqueCaptureAddress);
		LOAD(vkGetDeviceMemoryOpaqueCaptureAddress);
		LOAD(vkGetSemaphoreCounterValue);
		LOAD(vkResetQueryPool);
		LOAD(vkSignalSemaphore);
		LOAD(vkWaitSemaphores);
	}

	#undef LOAD
}


void Dispatcher::LoadExtension(Extension extension)
{
	#define LOAD(name) \
	assert(m_device != VK_NULL_HANDLE || m_instance != VK_NULL_HANDLE); \
	if (m_device != VK_NULL_HANDLE) \
		name = PFN_##name(vkGetDeviceProcAddr(m_device, #name)); \
	else \
		name = PFN_##name(vkGetInstanceProcAddr(m_instance, #name))

	switch (extension)
	{
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	case Extension::KHR_AndroidSurface:
		LOAD(vkCreateAndroidSurfaceKHR);
		break;
#endif

	case Extension::KHR_CopyCommands2:
		LOAD(vkCmdBlitImage2KHR);
		LOAD(vkCmdCopyBuffer2KHR);
		LOAD(vkCmdCopyBufferToImage2KHR);
		LOAD(vkCmdCopyImage2KHR);
		LOAD(vkCmdCopyImageToBuffer2KHR);
		LOAD(vkCmdResolveImage2KHR);
		break;

	case Extension::KHR_Display:
		LOAD(vkCreateDisplayModeKHR);
		LOAD(vkCreateDisplayPlaneSurfaceKHR);
		LOAD(vkGetDisplayModePropertiesKHR);
		LOAD(vkGetDisplayPlaneCapabilitiesKHR);
		LOAD(vkGetDisplayPlaneSupportedDisplaysKHR);
		LOAD(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
		LOAD(vkGetPhysicalDeviceDisplayPropertiesKHR);
		break;

	case Extension::KHR_DisplaySwapChain:
		LOAD(vkCreateSharedSwapchainsKHR);
		break;

	case Extension::KHR_ExternalFenceFd:
		LOAD(vkGetFenceFdKHR);
		LOAD(vkImportFenceFdKHR);
		break;

#ifdef VK_USE_PLATFORM_WIN32_KHR
	case Extension::KHR_ExternalFenceWin32:
		LOAD(vkGetFenceWin32HandleKHR);
		LOAD(vkImportFenceWin32HandleKHR);
		break;
#endif

	case Extension::KHR_ExternalMemoryFd:
		LOAD(vkGetMemoryFdKHR);
		LOAD(vkGetMemoryFdPropertiesKHR);
		break;

#ifdef VK_USE_PLATFORM_WIN32_KHR
	case Extension::KHR_ExternalMemoryWin32:
		LOAD(vkGetMemoryWin32HandleKHR);
		LOAD(vkGetMemoryWin32HandlePropertiesKHR);
		break;
#endif

	case Extension::KHR_ExternalSemaphoreFd:
		LOAD(vkGetSemaphoreFdKHR);
		LOAD(vkImportSemaphoreFdKHR);
		break;

#ifdef VK_USE_PLATFORM_WIN32_KHR
	case Extension::KHR_ExternalSemaphoreWin32:
		LOAD(vkGetSemaphoreWin32HandleKHR);
		LOAD(vkImportSemaphoreWin32HandleKHR);
		break;
#endif

#if 0
	case Extension::KHR_FragmentShadingRate:
		LOAD(vkCmdSetFragmentShadingRateKHR);
		LOAD(vkGetPhysicalDeviceFragmentShadingRatesKHR);
		break;
#endif

	case Extension::KHR_GetDisplayProperties2:
		LOAD(vkGetDisplayModeProperties2KHR);
		LOAD(vkGetDisplayPlaneCapabilities2KHR);
		LOAD(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
		LOAD(vkGetPhysicalDeviceDisplayProperties2KHR);
		break;

	case Extension::KHR_GetSurfaceCapabilities2:
		LOAD(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
		LOAD(vkGetPhysicalDeviceSurfaceFormats2KHR);
		break;

	case Extension::KHR_PerformanceQuery:
		LOAD(vkAcquireProfilingLockKHR);
		LOAD(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
		LOAD(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
		LOAD(vkReleaseProfilingLockKHR);
		break;

	case Extension::KHR_PipelineExecutableProperties:
		LOAD(vkGetPipelineExecutableInternalRepresentationsKHR);
		LOAD(vkGetPipelineExecutablePropertiesKHR);
		LOAD(vkGetPipelineExecutableStatisticsKHR);
		break;

	case Extension::KHR_PushDescriptor:
		LOAD(vkCmdPushDescriptorSetKHR);
		LOAD(vkCmdPushDescriptorSetWithTemplateKHR);
		break;

	case Extension::KHR_SharedPresentableImage:
		LOAD(vkGetSwapchainStatusKHR);
		break;

	case Extension::KHR_Surface:
		LOAD(vkDestroySurfaceKHR);
		LOAD(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
		LOAD(vkGetPhysicalDeviceSurfaceFormatsKHR);
		LOAD(vkGetPhysicalDeviceSurfacePresentModesKHR);
		LOAD(vkGetPhysicalDeviceSurfaceSupportKHR);
		break;

	case Extension::KHR_Swapchain:
		LOAD(vkAcquireNextImageKHR);
		LOAD(vkCreateSwapchainKHR);
		LOAD(vkDestroySwapchainKHR);
		LOAD(vkGetSwapchainImagesKHR);
		LOAD(vkQueuePresentKHR);
		break;

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
	case Extension::KHR_WaylandSurface:
		LOAD(vkCreateWaylandSurfaceKHR);
		LOAD(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
		break;
#endif

#ifdef VK_USE_PLATFORM_WIN32_KHR
	case Extension::KHR_Win32Surface:
		LOAD(vkCreateWin32SurfaceKHR);
		LOAD(vkGetPhysicalDeviceWin32PresentationSupportKHR);
		break;
#endif

#ifdef VK_USE_PLATFORM_XCB_KHR
	case Extension::KHR_XcbSurface:
		LOAD(vkCreateXcbSurfaceKHR);
		LOAD(vkGetPhysicalDeviceXcbPresentationSupportKHR);
		break;
#endif

#ifdef VK_USE_PLATFORM_XLIB_KHR
	case Extension::KHR_XlibSurface:
		LOAD(vkCreateXlibSurfaceKHR);
		LOAD(vkGetPhysicalDeviceXlibPresentationSupportKHR);
		break;
#endif

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
	case Extension::EXT_AcquireXlibDisplay:
		LOAD(vkAcquireXlibDisplayEXT);
		LOAD(vkGetRandROutputDisplayEXT);
		break;
#endif

	case Extension::EXT_CalibratedTimestamps:
		LOAD(vkGetCalibratedTimestampsEXT);
		LOAD(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
		break;

	case Extension::EXT_ConditionalRendering:
		LOAD(vkCmdBeginConditionalRenderingEXT);
		LOAD(vkCmdEndConditionalRenderingEXT);
		break;

	case Extension::EXT_DebugUtils:
		LOAD(vkCmdBeginDebugUtilsLabelEXT);
		LOAD(vkCmdEndDebugUtilsLabelEXT);
		LOAD(vkCmdInsertDebugUtilsLabelEXT);
		LOAD(vkCreateDebugUtilsMessengerEXT);
		LOAD(vkDestroyDebugUtilsMessengerEXT);
		LOAD(vkQueueBeginDebugUtilsLabelEXT);
		LOAD(vkQueueEndDebugUtilsLabelEXT);
		LOAD(vkQueueInsertDebugUtilsLabelEXT);
		LOAD(vkSetDebugUtilsObjectNameEXT);
		LOAD(vkSetDebugUtilsObjectTagEXT);
		LOAD(vkSubmitDebugUtilsMessageEXT);
		break;

	case Extension::EXT_DirectModeDisplay:
		LOAD(vkReleaseDisplayEXT);
		break;

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
	case Extension::EXT_DirectFbSurface:
		LOAD(vkCreateDirectFBSurfaceEXT);
		LOAD(vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
		break;
#endif

	case Extension::EXT_DiscardRectangles:
		LOAD(vkCmdSetDiscardRectangleEXT);
		break;

	case Extension::EXT_DisplayControl:
		LOAD(vkDisplayPowerControlEXT);
		LOAD(vkGetSwapchainCounterEXT);
		LOAD(vkRegisterDeviceEventEXT);
		LOAD(vkRegisterDisplayEventEXT);
		break;

	case Extension::EXT_DisplaySurfaceCounter:
		LOAD(vkGetPhysicalDeviceSurfaceCapabilities2EXT);
		break;

	case Extension::EXT_ExtendedDynamicState:
		LOAD(vkCmdBindVertexBuffers2EXT);
		LOAD(vkCmdSetCullModeEXT);
		LOAD(vkCmdSetDepthBoundsTestEnableEXT);
		LOAD(vkCmdSetDepthCompareOpEXT);
		LOAD(vkCmdSetDepthTestEnableEXT);
		LOAD(vkCmdSetDepthWriteEnableEXT);
		LOAD(vkCmdSetFrontFaceEXT);
		LOAD(vkCmdSetPrimitiveTopologyEXT);
		LOAD(vkCmdSetScissorWithCountEXT);
		LOAD(vkCmdSetStencilOpEXT);
		LOAD(vkCmdSetStencilTestEnableEXT);
		LOAD(vkCmdSetViewportWithCountEXT);
		break;

	case Extension::EXT_ExternalMemoryHost:
		LOAD(vkGetMemoryHostPointerPropertiesEXT);
		break;

#ifdef VK_USE_PLATFORM_WIN32_KHR
	case Extension::EXT_FullScreenExclusive:
		LOAD(vkAcquireFullScreenExclusiveModeEXT);
		LOAD(vkGetDeviceGroupSurfacePresentModes2EXT);
		LOAD(vkGetPhysicalDeviceSurfacePresentModes2EXT);
		LOAD(vkReleaseFullScreenExclusiveModeEXT);
		break;
#endif

	case Extension::EXT_HdrMetadata:
		LOAD(vkSetHdrMetadataEXT);
		break;

	case Extension::EXT_HeadlessSurface:
		LOAD(vkCreateHeadlessSurfaceEXT);
		break;

	case Extension::EXT_ImageDrmFormatModifier:
		LOAD(vkGetImageDrmFormatModifierPropertiesEXT);
		break;

	case Extension::EXT_LineRasterization:
		LOAD(vkCmdSetLineStippleEXT);
		break;

#if VK_USE_PLATFORM_METAL_EXT
	case Extension::EXT_MetalSurface:
		LOAD(vkCreateMetalSurfaceEXT);
		break;
#endif

	case Extension::EXT_PrivateData:
		LOAD(vkCreatePrivateDataSlotEXT);
		LOAD(vkDestroyPrivateDataSlotEXT);
		LOAD(vkGetPrivateDataEXT);
		LOAD(vkSetPrivateDataEXT);
		break;

	case Extension::EXT_SampleLocations:
		LOAD(vkCmdSetSampleLocationsEXT);
		LOAD(vkGetPhysicalDeviceMultisamplePropertiesEXT);
		break;

	case Extension::EXT_ToolingInfo:
		LOAD(vkGetPhysicalDeviceToolPropertiesEXT);
		break;

	case Extension::EXT_TransformFeedback:
		LOAD(vkCmdBeginQueryIndexedEXT);
		LOAD(vkCmdBeginTransformFeedbackEXT);
		LOAD(vkCmdBindTransformFeedbackBuffersEXT);
		LOAD(vkCmdDrawIndirectByteCountEXT);
		LOAD(vkCmdEndQueryIndexedEXT);
		LOAD(vkCmdEndTransformFeedbackEXT);
		break;

	case Extension::EXT_ValidationCache:
		LOAD(vkCreateValidationCacheEXT);
		LOAD(vkDestroyValidationCacheEXT);
		LOAD(vkGetValidationCacheDataEXT);
		LOAD(vkMergeValidationCachesEXT);
		break;

	case Extension::AMD_BufferMarker:
		LOAD(vkCmdWriteBufferMarkerAMD);
		break;

	case Extension::AMD_DisplayNativeHdr:
		LOAD(vkSetLocalDimmingAMD);
		break;

	case Extension::AMD_ShaderInfo:
		LOAD(vkGetShaderInfoAMD);
		break;

#ifdef VK_USE_PLATFORM_ANDROID_KHR
	case Extension::ANDROID_ExternalMemoryAndroidHardwareBuffer:
		LOAD(vkGetAndroidHardwareBufferPropertiesANDROID);
		LOAD(vkGetMemoryAndroidHardwareBufferANDROID);
		break;
#endif

#ifdef VK_USE_PLATFORM_FUSCHIA
	case Extension::FUSCHIA_ImagepipeSurface:
		LOAD(vkCreateImagePipeSurfaceFUCHSIA);
		break;
#endif

#ifdef VK_USE_PLATFORM_GGP
	case Extension::GGP_StreamDescriptorSurface:
		LOAD(vkCreateStreamDescriptorSurfaceGGP);
		break;
#endif

	case Extension::GOOGLE_DisplayTiming:
		LOAD(vkGetPastPresentationTimingGOOGLE);
		LOAD(vkGetRefreshCycleDurationGOOGLE);
		break;

	case Extension::INTEL_PerformanceQuery:
		LOAD(vkAcquirePerformanceConfigurationINTEL);
		LOAD(vkCmdSetPerformanceMarkerINTEL);
		LOAD(vkCmdSetPerformanceOverrideINTEL);
		LOAD(vkCmdSetPerformanceStreamMarkerINTEL);
		LOAD(vkGetPerformanceParameterINTEL);
		LOAD(vkInitializePerformanceApiINTEL);
		LOAD(vkQueueSetPerformanceConfigurationINTEL);
		LOAD(vkReleasePerformanceConfigurationINTEL);
		LOAD(vkUninitializePerformanceApiINTEL);
		break;

#ifdef VK_USE_PLATFORM_VI_NN
	case Extension::NN_ViSurface:
		LOAD(vkCreateViSurfaceNN);
		break;
#endif

	case Extension::NV_ClipSpaceWScaling:
		LOAD(vkCmdSetViewportWScalingNV);
		break;

	case Extension::NV_CooperativeMatrix:
		LOAD(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
		break;

	case Extension::NV_CoverageReductionMode:
		LOAD(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
		break;

	case Extension::NV_DeviceDiagnosticCheckpoints:
		LOAD(vkCmdSetCheckpointNV);
		LOAD(vkGetQueueCheckpointDataNV);
		break;

	case Extension::NV_DeviceGeneratedCommands:
		LOAD(vkCmdBindPipelineShaderGroupNV);
		LOAD(vkCmdExecuteGeneratedCommandsNV);
		LOAD(vkCmdPreprocessGeneratedCommandsNV);
		LOAD(vkCreateIndirectCommandsLayoutNV);
		LOAD(vkDestroyIndirectCommandsLayoutNV);
		LOAD(vkGetGeneratedCommandsMemoryRequirementsNV);
		break;

#if 0
	case Extension::NV_FragmentShadingRateEnums:
		LOAD(vkCmdSetFragmentShadingRateEnumNV);
		break;
#endif

	case Extension::NV_MeshShader:
		LOAD(vkCmdDrawMeshTasksIndirectCountNV);
		LOAD(vkCmdDrawMeshTasksIndirectNV);
		LOAD(vkCmdDrawMeshTasksNV);
		break;

	case Extension::NV_RayTracing:
		LOAD(vkBindAccelerationStructureMemoryNV);
		LOAD(vkCmdBuildAccelerationStructureNV);
		LOAD(vkCmdCopyAccelerationStructureNV);
		LOAD(vkCmdTraceRaysNV);
		LOAD(vkCmdWriteAccelerationStructuresPropertiesNV);
		LOAD(vkCompileDeferredNV);
		LOAD(vkCreateAccelerationStructureNV);
		LOAD(vkCreateRayTracingPipelinesNV);
		LOAD(vkDestroyAccelerationStructureNV);
		LOAD(vkGetAccelerationStructureHandleNV);
		LOAD(vkGetAccelerationStructureMemoryRequirementsNV);
		LOAD(vkGetRayTracingShaderGroupHandlesNV);
		break;

	case Extension::NV_ScissorExclusive:
		LOAD(vkCmdSetExclusiveScissorNV);
		break;

	case Extension::NV_ShadingRateImage:
		LOAD(vkCmdBindShadingRateImageNV);
		LOAD(vkCmdSetCoarseSampleOrderNV);
		LOAD(vkCmdSetViewportShadingRatePaletteNV);
		break;

	case Extension::NVX_ImageViewHandle:
		LOAD(vkGetImageViewAddressNVX);
		LOAD(vkGetImageViewHandleNVX);
		break;
	}

	#undef LOAD
}

} // namespace Kodiak