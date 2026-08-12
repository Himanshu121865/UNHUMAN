#pragma once
#include <vulkan/vulkan_raii.hpp>
#include "Platform/Vulkan/VulkanDescriptorPool.h"
#include "Platform/Vulkan/VulkanDescriptorSet.h"

namespace UHE::RHI::VULKAN
{
class DescriptorBuilder
{
public:
    DescriptorBuilder() = default;

    DescriptorBuilder& BindBuffer(u32 binding, vk::DescriptorBufferInfo* bufferInfo, vk::DescriptorType type, vk::ShaderStageFlags stageFlags);
    DescriptorBuilder& BindImage(u32 binding, vk::DescriptorImageInfo* imageInfo, vk::DescriptorType type, vk::ShaderStageFlags stageFlags);
    
    // For bindless array elements
    DescriptorBuilder& BindBufferArray(u32 binding, u32 arrayElement, vk::DescriptorBufferInfo* bufferInfo, vk::DescriptorType type);
    DescriptorBuilder& BindImageArray(u32 binding, u32 arrayElement, vk::DescriptorImageInfo* imageInfo, vk::DescriptorType type);

    void Build(vk::raii::Device& device, vk::DescriptorSet set);

private:
    std::vector<vk::WriteDescriptorSet> m_Writes;
    std::vector<vk::DescriptorBufferInfo> m_BufferInfos; // Keep alive until build
    std::vector<vk::DescriptorImageInfo> m_ImageInfos;   // Keep alive until build
};

class VulkanDevice;
class VulkanDescriptorManager
{
public:
    VulkanDescriptorManager() = default;
    VulkanDescriptorManager(const VulkanDescriptorManager&) = delete;
    VulkanDescriptorManager& operator=(const VulkanDescriptorManager&) = delete;

    void init(VulkanDevice& device);
    u32 RegisterBuffer(vk::raii::Device& device, vk::Buffer buffer, vk::DeviceSize size);
    void UnregisterBuffer(u32 slot);

    u32 BindTexture(vk::raii::Device& device, vk::ImageView imageView, vk::Sampler sampler);
    void UnbindTexture(u32 slot);
    void UpdateDescriptorWithSameState(vk::raii::Device& device, vk::DescriptorSet DescriptorSet,
                                       DescriptorBuilder& builder);
    void UpdateDescriptorWithNewState(vk::raii::Device& device, vk::DescriptorSet DescriptorSet,
                                      DescriptorBuilder& builder);
    void cleanup();

    [[nodiscard]] vk::DescriptorSetLayout GetLayoutHandle() const { return m_GlobalDescriptorSet.GetLayout(); }
    [[nodiscard]] vk::DescriptorSet GetSetHandle() const { return m_GlobalDescriptorSet.GetSet(); }

    [[nodiscard]] u32& GetNextBufferIndex() { return m_NextBufferIndex; }
    [[nodiscard]] u32& GetNextTextureIndex() { return m_NextTextureIndex; }

    [[nodiscard]] const u32& GetBufferIndex() const { return m_NextBufferIndex; }
    [[nodiscard]] const u32& GetTextureIndex() const { return m_NextTextureIndex; }
    [[nodiscard]] const u32& GetMaxBindlessResourceCount() const { return MAX_BINDLESS_RESOURCES; }

    [[nodiscard]] const vk::Device& GetDevice() const { return mdevice; }

    [[nodiscard]] const vk::raii::DescriptorPool& GetDescriptorPool() const
    {
        return m_FallbackDescriptorPool.GetDescriptorPool();
    }
    [[nodiscard]] vk::DescriptorSetLayout GetDescriptorSetLayout() const { return m_GlobalDescriptorSet.GetLayout(); }
    [[nodiscard]] vk::DescriptorSet GetDescriptorSet() const { return m_GlobalDescriptorSet.GetSet(); }

    [[nodiscard]] vk::raii::DescriptorPool& GetDescriptorPool() { return m_FallbackDescriptorPool.GetDescriptorPool(); }
    [[nodiscard]] vk::DescriptorSetLayout GetDescriptorSetLayout() { return m_GlobalDescriptorSet.GetLayout(); }
    [[nodiscard]] vk::DescriptorSet GetDescriptorSet() { return m_GlobalDescriptorSet.GetSet(); }

    [[nodiscard]] VulkanDescriptorPool* GetFallbackPool() { return &m_FallbackDescriptorPool; }

private:
    vk::Device mdevice;
    VulkanDescriptorSet m_GlobalDescriptorSet;
    VulkanDescriptorPool m_FallbackDescriptorPool;
    bool m_IsBindless = false;
    static constexpr uint32_t MAX_BINDLESS_RESOURCES = 10000;
    uint32_t m_NextBufferIndex = 0;
    uint32_t m_NextTextureIndex = 0;
    std::vector<u32> m_FreeBufferIndices;
    std::vector<u32> m_FreeTextureIndices;
};
} // namespace UHE::RHI::VULKAN
