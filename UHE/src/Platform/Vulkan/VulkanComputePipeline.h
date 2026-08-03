#pragma once

namespace UHE::RHI::VULKAN
{
class VulkanComputePipeline
{
public:
    VulkanComputePipeline() = default;
    ~VulkanComputePipeline() = default;
    VulkanComputePipeline(VulkanComputePipeline&) = delete;
    VulkanComputePipeline operator=(VulkanComputePipeline&) = delete;
    void Init();
    void CreateComputePipeline();
    void ShutDownComputePipeline();
private:
};
}; // namespace UHE::RHI::VULKAN
