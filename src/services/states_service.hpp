#pragma once

#include <QObject>

namespace hist {
    class StatesService final {
        Q_DISABLE_COPY_MOVE(StatesService)

    public:
        static StatesService& instance() noexcept;

    private:
        StatesService() noexcept;

        ~StatesService() = default;
    };
}
