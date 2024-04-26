#include "hist_controller.hpp"

#include "../services/navigation_service.hpp"

namespace hist {
    HistController::HistController(QObject* parent) noexcept
        : QObject{ parent }
    {}

    void HistController::init() noexcept {
        /*
            TODO: Создать синглтон контроллер HistogramPageController, прокинуть в qml, общаться через этот синлтон с qml
        */
        emit NavigationService::instance().changePage("qrc:/qml/pages/Hist.qml");
    }
}

