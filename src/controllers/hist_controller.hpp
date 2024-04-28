#pragma once

#include <memory>

#include <QObject>

#include "../models/hist_model.hpp"

namespace hist {
    class HistController final : public QObject {
        Q_OBJECT

    public:
        explicit HistController(QObject* parent = nullptr) noexcept;

        ~HistController() = default;

        void init() noexcept;

    private:
        void saveSelectedFilePath(QUrl path) noexcept;
        void read() noexcept;

        std::unique_ptr<model::HistModel> _model;
    };
}
