#pragma once

namespace UHE::RHI::VULKAN
{
class VulkanDescriptorPool
{
public:
    VulkanDescriptorPool() = default;
    ~VulkanDescriptorPool() = default;
    VulkanDescriptorPool(VulkanDescriptorPool&) = delete;
    VulkanDescriptorPool operator=(VulkanDescriptorPool&) = delete;
    void Init();

private:    
};
} // namespace UHE::RHI::VULKAN
