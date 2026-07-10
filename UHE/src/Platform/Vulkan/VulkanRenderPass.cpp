#include "VulkanRenderPass.h"
#include "Platform/Vulkan/VulkanContext.h"
#include "UHE/RHI/RHITypes.h"
#include "vulkan/vulkan.hpp"

namespace UHE::RHI::VULKAN
{
void VulkanRenderPass::Init(VulkanContext& ctx, const UHE::RHI::RenderPassDesc& renderdesc)

{
    vk::RenderPassCreateInfo{

    };
}
}; // namespace UHE::RHI::VULKAN
