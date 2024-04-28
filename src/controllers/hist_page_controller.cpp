#include "hist_page_controller.hpp"

#include <QDebug> // TODO:

namespace hist {
    HistPageController::HistPageController(QObject* parent) noexcept
        : QObject{ parent },
          _openEnabled{ true },
          _startEnabled{ false },
          _cancelEnabled{ true },
          _processProgressValue{ 0 },
          _isReading{ false }
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

    int HistPageController::processProgressValue() const noexcept {
        return _processProgressValue;
    }

    void HistPageController::setProcessProgressValue(int value) noexcept {
        if (_processProgressValue == value)
            return;
        _processProgressValue = value;
        emit processProgressValueChanged();
    }

    void HistPageController::setIsReading(bool isReading) noexcept {
        _isReading = isReading;
    }

    void HistPageController::onFileSelected(QUrl path) noexcept {
        setStartEnabled(true);
        emit fileSelected(path);
    }

    void HistPageController::onStarted() noexcept {
        if (_isReading)
            return;

        setStartEnabled(false);
        emit startRead();
    }

    void HistPageController::onCanceled() noexcept {
        // TODO: Implement logic!
    }

    void HistPageController::onHandleWord(QString word) noexcept {
        (void)word;
//        qDebug() << word;
    }
}
