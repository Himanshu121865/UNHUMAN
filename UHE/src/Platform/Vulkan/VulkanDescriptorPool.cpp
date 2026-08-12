#include "uhepch.h"
#include "VulkanDescriptorPool.h"
#include "VulkanContext.h"
#include "VulkanLogicalDevice.h"

namespace UHE::RHI::VULKAN
{
void VulkanDescriptorPool::Init(VulkanContext* context)
{
    m_Context = context;
};

void VulkanDescriptorPool::CreateDescriptorPool()
{
    // Standard fallback pool sizes for Vulkan 1.1
    std::array<vk::DescriptorPoolSize, 3> poolSize = {
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eStorageBuffer, .descriptorCount = 1000},
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eCombinedImageSampler, .descriptorCount = 1000},
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eUniformBuffer, .descriptorCount = 1000}
    };

    vk::DescriptorPoolCreateInfo CreatepoolSize{
        .flags = vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet, // Removed eUpdateAfterBind for 1.1 support
        .maxSets = 1000,
        .poolSizeCount = static_cast<uint32_t>(poolSize.size()),
        .pPoolSizes = poolSize.data()
    };
    
    m_DescriptorPool = vk::raii::DescriptorPool(*m_Context->logicalDeviceHandle, CreatepoolSize);
}

void VulkanDescriptorPool::CreateBindlessDescriptorPool(uint32_t maxBindlessResources)
{
    std::array<vk::DescriptorPoolSize, 2> poolSizes = {
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eStorageBuffer, .descriptorCount = maxBindlessResources},
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eCombinedImageSampler,
                               .descriptorCount = maxBindlessResources}};

    vk::DescriptorPoolCreateInfo poolInfo{
        .flags = vk::DescriptorPoolCreateFlagBits::eUpdateAfterBind |
                 vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet,
        .maxSets = 2,
        .poolSizeCount = static_cast<uint32_t>(poolSizes.size()),
        .pPoolSizes = poolSizes.data()};

    m_DescriptorPool = vk::raii::DescriptorPool(*m_Context->logicalDeviceHandle, poolInfo);
}

void VulkanDescriptorPool::DestroyDescriptorPool()
{
    m_DescriptorPool = nullptr;
}

void VulkanDescriptorPool::ResetDescriptorPool()
{
    m_DescriptorPool.reset();
}

void VulkanDescriptorPool::Allocate()
{
   // Allocation logic can be implemented here if needed
}
}; // namespace UHE::RHI::VULKAN
