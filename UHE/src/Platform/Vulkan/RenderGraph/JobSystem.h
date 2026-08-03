#pragma once

namespace UHE::RHI::VULKAN
{
class JobSystem
{
public:
    JobSystem() = default;
    ~JobSystem() = default;
    JobSystem(JobSystem&) = delete;
    JobSystem operator=(JobSystem&) = delete;

    void Init();
    void Cleanup();
};
} // namespace UHE::RHI::VULKAN
