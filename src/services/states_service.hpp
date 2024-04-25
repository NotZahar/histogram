#pragma once

#include <QObject>

namespace hist {
    class StatesService final {
    public:
        Q_DISABLE_COPY_MOVE(StatesService)

        static StatesService& instance() noexcept;

    private:
        StatesService() noexcept;

        ~StatesService() = default;
    };
}
