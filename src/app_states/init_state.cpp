#include "init_state.hpp"

#include "states.hpp"
#include "state_manager.hpp"

namespace hist {
    InitState::InitState(QObject* parent) noexcept
        : State{ state::init, parent },
          _initController{}
    {
        connect(&_initController, &InitController::done, this, &InitState::onHistogramTransfer);
    }

    void InitState::start() noexcept {
        _initController.init();
    }

    void InitState::finish() noexcept {
        // nothing
    }

    void InitState::onHistogramTransfer() {
        StateManager::instance().setStateAsCurrent(state::histogram);
    }
}
