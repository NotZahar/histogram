#include "init_controller.hpp"

#include "../services/qml_service.hpp"

namespace hist {
    InitController::InitController(QObject* parent) noexcept
        : QObject{ parent }
    {}

    void InitController::init() noexcept {
        QMLService::instance().init();
        emit done();
    }
}

