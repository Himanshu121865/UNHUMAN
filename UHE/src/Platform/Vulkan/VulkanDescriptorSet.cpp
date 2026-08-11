#include "uhepch.h"
#include "VulkanDescriptorSet.h"
#include <vulkan/vulkan_raii.hpp>
#include "Platform/Vulkan/VulkanDescriptorManager.h"
#include "UHE/RHI/RHITypes.h"
#include "VulkanTypes.h"

namespace UHE::RHI::VULKAN
{

void VulkanDescriptorSet::Init(const VulkanDescriptorManager* Manager)
{
    MAX_BINDLESS_RESOURCES = Manager->GetMaxBindlessResourceCount();
    m_BufferBinding.reserve(MAX_BINDLESS_RESOURCES);
    
}

void VulkanDescriptorSet::Bind() {};

void VulkanDescriptorSet::CreateDescriptorSet(const VulkanDescriptorManager* descriptorManager,
                                              VkDescriptorSetLayout layout)
{
    // Implementation for creating a descriptor set using the provided descriptor manager and layout
    vk::DescriptorSetAllocateInfo allocInfo{
        .descriptorPool = *descriptorManager->GetDescriptorPool(), .descriptorSetCount = 1, .pSetLayouts = &layout};
    m_DescriptorSet = descriptorManager->GetDevice().allocateDescriptorSets(allocInfo)[0];
    m_DescriptorSetLayout = layout;
};

void VulkanDescriptorSet::CreateBufferAnyTypeDescriptorSet(const VulkanDescriptorManager* descriptorManager,
                                                           const VkDescriptorSetLayout layout,
                                                           const UHE::RHI::BufferUsageFlags usage,
                                                           vk::ShaderStageFlagBits flags, const u32 mdescriptorCount)
{
    vk::DescriptorSetLayoutBinding eBufferBinding{.binding = 0,
                                                  .descriptorType = ToVkDescriptorType(usage),
                                                  .descriptorCount = mdescriptorCount,
                                                  .stageFlags = flags,
                                                  .pImmutableSamplers = nullptr};

    m_BufferBinding.emplace_back(eBufferBinding);
}

void VulkanDescriptorSet::DestroyDescriptorSet(const VulkanDescriptorManager* descriptorManager) {
    descriptorManager->GetDevice().freeDescriptorSets(*descriptorManager->GetDescriptorPool(), m_DescriptorSet);
    m_DescriptorSet = nullptr;
}

} // namespace UHE::RHI::VULKAN
