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


Kodiak::Dispatcher g_dispatcher;


namespace Kodiak
{

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

} // namespace Kodiak


// Base functions
VkResult vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{
	return g_dispatcher.vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}


VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
{
	return g_dispatcher.vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}


VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
	return g_dispatcher.vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}


VkResult vkEnumerateInstanceVersion(uint32_t* pApiVersion)
{
	return g_dispatcher.vkEnumerateInstanceVersion(pApiVersion);
}


PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char* pName)
{
	return g_dispatcher.vkGetInstanceProcAddr(instance, pName);
}