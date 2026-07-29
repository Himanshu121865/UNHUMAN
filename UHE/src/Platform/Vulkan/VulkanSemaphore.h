#pragma once

namespace UHE::RHI::VULKAN
{
class VulkanSemaphore
{
public:
    VulkanSemaphore() = default;
    ~VulkanSemaphore() = default;
    VulkanSemaphore(VulkanSemaphore&) = delete;
    VulkanSemaphore operator=(VulkanSemaphore&) = delete;

    void Init();

private:
};

} // namespace UHE::RHI::VULKAN
