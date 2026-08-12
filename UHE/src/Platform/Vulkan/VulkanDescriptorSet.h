#pragma once
#include <vector>
#include <vulkan/vulkan_raii.hpp>
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
    // Builder Methods
    void AddBinding(u32 binding, const UHE::RHI::BufferUsageFlags usage, vk::ShaderStageFlags flags,
                    u32 descriptorCount = 1);
    void AddBinding(u32 binding, vk::DescriptorType type, vk::ShaderStageFlags flags, u32 descriptorCount = 1,
                    vk::DescriptorBindingFlags bindingFlags = {});
    void BuildLayout(vk::Device device);
    void AllocateSet(vk::Device device, class VulkanDescriptorPool* pool);

    // Writers
    void WriteBuffer(vk::Device device, u32 binding, vk::Buffer buffer, vk::DeviceSize size, vk::DeviceSize offset = 0);
    void WriteImage(vk::Device device, u32 binding, vk::ImageView imageView, vk::Sampler sampler,
                    vk::ImageLayout layout = vk::ImageLayout::eShaderReadOnlyOptimal);

    void Bind();
    void DestroyDescriptorSet(vk::Device device);

    [[nodiscard]] vk::DescriptorSetLayout GetLayout() const { return m_DescriptorSetLayout; }
    [[nodiscard]] vk::DescriptorSet GetSet() const { return m_DescriptorSet; }

private:
    std::vector<vk::DescriptorSetLayoutBinding> m_BufferBinding;
    std::vector<vk::DescriptorBindingFlags> m_BindingFlags;
    vk::DescriptorSetLayout m_DescriptorSetLayout = nullptr;
    vk::DescriptorSet m_DescriptorSet = nullptr;
};
} // namespace UHE::RHI::VULKAN
