
namespace UHE::RHI::VULKAN
{
class VulkanExtensionCheck
{
    VulkanExtensionCheck() = default;
    ~VulkanExtensionCheck() = default;
    void SetContext();
    [[nodiscard]] bool IsInstanceVulkanExtensionEnable() noexcept { return false; }
    [[nodiscard]] bool IsPhysicalVulkanExtensionEnable() noexcept { return false; }
};

} // namespace UHE::RHI::VULKAN
