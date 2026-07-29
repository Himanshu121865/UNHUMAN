#pragma once
#include <vk_mem_alloc.h>
#include <vulkan/vulkan_raii.hpp>
#include "UHE/Core/Core.h"

namespace UHE::RHI::VULKAN
{

class VulkanInstance;
class VulkanPhysicalDevice;
class VulkanLogicalDevice;
class VulkanSwapChain;
class VulkanDevice;
class VulkanDescriptorManager;
class VulkanExtensionCheck;
class VulkanGraphicPipeline;

struct VulkanContext
{
    VulkanInstance* instance = nullptr;
    VulkanPhysicalDevice* physicalDevice = nullptr;
    VulkanLogicalDevice* logicalDevice = nullptr;
    VulkanExtensionCheck* CheckExtensions = nullptr;
    VulkanSwapChain* swapChain = nullptr;
    VulkanDevice* device = nullptr;
    VulkanDescriptorManager* descriptorManager = nullptr;
    VulkanGraphicPipeline* graphicPipeline;

    VmaAllocator allocator = nullptr;
    vk::raii::Device* logicalDeviceHandle = nullptr;
    vk::raii::PhysicalDevice* physicalDeviceHandle = nullptr;
    vk::raii::Instance* instanceHandle = nullptr;
    vk::raii::Queue* graphicsQueue = nullptr;
    vk::raii::SurfaceKHR* surface = nullptr;

    u32 graphicsQueueFamilyIndex = 0;
    u32 currentFrameIndex = 0;
    u32 imageIndex = 0;
};

extern VulkanContext* g_VulkanContext;

inline VulkanContext& GetVulkanContext()
{
    return *g_VulkanContext;
}

} // namespace UHE::RHI::VULKAN
