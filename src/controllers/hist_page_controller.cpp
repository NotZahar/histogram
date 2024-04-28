#include "hist_page_controller.hpp"

namespace hist {
    HistPageController::HistPageController(QObject* parent) noexcept
        : QObject{ parent },
          _openEnabled{ true },
          _startEnabled{ true },
          _cancelEnabled{ true }
    {}

    HistPageController& HistPageController::instance() noexcept {
        static HistPageController instance;
        return instance;
    }

    bool HistPageController::openEnabled() const noexcept {
        return _openEnabled;
    }

    void HistPageController::setOpenEnabled(bool enabled) noexcept {
        if (_openEnabled == enabled)
            return;
        _openEnabled = enabled;
        emit openEnabledChanged();
    }

    bool HistPageController::startEnabled() const noexcept {
        return _startEnabled;
    }

    void HistPageController::setStartEnabled(bool enabled) noexcept {
        if (_startEnabled == enabled)
            return;
        _startEnabled = enabled;
        emit startEnabledChanged();
    }

    bool HistPageController::cancelEnabled() const noexcept {
        return _cancelEnabled;
    }

    void HistPageController::setCancelEnabled(bool enabled) noexcept {
        if (_cancelEnabled == enabled)
            return;
        _cancelEnabled = enabled;
        emit cancelEnabledChanged();
    }

    void HistPageController::onFileSelected(QUrl path) noexcept {
        emit fileSelected(path);
    }

    void HistPageController::onStarted() noexcept {
        setOpenEnabled(false);
        setStartEnabled(false);
        emit startRead();
    }

    void HistPageController::onCanceled() noexcept {
        // TODO: Implement!
    }
}
