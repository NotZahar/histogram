#pragma once

#include <QObject>
#include <QGuiApplication>

namespace hist {
    class Storage final {
    public:
        Q_DISABLE_COPY_MOVE(Storage)

        static Storage& instance() noexcept;

        void setAppPtr(QGuiApplication* app) noexcept;
        QGuiApplication* getAppPtr() const noexcept;

    private:
        Storage() noexcept;

        ~Storage() = default;

        QGuiApplication* _app;
    };
}
