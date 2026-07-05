#pragma once
#include <vulkan/vulkan_raii.hpp>
#include "UHE/RHI/RHITypes.h"

namespace UHE::RHI::VULKAN
{

inline vk::Format MapTextureFormat(TextureFormat format);
inline vk::PrimitiveTopology MapTopology(PrimitiveTopology topology);
inline vk::Format ShaderDataTypeToVulkanFormat(ShaderDataType type);

} // namespace UHE::RHI::VULKAN
