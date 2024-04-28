#pragma once

#include <QObject>

#include <boost/asio.hpp>

namespace hist::tools {
    class ThreadPool {
        Q_DISABLE_COPY_MOVE(ThreadPool)

    public:
        ThreadPool() = delete;
        explicit ThreadPool(std::size_t threads) noexcept;

        ~ThreadPool() = default;

        template <class Task>
        void addTask(Task&& function) {
            boost::asio::post(_pool, std::move(function));
        }

        void wait() noexcept;

    private:
        boost::asio::thread_pool _pool;
    };
}
