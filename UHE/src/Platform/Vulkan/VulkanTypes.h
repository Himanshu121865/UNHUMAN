#pragma once
#include <vulkan/vulkan_raii.hpp>
#include "UHE/RHI/RHITypes.h"

namespace UHE::RHI::VULKAN
{
vk::Format MapTextureFormat(TextureFormat format);
vk::PrimitiveTopology MapTopology(PrimitiveTopology topology);
vk::Format ShaderDataTypeToVulkanFormat(ShaderDataType type);
vk::Format ToVkFormat(TextureFormat format);
vk::SampleCountFlagBits ToVkSample(u32 sampleCount);
vk::AttachmentStoreOp ToVkStoreOp(StoreOp storeOp);
vk::AttachmentLoadOp ToVkLoadOp(LoadOp loadOp);
vk::ImageLayout ToVkImageLayout(TextureUsage usage);

} // namespace UHE::RHI::VULKAN
