#include "thread_pool.hpp"

namespace hist::tools {
    ThreadPool::ThreadPool(std::size_t threads) noexcept
        : _pool{ threads }
    {}

    void ThreadPool::wait() noexcept {
        _pool.join();
    }
}
