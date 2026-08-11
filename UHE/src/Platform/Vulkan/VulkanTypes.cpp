#include "VulkanTypes.h"
#include "UHE/RHI/RHITypes.h"
#include "UHE/Renderer/Shader.h"
#include "vulkan/vulkan.hpp"

namespace UHE::RHI::VULKAN
{
vk::Format MapTextureFormat(TextureFormat format)
{
    switch (format)
    {
        case TextureFormat::RGBA8_UNORM:
            return vk::Format::eR8G8B8A8Unorm;
        case TextureFormat::RGBA8_SRGB:
            return vk::Format::eR8G8B8A8Srgb;
        case TextureFormat::BGRA8_UNORM:
            return vk::Format::eB8G8R8A8Unorm;
        case TextureFormat::BGRA8_SRGB:
            return vk::Format::eB8G8R8A8Srgb;
        case TextureFormat::D24_UNORM_S8:
            return vk::Format::eD32SfloatS8Uint;
        case TextureFormat::D32_FLOAT:
            return vk::Format::eD32Sfloat;
        case TextureFormat::R32_SINT:
            return vk::Format::eR32Sint;
        default:
            return vk::Format::eUndefined;
    }
}

vk::PrimitiveTopology MapTopology(PrimitiveTopology topology)
{
    switch (topology)
    {
        case PrimitiveTopology::TriangleList:
            return vk::PrimitiveTopology::eTriangleList;
        case PrimitiveTopology::TriangleStrip:
            return vk::PrimitiveTopology::eTriangleStrip;
        case PrimitiveTopology::LineList:
            return vk::PrimitiveTopology::eLineList;
        case PrimitiveTopology::PointList:
            return vk::PrimitiveTopology::ePointList;
    }
    return vk::PrimitiveTopology::eTriangleList;
}

vk::Format ShaderDataTypeToVulkanFormat(ShaderDataType type)
{
    switch (type)
    {
        case ShaderDataType::Float:
            return vk::Format::eR32Sfloat;
        case ShaderDataType::Float2:
            return vk::Format::eR32G32Sfloat;
        case ShaderDataType::Float3:
            return vk::Format::eR32G32B32Sfloat;
        case ShaderDataType::Float4:
            return vk::Format::eR32G32B32A32Sfloat;
        case ShaderDataType::Int:
            return vk::Format::eR32Sint;
        case ShaderDataType::Int2:
            return vk::Format::eR32G32Sint;
        case ShaderDataType::Int3:
            return vk::Format::eR32G32B32Sint;
        case ShaderDataType::Int4:
            return vk::Format::eR32G32B32A32Sint;
        case ShaderDataType::Mat3:
            return vk::Format::eR32G32B32Sfloat;
        case ShaderDataType::Mat4:
            return vk::Format::eR32G32B32A32Sfloat;
        case ShaderDataType::Bool:
            return vk::Format::eR32Uint;
        case ShaderDataType::None:
            return vk::Format::eUndefined;
    }
    return vk::Format::eUndefined;
}

vk::Format ToVkFormat(TextureFormat format)
{
    switch (format)
    {
        case TextureFormat::RGBA8_UNORM:
            return vk::Format::eR8G8B8A8Unorm;
        case TextureFormat::RGBA8_SRGB:
            return vk::Format::eR8G8B8A8Srgb;
        case TextureFormat::BGRA8_UNORM:
            return vk::Format::eB8G8R8A8Unorm;
        case TextureFormat::BGRA8_SRGB:
            return vk::Format::eB8G8R8A8Srgb;
        case TextureFormat::D24_UNORM_S8:
            return vk::Format::eD32SfloatS8Uint;
        case TextureFormat::D32_FLOAT:
            return vk::Format::eD32Sfloat;
        case TextureFormat::R32_SINT:
            return vk::Format::eR32Sint;
        default:
            return vk::Format::eUndefined;
    }
}

vk::SampleCountFlagBits ToVkSample(u32 sampleCount)
{
    switch (sampleCount)
    {
        case 1:
            return vk::SampleCountFlagBits::e1;
        case 2:
            return vk::SampleCountFlagBits::e2;
        case 4:
            return vk::SampleCountFlagBits::e4;
        case 8:
            return vk::SampleCountFlagBits::e8;
        case 16:
            return vk::SampleCountFlagBits::e16;
        case 32:
            return vk::SampleCountFlagBits::e32;
        case 64:
            return vk::SampleCountFlagBits::e64;
        default:
            return vk::SampleCountFlagBits::e1;
    }
}

vk::AttachmentLoadOp ToVkLoadOp(LoadOp loadOp)
{
    switch (loadOp)
    {
        case LoadOp::Load:
            return vk::AttachmentLoadOp::eLoad;
        case LoadOp::Clear:
            return vk::AttachmentLoadOp::eClear;
        case LoadOp::DontCare:
            return vk::AttachmentLoadOp::eDontCare;
        default:
            return vk::AttachmentLoadOp::eDontCare;
    }
}

vk::AttachmentStoreOp ToVkStoreOp(StoreOp storeOp)
{
    switch (storeOp)
    {
        case StoreOp::Store:
            return vk::AttachmentStoreOp::eStore;
        case StoreOp::DontCare:
            return vk::AttachmentStoreOp::eDontCare;
        default:
            return vk::AttachmentStoreOp::eDontCare;
    }
}

vk::ImageLayout ToVkImageLayout(TextureUsage usage)
{
    if (usage & TextureUsage::ColorAttach)
        return vk::ImageLayout::eColorAttachmentOptimal;
    else if (usage & TextureUsage::DepthAttach)
        return vk::ImageLayout::eDepthStencilAttachmentOptimal;
    else if (usage & TextureUsage::Sampled)
        return vk::ImageLayout::eShaderReadOnlyOptimal;
    else if (usage & TextureUsage::Storage)
        return vk::ImageLayout::eGeneral;
    else
        return vk::ImageLayout::eUndefined;
}

vk::DescriptorType ToVkDescriptorType(BufferUsageFlags usage)
{
    switch (usage)
    {
        case BufferUsageFlags::None:
            UHE_CORE_ASSERT(false, "Cannot convert BufferUsageFlags::None to a valid Vulkan Descriptor Type!");
            return vk::DescriptorType::eUniformBuffer;
        case BufferUsageFlags::Sampler:
            return vk::DescriptorType::eSampler;
        case BufferUsageFlags::CombinedImageSampler:
            return vk::DescriptorType::eCombinedImageSampler;
        case BufferUsageFlags::SampledImage:
            return vk::DescriptorType::eSampledImage;
        case BufferUsageFlags::StorageImage:
            return vk::DescriptorType::eStorageImage;
        case BufferUsageFlags::UniformTexelBuffer:
            return vk::DescriptorType::eUniformTexelBuffer;
        case BufferUsageFlags::StorageTexelBuffer:
            return vk::DescriptorType::eStorageTexelBuffer;
        case BufferUsageFlags::UniformBuffer:
            return vk::DescriptorType::eUniformBuffer;
        case BufferUsageFlags::StorageBuffer:
            return vk::DescriptorType::eStorageBuffer;
        case BufferUsageFlags::UniformBufferDynamic:
            return vk::DescriptorType::eUniformBufferDynamic;
        case BufferUsageFlags::StorageBufferDynamic:
            return vk::DescriptorType::eStorageBufferDynamic;
        case BufferUsageFlags::InputAttachment:
            return vk::DescriptorType::eInputAttachment;
        case BufferUsageFlags::InlineUniformBlock:
            return vk::DescriptorType::eInlineUniformBlock;
        case BufferUsageFlags::InlineUniformBlockEXT:
            return vk::DescriptorType::eInlineUniformBlockEXT;
        case BufferUsageFlags::AccelerationStructureKHR:
            return vk::DescriptorType::eAccelerationStructureKHR;
        case BufferUsageFlags::AccelerationStructureNV:
            return vk::DescriptorType::eAccelerationStructureNV;
        case BufferUsageFlags::SampleWeightImageQCOM:
            return vk::DescriptorType::eSampleWeightImageQCOM;
        case BufferUsageFlags::BlockMatchImageQCOM:
            return vk::DescriptorType::eBlockMatchImageQCOM;
        case BufferUsageFlags::TensorARM:
            return vk::DescriptorType::eTensorARM;
        case BufferUsageFlags::MutableEXT:
            return vk::DescriptorType::eMutableEXT;
        case BufferUsageFlags::MutableVALVE:
            return vk::DescriptorType::eMutableVALVE;
        case BufferUsageFlags::PartitionedAccelerationStructureNV:
            return vk::DescriptorType::ePartitionedAccelerationStructureNV;
        default:
            UHE_CORE_ASSERT(false, "Invalid BufferUsageFlags!");
            return vk::DescriptorType::eUniformBuffer;
    }
}

} // namespace UHE::RHI::VULKAN
