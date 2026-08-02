#pragma once
#include <vulkan/vulkan_raii.hpp>

namespace UHE::RHI::VULKAN
{
class VulkanContext;    
class VulkanDescriptorPool
{
public:
    VulkanDescriptorPool() = default;
    ~VulkanDescriptorPool() = default;
    VulkanDescriptorPool(VulkanDescriptorPool&) = delete;
    VulkanDescriptorPool operator=(VulkanDescriptorPool&) = delete;
    void Init(VulkanContext* context);
    void CreateDescriptorPool();
    void DestroyDescriptorPool();

private:    
   static constexpr uint32_t MAX_BINDLESS_RESOURCES = 10000;
   VulkanContext* m_Context = nullptr;
   vk::raii::DescriptorPool m_DescriptorPool = nullptr;
};
} // namespace UHE::RHI::VULKAN
