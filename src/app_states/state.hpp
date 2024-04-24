#pragma once

#include <QObject>

#include "states.hpp"

namespace hist {
    class State : public QObject {
        Q_OBJECT

    public:
        virtual void start() noexcept = 0;
        virtual void finish() noexcept = 0;
        state getStateId() const noexcept;

        virtual ~State() = default;

    protected:
        State() = delete;
        explicit State(const state stateId, QObject* parent = nullptr) noexcept;


    private:
        const state _stateId;
    };
}
