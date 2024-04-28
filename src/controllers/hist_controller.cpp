#include "hist_controller.hpp"

#include "../services/navigation_service.hpp"
#include "hist_page_controller.hpp"

namespace hist {
    HistController::HistController(QObject* parent) noexcept
        : QObject{ parent },
          _model{ std::make_unique<model::HistModel>() }
    {
        auto* histPageController = &HistPageController::instance();
        connect(histPageController, &HistPageController::fileSelected,
                this, &HistController::saveSelectedFilePath);
        connect(histPageController, &HistPageController::startRead,
                this, &HistController::read);
    }

    void HistController::init() noexcept {
        emit NavigationService::instance().changePage("qrc:/qml/pages/Hist.qml");
    }

    void HistController::saveSelectedFilePath(QUrl path) noexcept {
        _model->setSelectedFilePath(std::move(path));
    }

    void HistController::read() noexcept {
        const QUrl selectedFilePath = _model->getSelectedFilePath();
        // TODO:
    }
}

