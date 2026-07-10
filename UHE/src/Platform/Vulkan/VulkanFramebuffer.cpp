#include "uhepch.h"
#include "VulkanFramebuffer.h"
#include "VulkanContext.h"

namespace UHE::RHI::VULKAN
{

void VulkanFramebuffer::Init(const FramebufferDesc& desc)
{
    auto& ctx = GetVulkanContext();

    vk::FramebufferCreateInfo framebufferInfo{
        .flags = {},
        .renderPass = desc.renderPass,
        .attachmentCount = desc.attachmentCount,
        .pAttachments = desc.attachments,
        .width = desc.width,
        .height = desc.height,
        .layers = desc.layers
    };

    m_Framebuffer = vk::raii::Framebuffer(*ctx.logicalDeviceHandle, framebufferInfo);
}

void VulkanFramebuffer::Cleanup()
{
    m_Framebuffer.clear();
}

} // namespace UHE::RHI::VULKAN
