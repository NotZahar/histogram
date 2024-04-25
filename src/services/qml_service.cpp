#include "qml_service.hpp"

namespace hist {
    QMLService& QMLService::instance() noexcept {
        static QMLService instance;
        return instance;
    }

    void QMLService::init() noexcept {
        _mainView = std::make_unique<QQuickView>();
        _mainView->setSource(QUrl("qrc:/qml/pages/Main.qml"));

        assert(_mainView->status() != QQuickView::Error);
        _mainView->setResizeMode(QQuickView::SizeRootObjectToView);
        _mainView->show();
    }
}

