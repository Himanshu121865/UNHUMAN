#include "uhepch.h"
#include "VulkanDescriptorSet.h"
#include <vulkan/vulkan_raii.hpp>
#include "VulkanDescriptorPool.h"
#include "VulkanTypes.h"

namespace UHE::RHI::VULKAN
{

void VulkanDescriptorSet::AddBinding(u32 binding, const UHE::RHI::BufferUsageFlags usage, vk::ShaderStageFlags flags,
                                     u32 descriptorCount)
{
    vk::DescriptorSetLayoutBinding newBinding{.binding = binding,
                                              .descriptorType = ToVkDescriptorType(usage),
                                              .descriptorCount = descriptorCount,
                                              .stageFlags = flags,
                                              .pImmutableSamplers = nullptr};
    m_BufferBinding.push_back(newBinding);
    m_BindingFlags.push_back({});
}

void VulkanDescriptorSet::AddBinding(u32 binding, vk::DescriptorType type, vk::ShaderStageFlags flags,
                                     u32 descriptorCount, vk::DescriptorBindingFlags bindingFlags)
{
    vk::DescriptorSetLayoutBinding newBinding{.binding = binding,
                                              .descriptorType = type,
                                              .descriptorCount = descriptorCount,
                                              .stageFlags = flags,
                                              .pImmutableSamplers = nullptr};
    m_BufferBinding.push_back(newBinding);
    m_BindingFlags.push_back(bindingFlags);
}

void VulkanDescriptorSet::BuildLayout(vk::Device device)
{
    bool hasFlags = false;
    for (auto flag : m_BindingFlags)
    {
        if (flag)
            hasFlags = true;
    }

    vk::DescriptorSetLayoutBindingFlagsCreateInfo extendedInfo{
        .bindingCount = static_cast<uint32_t>(m_BindingFlags.size()), .pBindingFlags = m_BindingFlags.data()};

    vk::DescriptorSetLayoutCreateInfo layoutInfo{.bindingCount = static_cast<uint32_t>(m_BufferBinding.size()),
                                                 .pBindings = m_BufferBinding.data()};

    if (hasFlags)
    {
        layoutInfo.pNext = &extendedInfo;
        layoutInfo.flags = vk::DescriptorSetLayoutCreateFlagBits::eUpdateAfterBindPool;
    }

    m_DescriptorSetLayout = device.createDescriptorSetLayout(layoutInfo);
}

void VulkanDescriptorSet::AllocateSet(vk::Device device, VulkanDescriptorPool* pool)
{
    vk::DescriptorSetAllocateInfo allocInfo{
        .descriptorPool = *pool->GetDescriptorPool(), .descriptorSetCount = 1, .pSetLayouts = &m_DescriptorSetLayout};
    m_DescriptorSet = device.allocateDescriptorSets(allocInfo)[0];
}

void VulkanDescriptorSet::WriteBuffer(vk::Device device, u32 binding, vk::Buffer buffer, vk::DeviceSize size,
                                      vk::DeviceSize offset)
{
    auto it = std::find_if(m_BufferBinding.begin(), m_BufferBinding.end(),
                           [binding](const vk::DescriptorSetLayoutBinding& b) { return b.binding == binding; });
    if (it == m_BufferBinding.end())
        return;

    vk::DescriptorBufferInfo bufferInfo{.buffer = buffer, .offset = offset, .range = size};

    vk::WriteDescriptorSet descriptorWrite{.dstSet = m_DescriptorSet,
                                           .dstBinding = binding,
                                           .dstArrayElement = 0,
                                           .descriptorCount = 1,
                                           .descriptorType = it->descriptorType,
                                           .pImageInfo = nullptr,
                                           .pBufferInfo = &bufferInfo,
                                           .pTexelBufferView = nullptr};

    device.updateDescriptorSets({descriptorWrite}, nullptr);
}

void VulkanDescriptorSet::WriteImage(vk::Device device, u32 binding, vk::ImageView imageView, vk::Sampler sampler,
                                     vk::ImageLayout layout)
{
    auto it = std::find_if(m_BufferBinding.begin(), m_BufferBinding.end(),
                           [binding](const vk::DescriptorSetLayoutBinding& b) { return b.binding == binding; });
    if (it == m_BufferBinding.end())
        return;

    vk::DescriptorImageInfo imageInfo{.sampler = sampler, .imageView = imageView, .imageLayout = layout};

    vk::WriteDescriptorSet descriptorWrite{.dstSet = m_DescriptorSet,
                                           .dstBinding = binding,
                                           .dstArrayElement = 0,
                                           .descriptorCount = 1,
                                           .descriptorType = it->descriptorType,
                                           .pImageInfo = &imageInfo,
                                           .pBufferInfo = nullptr,
                                           .pTexelBufferView = nullptr};

    device.updateDescriptorSets({descriptorWrite}, nullptr);
}

void VulkanDescriptorSet::Bind() {}

void VulkanDescriptorSet::DestroyDescriptorSet(vk::Device device)
{
    if (m_DescriptorSetLayout)
    {
        device.destroyDescriptorSetLayout(m_DescriptorSetLayout);
        m_DescriptorSetLayout = nullptr;
    }
    // We don't free the descriptor set individually because the pool will free it
}

} // namespace UHE::RHI::VULKAN
