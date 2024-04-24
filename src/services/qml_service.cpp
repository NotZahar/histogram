#include "qml_service.hpp"

namespace hist {
    QMLService& QMLService::instance() noexcept {
        static QMLService instance;
        return instance;
    }

    void QMLService::init() noexcept {
        _startView = std::make_unique<QQuickView>();
        _startView->setSource(QUrl("qrc:/qml/pages/main.qml"));

        assert(_startView->status() != QQuickView::Error);
        _startView->setResizeMode(QQuickView::SizeRootObjectToView);
        _startView->show();
    }
}

