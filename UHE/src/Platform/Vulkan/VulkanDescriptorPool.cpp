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
    std::array<vk::DescriptorPoolSize, 3> poolSize = {
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eStorageBuffer, .descriptorCount = MAX_BINDLESS_RESOURCES},
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eCombinedImageSampler,
                               .descriptorCount = MAX_BINDLESS_RESOURCES},
        vk::DescriptorPoolSize{.type = vk::DescriptorType::eUniformBuffer, .descriptorCount = MAX_BINDLESS_RESOURCES}};

    vk::DescriptorPoolCreateInfo CreatepoolSize{.flags = vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet |
                                                         vk::DescriptorPoolCreateFlagBits::eUpdateAfterBind,
                                                .maxSets = 3,
                                                .poolSizeCount = static_cast<uint32_t>(poolSize.size()),
                                                .pPoolSizes = poolSize.data()};
    m_DescriptorPool = vk::raii::DescriptorPool(*m_Context->logicalDeviceHandle, CreatepoolSize);
}

void VulkanDescriptorPool::DestroyDescriptorPool()
{
    m_DescriptorPool = nullptr;
}
}; // namespace UHE::RHI::VULKAN
