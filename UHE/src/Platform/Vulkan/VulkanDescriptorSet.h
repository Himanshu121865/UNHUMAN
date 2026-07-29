#pragma once
#include "Platform/Vulkan/VulkanDescriptorManager.h"

namespace UHE::RHI::VULKAN
{
class VulkanDescriptorSet
{
public:
    VulkanDescriptorSet() = default;
    ~VulkanDescriptorSet() = default;
    VulkanDescriptorSet(VulkanDescriptorSet&) = delete;
    VulkanDescriptorSet operator=(VulkanDescriptorSet&) = delete;
    void Bind();

private:
};
} // namespace UHE::RHI::VULKAN
