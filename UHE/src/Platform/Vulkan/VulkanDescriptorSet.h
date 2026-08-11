#pragma once
#include <vector>
#include <vulkan/vulkan_raii.hpp>
#include "Platform/Vulkan/VulkanDescriptorManager.h"
#include "UHE/RHI/RHITypes.h"

namespace UHE::RHI::VULKAN
{
class VulkanDescriptorSet
{
public:
    VulkanDescriptorSet() = default;
    ~VulkanDescriptorSet() = default;
    VulkanDescriptorSet(VulkanDescriptorSet&) = delete;
    VulkanDescriptorSet operator=(VulkanDescriptorSet&) = delete;
    void Init(const VulkanDescriptorManager* Manager);
    void CreateDescriptorSet(const VulkanDescriptorManager* descriptorManager, VkDescriptorSetLayout layout);
    void DestroyDescriptorSet();
    void CreateBufferAnyTypeDescriptorSet(const VulkanDescriptorManager* descriptorManager,
                                          const VkDescriptorSetLayout layout, const UHE::RHI::BufferUsageFlags usage,
                                          vk::ShaderStageFlagBits flags, const u32 mdescriptorCount = 1);

    void Bind();

private:
    u32 MAX_BINDLESS_RESOURCES{};
    std::vector<vk::DescriptorSetLayoutBinding> m_BufferBinding;
    vk::raii::DescriptorSetLayout& m_DescriptorSetLayout;
    vk::raii::DescriptorSet& m_DescriptorSet;
};
} // namespace UHE::RHI::VULKAN
