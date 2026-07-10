#pragma once
#include <vulkan/vulkan_raii.hpp>
#include <vk_mem_alloc.h>
#include "UHE/Core/Core.h"

namespace UHE::RHI::VULKAN
{

class VulkanInstance;
class VulkanPhysicalDevice;
class VulkanLogicalDevice;
class VulkanSwapChain;
class VulkanDevice;
class VulkanDescriptorManager;

struct VulkanContext
{
    VulkanInstance* instance = nullptr;
    VulkanPhysicalDevice* physicalDevice = nullptr;
    VulkanLogicalDevice* logicalDevice = nullptr;
    VulkanSwapChain* swapChain = nullptr;
    VulkanDevice* device = nullptr;
    VulkanDescriptorManager* descriptorManager = nullptr;

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
