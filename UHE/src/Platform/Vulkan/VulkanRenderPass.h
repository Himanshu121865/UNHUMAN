#pragma once

namespace UHE::RHI::VULKAN
{
class VulkanRenderPass
{
public:
    VulkanRenderPass() = default;
    ~VulkanRenderPass() = default;
    VulkanRenderPass(VulkanRenderPass& obj) = delete;

    void Init();

private:
};
} // namespace UHE::RHI::VULKAN
