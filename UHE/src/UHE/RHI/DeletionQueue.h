#pragma once
#include <functional>
#include <vector>

namespace UHE::RHI {


class DeletionQueue {
public:
    void Push(std::function<void()>&& fn) {
        m_deletors.push_back(std::move(fn));
    }

    /// Flush all pending deletions in LIFO order (reverse of creation).
    void Flush() {
        while (!m_deletors.empty()) {
            std::vector<std::function<void()>> temp;
            temp.swap(m_deletors);
            for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
                if (*it) {
                    (*it)();
                }
            }
        }
    }

    [[nodiscard]] bool Empty() const { return m_deletors.empty(); }
    [[nodiscard]] size_t Size() const { return m_deletors.size(); }

private:
    std::vector<std::function<void()>> m_deletors;
};

} // namespace UHE::RHI
