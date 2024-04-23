#include "app.h"

#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>

#include "config/settings.hpp"

namespace hist {
    App& App::instance(int argc, char **argv) {
        static App instance{ argc, argv };
        return instance;
    }

    int App::run() {
        return _app.exec();
    }

    App::App(int argc, char **argv) noexcept
        : _app{ argc, argv }
    {
        QCoreApplication::setOrganizationName(settings::organizationName);
        QCoreApplication::setApplicationName(settings::applicationName);

        QGuiApplication app(argc, argv);

        QQuickView view;
        view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);
        view.setSource(QUrl("qrc:/qml/pages/app.qml"));
        assert(view.status() != QQuickView::Error);

        view.setResizeMode(QQuickView::SizeRootObjectToView);
        view.show();
    }
}
