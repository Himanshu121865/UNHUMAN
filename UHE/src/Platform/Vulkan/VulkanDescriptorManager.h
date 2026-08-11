#pragma once
#include <vulkan/vulkan_raii.hpp>

namespace UHE::RHI::VULKAN
{
class VulkanDevice;
class VulkanDescriptorManager
{
public:
    VulkanDescriptorManager() = default;
    VulkanDescriptorManager(const VulkanDescriptorManager&) = delete;
    VulkanDescriptorManager& operator=(const VulkanDescriptorManager&) = delete;

    void init(VulkanDevice& device);
    u32 RegisterBuffer(vk::raii::Device& device, vk::Buffer buffer, vk::DeviceSize size);
    u32 BindTexture(vk::raii::Device& device, vk::ImageView imageView, vk::Sampler sampler);
    void UpdateDescriptorWithSameState(vk::raii::Device& device, vk::DescriptorSet DescriptorSet,
                                       const std::vector<vk::WriteDescriptorSet>& writeDescriptorSets);
    void UpdateDescriptorWithNewState(vk::raii::Device& device, vk::DescriptorSet DescriptorSet,
                                      const std::vector<vk::WriteDescriptorSet>& writeDescriptorSets);
    void cleanup();

    [[nodiscard]] vk::DescriptorSetLayout GetLayoutHandle() const { return *m_DescriptorSetLayout; }
    [[nodiscard]] vk::DescriptorSet GetSetHandle() const { return *m_GlobalDescriptorSet; }

    [[nodiscard]] u32& GetNextBufferIndex() { return m_NextBufferIndex; }
    [[nodiscard]] u32& GetNextTextureIndex() { return m_NextTextureIndex; }

    [[nodiscard]] const u32& GetBufferIndex() const { return m_NextBufferIndex; }
    [[nodiscard]] const u32& GetTextureIndex() const { return m_NextTextureIndex; }
    [[nodiscard]] const u32& GetMaxBindlessResourceCount() const { return MAX_BINDLESS_RESOURCES; }

    [[nodiscard]] const vk::Device& GetDevice() const { return mdevice; }

    [[nodiscard]] const vk::raii::DescriptorPool& GetDescriptorPool() const { return m_DescriptorPool; }
    [[nodiscard]] const vk::raii::DescriptorSetLayout& GetDescriptorSetLayout() const { return m_DescriptorSetLayout; }
    [[nodiscard]] const vk::raii::DescriptorSet& GetDescriptorSet() const { return m_GlobalDescriptorSet; }

    [[nodiscard]] vk::raii::DescriptorPool& GetDescriptorPool() { return m_DescriptorPool; }
    [[nodiscard]] vk::raii::DescriptorSetLayout& GetDescriptorSetLayout() { return m_DescriptorSetLayout; }
    [[nodiscard]] vk::raii::DescriptorSet& GetDescriptorSet() { return m_GlobalDescriptorSet; }

private:
    vk::Device mdevice;
    vk::raii::DescriptorPool m_DescriptorPool = nullptr;
    vk::raii::DescriptorSetLayout m_DescriptorSetLayout = nullptr;
    vk::raii::DescriptorSet m_GlobalDescriptorSet = nullptr;
    static constexpr uint32_t MAX_BINDLESS_RESOURCES = 10000;
    uint32_t m_NextBufferIndex = 0;
    uint32_t m_NextTextureIndex = 0;
};
} // namespace UHE::RHI::VULKAN
