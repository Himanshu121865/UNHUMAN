#pragma once

namespace UHE::RHI::VULKAN
{
class VulkanFramebuffer
{
public:
    VulkanFramebuffer() = default;
    ~VulkanFramebuffer() = default;
    VulkanFramebuffer(const VulkanFramebuffer&) = delete;
    VulkanFramebuffer operator=(const VulkanFramebuffer&) = delete;
    void init();
};
}; // namespace UHE::RHI::VULKAN
