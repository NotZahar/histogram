#pragma once

#include <QObject>
#include <QGuiApplication>

namespace hist {
    class Storage final {
    public:
        Q_DISABLE_COPY_MOVE(Storage)

        static Storage& instance() noexcept;

    private:
        Storage() noexcept = default;

        ~Storage() = default;
    };
}
