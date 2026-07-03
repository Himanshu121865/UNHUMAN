#pragma once
#include "Platform/Vulkan/VulkanDescriptorManager.h"
#include "UHE/RHI/RHITypes.h"

namespace UHE::RHI::VULKAN
{
class VulkanDescriptorSet
{
public:
    VulkanDescriptorSet() = default;
    ~VulkanDescriptorSet() = default;

    void Bind();

private:
};
} // namespace UHE::RHI::VULKAN
