#include "state_manager.hpp"

#include <cassert>

namespace hist {
    StateManager::StateManager(QObject* parent) noexcept
        : QObject{ parent },
          _currentStateId{ state::invalid }
    {}

    StateManager& StateManager::instance() noexcept {
        static StateManager instance;
        return instance;
    }

    bool StateManager::stateExists(const state stateId) const noexcept {
        return _states.contains(stateId);
    }

    void StateManager::addNewState(std::unique_ptr<State> newState) noexcept {
        const state newStateId = newState->getStateId();
        if (stateExists(newStateId))
            return;
        assert(!stateExists(newStateId));
        _states.insert({ newStateId, std::move(newState) });
    }

    void StateManager::setStateAsCurrent(const state stateId) noexcept {
        assert(_currentStateId != state::invalid);
        assert(stateId != state::invalid);
        assert(stateExists(stateId));
        _states.at(_currentStateId)->finish();
        _currentStateId = stateId;
        _states.at(_currentStateId)->start();
    }

    state StateManager::getCurrentState() const noexcept {
        return _currentStateId;
    }

    void StateManager::init(const state stateId) noexcept {
        assert(_currentStateId == state::invalid);
        assert(stateId != state::invalid);
        assert(stateExists(stateId));
        _currentStateId = stateId;
        _states.at(_currentStateId)->start();
    }

    void StateManager::clear() noexcept {
        assert(_currentStateId != state::invalid);
        assert(!_states.empty());
        _states.at(_currentStateId)->finish();
        _states.clear();
    }
}
