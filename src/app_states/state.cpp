#include "state.hpp"

#include <cassert>

namespace hist {
    State::State(const state stateId, QObject* parent) noexcept
        : QObject{ parent },
          _stateId{ stateId }
    {
        assert(stateId != state::invalid);
    }

    state State::getStateId() const noexcept {
        return _stateId;
    }
}
