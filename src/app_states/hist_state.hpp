#pragma once

#include "state.hpp"
#include "../controllers/hist_controller.hpp"

namespace hist {
    class HistState final : public State {
        Q_OBJECT

    public:
        explicit HistState(QObject* parent = nullptr) noexcept;

        ~HistState() override = default;

        void start() noexcept override;
        void finish() noexcept override;

//    private slots:
//        void onHistogramTransfer();

    private:
        HistController _histController;
    };
}
