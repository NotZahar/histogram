#pragma once

#include <QObject>
#include <QGuiApplication>

namespace hist {
    class Storage final {
        Q_DISABLE_COPY_MOVE(Storage)

    public:
        static Storage& instance() noexcept;

    private:
        Storage() noexcept = default;

        ~Storage() = default;
    };
}
