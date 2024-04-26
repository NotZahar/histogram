#include "hist_state.hpp"

#include "states.hpp"
//#include "state_manager.hpp"

namespace hist {
    HistState::HistState(QObject* parent) noexcept
        : State{ state::histogram, parent },
          _histController{}
    {
//        connect(&_initController, &InitController::done, this, &InitState::onHistogramTransfer);
    }

    void HistState::start() noexcept {
        _histController.init();
    }

    void HistState::finish() noexcept {
        // nothing
    }
}
