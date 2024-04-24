#include "storage.hpp"

namespace hist {
    Storage::Storage() noexcept
        : _app{ nullptr }
    {}

    Storage& Storage::instance() noexcept {
        static Storage instance;
        return instance;
    }

    void Storage::setAppPtr(QGuiApplication* app) noexcept {
        _app = app;
    }

    QGuiApplication* Storage::getAppPtr() const noexcept {
        return _app;
    }
}

