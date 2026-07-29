#pragma once

namespace UHE::RHI::VULKAN
{
class VulkanFence
{
public:
    VulkanFence() = default;
    ~VulkanFence() = default;
    VulkanFence(VulkanFence&) = delete;
    VulkanFence operator=(VulkanFence) = delete;

    void Init();

private:
};
} // namespace UHE::RHI::VULKAN
