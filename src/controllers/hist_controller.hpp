#pragma once

#include <QObject>

namespace hist {
    class HistController final : public QObject {
        Q_OBJECT

    public:
        explicit HistController(QObject* parent = nullptr) noexcept;

        ~HistController() = default;

        void init() noexcept;

//    signals:
//        void done();
    };
}
