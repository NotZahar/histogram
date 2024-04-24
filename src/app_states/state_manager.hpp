#pragma once

#include <memory>
#include <unordered_map>

#include <QObject>

#include "state.hpp"

namespace hist {
    class StateManager final : public QObject {
        Q_OBJECT

    public:
        static StateManager& instance() noexcept;

        bool stateExists(const state stateId) const noexcept;
        void addNewState(std::unique_ptr<State> newState) noexcept;
        void setStateAsCurrent(const state stateId) noexcept;
        state getCurrentState() const noexcept;
        void init(const state stateId) noexcept;
        void clear() noexcept;

    private:
        explicit StateManager(QObject* parent = nullptr) noexcept;

        ~StateManager() = default;

        std::unordered_map<state, std::unique_ptr<State>> _states;
        state _currentStateId;
    };
}
