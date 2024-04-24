#pragma once

#include "state.hpp"
#include "../controllers/init_controller.hpp"

namespace hist {
    class InitState final : public State {
        Q_OBJECT

    public:
        explicit InitState(QObject* parent = nullptr) noexcept;

        ~InitState() override = default;

        void start() noexcept override;
        void finish() noexcept override;

    private slots:
        void onHistogramTransfer();

    private:
        InitController _initController;
    };
}
