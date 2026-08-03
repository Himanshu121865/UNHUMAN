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
    void CreateDescriptorSet(VulkanDescriptorManager* descriptorManager, VkDescriptorSetLayout layout);
    void DestroyDescriptorSet();
    void CreateUniformBufferDescriptorSet(VulkanDescriptorManager* descriptorManager, VkDescriptorSetLayout layout);
    void CreateStorageBufferDescriptorSet(VulkanDescriptorManager* descriptorManager, VkDescriptorSetLayout layout);
    
    void Bind();

private:
};
} // namespace UHE::RHI::VULKAN
