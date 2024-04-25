#include "states_service.hpp"

#include "../app_states/state_manager.hpp"
#include "../app_states/init_state.hpp"

namespace hist {
    StatesService::StatesService() noexcept
    {
        auto& stateManager = hist::StateManager::instance();

        stateManager.addNewState(std::make_unique<hist::InitState>());

        stateManager.init(hist::state::init);
    }

    StatesService& StatesService::instance() noexcept {
        static StatesService instance;
        return instance;
    }
}

