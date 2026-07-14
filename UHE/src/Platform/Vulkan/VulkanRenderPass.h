#pragma once
#include <vulkan/vulkan_raii.hpp>
#include "UHE/RHI/RHITypes.h"
namespace UHE::RHI::VULKAN
{

class VulkanContext;
class VulkanRenderPass
{
public:
    VulkanRenderPass() = default;
    ~VulkanRenderPass() = default;
    VulkanRenderPass(VulkanRenderPass&) = delete;
    VulkanRenderPass operator=(VulkanRenderPass&) = delete;
    void Init(VulkanContext& ctx, UHE::RHI::RenderPassDesc& desc);

    // TODO
    // implement the RenderPass Builder Feature so it can run better in old hardware

private:
};
} // namespace UHE::RHI::VULKAN
