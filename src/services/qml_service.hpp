#pragma once

#include <memory>

#include <QObject>
#include <QQuickView>

namespace hist {
    class QMLService final {
        Q_DISABLE_COPY_MOVE(QMLService)

    public:
        static QMLService& instance() noexcept;
        void init() noexcept;

    private:
        QMLService() noexcept = default;

        ~QMLService() = default;

        std::unique_ptr<QQuickView> _mainView;
    };
}
