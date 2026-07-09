#include "uhepch.h"
#include "VulkanExtensionCheck.h"
#include <vector>
#include <vulkan/vulkan_core.h>

namespace UHE::RHI::VULKAN
{

std::vector<const char*> VulkanExtensionCheck::GetEnabledDeviceExtensions() const
{
    std::vector<const char*> extensions;

    extensions.emplace_back("VK_KHR_swapchain");

    if (m_extensionCheck.HasVkdynamicRendering)
        extensions.emplace_back("VK_KHR_dynamic_rendering");
    if (m_extensionCheck.HasVkSync2)
        extensions.emplace_back("VK_KHR_synchronization2");
    if (m_extensionCheck.HasVkTimelineSemaphore)
        extensions.emplace_back("VK_KHR_timeline_semaphore");
    if (m_extensionCheck.HasVkPushDescriptor)
        extensions.emplace_back("VK_KHR_push_descriptor");

    if (m_extensionCheck.HasVK16bit_storage)
        extensions.emplace_back("VK_KHR_16bit_storage");
    if (m_extensionCheck.HasVkshader_float16_int8)
        extensions.emplace_back("VK_KHR_shader_float16_int8");
    if (m_extensionCheck.HasVkbuffer_device_address)
        extensions.emplace_back("VK_KHR_buffer_device_address");
    if (m_extensionCheck.HasVkshader_subgroup_extended_types)
        extensions.emplace_back("VK_KHR_shader_subgroup_extended_types");

    if (m_extensionCheck.HasVkBindlessDescriptor)
        extensions.emplace_back("VK_EXT_descriptor_indexing");
    if (m_extensionCheck.HasVkDescriptorBuffer)
        extensions.emplace_back("VK_EXT_descriptor_buffer");
    if (m_extensionCheck.HasVkDescriptorHeap)
        extensions.emplace_back("VK_EXT_descriptor_heap");

    if (m_extensionCheck.HasVkShaderObject)
        extensions.emplace_back("VK_EXT_shader_object");
    if (m_extensionCheck.HasVkGraphicsPipelineLibrary)
        extensions.emplace_back("VK_EXT_graphics_pipeline_library");
    if (m_extensionCheck.HasVkExtendedDynamicState)
        extensions.emplace_back("VK_EXT_extended_dynamic_state");
    if (m_extensionCheck.HasVkExtendedDynamicState2)
        extensions.emplace_back("VK_EXT_extended_dynamic_state2");
    if (m_extensionCheck.HasVkExtendedDynamicState3)
        extensions.emplace_back("VK_EXT_extended_dynamic_state3");

    if (m_extensionCheck.HasVkDrawIndirectCount)
        extensions.emplace_back("VK_KHR_draw_indirect_count");
    if (m_extensionCheck.HasVkInlineUniformBlock)
        extensions.emplace_back("VK_EXT_inline_uniform_block");
    if (m_extensionCheck.HasVkShaderDrawParameters)
        extensions.emplace_back("VK_KHR_shader_draw_parameters");
    if (m_extensionCheck.HasVkmesh_shader)
        extensions.emplace_back("VK_EXT_mesh_shader");
    if (m_extensionCheck.HasVkDeviceGeneratedCommands)
        extensions.emplace_back("VK_EXT_device_generated_commands");

    if (m_extensionCheck.HasVkVideoQueue)
        extensions.emplace_back("VK_KHR_video_queue");
    if (m_extensionCheck.HasVkdecode_av1)
        extensions.emplace_back("VK_KHR_video_decode_av1");
    if (m_extensionCheck.HasVkdecode_h265)
        extensions.emplace_back("VK_KHR_video_decode_h265");
    if (m_extensionCheck.HasVkdecode_h264)
        extensions.emplace_back("VK_KHR_video_decode_h264");
    if (m_extensionCheck.HasVkencode_h265)
        extensions.emplace_back("VK_KHR_video_encode_h265");
    if (m_extensionCheck.HasVkencode_h264)
        extensions.emplace_back("VK_KHR_video_encode_h264");
    if (m_extensionCheck.HasVkencode_av1)
        extensions.emplace_back("VK_KHR_video_encode_av1");
    if (m_extensionCheck.HasVkVideoEncodeAV1)
        extensions.emplace_back("VK_KHR_video_encode_av1");
    if (m_extensionCheck.HasVkVideoEncodeFeedback2)
        extensions.emplace_back("VK_KHR_video_encode_feedback2");
    if (m_extensionCheck.HasVKYcbcr2Conversion)
        extensions.emplace_back("VK_KHR_sampler_ycbcr_conversion");

    if (m_extensionCheck.HasVkExternalMemoryAndroidHardwareBuffer)
        extensions.emplace_back("VK_ANDROID_external_memory_android_hardware_buffer");
    if (m_extensionCheck.HasVkShaderFramebufferFetch)
        extensions.emplace_back("VK_EXT_shader_framebuffer_fetch");
    if (m_extensionCheck.HasVkMemoryBudget)
        extensions.emplace_back("VK_EXT_memory_budget");
    if (m_extensionCheck.HasVkTextureCompressionASTC_HDR)
        extensions.emplace_back("VK_EXT_texture_compression_astc_hdr");

    if (m_extensionCheck.HasVkMemoryPriority)
        extensions.emplace_back("VK_EXT_memory_priority");
    if (m_extensionCheck.HasVkPageableDeviceLocalMemory)
        extensions.emplace_back("VK_EXT_pageable_device_local_memory");
    if (m_extensionCheck.HasVkHostImageCopy)
        extensions.emplace_back("VK_EXT_host_image_copy");
    if (m_extensionCheck.HasVkDynamicRenderingLocalRead)
        extensions.emplace_back("VK_KHR_dynamic_rendering_local_read");
    if (m_extensionCheck.HasVkDedicatedAllocation)
        extensions.emplace_back("VK_KHR_dedicated_allocation");
    if (m_extensionCheck.HasVkAccelerationStructure)
        extensions.emplace_back("VK_KHR_acceleration_structure");
    if (m_extensionCheck.HasVkRayTracingPipeline)
        extensions.emplace_back("VK_KHR_ray_tracing_pipeline");
    if (m_extensionCheck.HasVkRayQuery)
        extensions.emplace_back("VK_KHR_ray_query");
    if (m_extensionCheck.HasVkfragment_shading_rate)
        extensions.emplace_back("VK_KHR_fragment_shading_rate");
    if (m_extensionCheck.HasVkCooperativeMatrix)
        extensions.emplace_back("VK_KHR_cooperative_matrix");

    if (m_extensionCheck.HasVkRobustness2)
        extensions.emplace_back("VK_EXT_robustness2");
    if (m_extensionCheck.HasVkImageRobustness)
        extensions.emplace_back("VK_EXT_image_robustness");
    if (m_extensionCheck.HasVkCreateRenderPass2)
        extensions.emplace_back("VK_KHR_create_renderpass2");

    return extensions;
};
vk::PhysicalDeviceFeatures2* VulkanExtensionCheck::BuildDeviceFeatureChain()
{
    m_features2.features.samplerAnisotropy = VK_TRUE;
    m_features2.features.independentBlend = VK_TRUE;

    void** pNextChainTail = &m_v12Features.pNext;

    if (m_extensionCheck.HasVkShaderDrawParameters)
    {
        m_v11Features.shaderDrawParameters = VK_TRUE;
        *pNextChainTail = &m_v11Features;
        pNextChainTail = &m_v11Features.pNext;
    }

    if (m_extensionCheck.HasVkBindlessDescriptor || m_extensionCheck.HasVkbuffer_device_address)
    {
        if (m_extensionCheck.HasVkBindlessDescriptor)
        {
            m_v12Features.descriptorBindingStorageBufferUpdateAfterBind = VK_TRUE;
            m_v12Features.descriptorBindingPartiallyBound = VK_TRUE;
            m_v12Features.descriptorBindingSampledImageUpdateAfterBind = VK_TRUE;
            m_v12Features.shaderSampledImageArrayNonUniformIndexing = VK_TRUE;
        }
        if (m_extensionCheck.HasVkbuffer_device_address)
            m_v12Features.bufferDeviceAddress = VK_TRUE;
        *pNextChainTail = &m_v12Features;
        pNextChainTail = &m_v12Features.pNext;
    }

    if (m_extensionCheck.HasVkdynamicRendering || m_extensionCheck.HasVkSync2)
    {
        m_v13Features.dynamicRendering = m_extensionCheck.HasVkdynamicRendering ? VK_TRUE : VK_FALSE;
        m_v13Features.synchronization2 = m_extensionCheck.HasVkSync2 ? VK_TRUE : VK_FALSE;
        *pNextChainTail = &m_v13Features;
        pNextChainTail = &m_v13Features.pNext;
    }

    if (m_extensionCheck.HasVkExtendedDynamicState)
    {
        m_dynamicStateFeatures.extendedDynamicState = VK_TRUE;
        *pNextChainTail = &m_dynamicStateFeatures;
        pNextChainTail = &m_dynamicStateFeatures.pNext;
    }

    if (m_extensionCheck.HasVkDescriptorBuffer)
    {
        m_descriptorBufferFeatures.descriptorBuffer = VK_TRUE;
        *pNextChainTail = &m_descriptorBufferFeatures;
        pNextChainTail = &m_descriptorBufferFeatures.pNext;
    }
    if (m_extensionCheck.HasVkShaderObject)
    {
        m_shaderObjectFeatures.shaderObject = VK_TRUE;
        *pNextChainTail = &m_shaderObjectFeatures;
        pNextChainTail = &m_shaderObjectFeatures.pNext;
    }
    *pNextChainTail = nullptr;
    return &m_features2;
};

} // namespace UHE::RHI::VULKAN
