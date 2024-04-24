#pragma once

#include <QObject>

namespace hist {
    class InitController final : public QObject {
        Q_OBJECT

    public:
        explicit InitController(QObject* parent = nullptr) noexcept;

        ~InitController() = default;

        void init() noexcept;

    signals:
        void done();
    };
}
