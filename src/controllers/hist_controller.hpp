#pragma once

#include <memory>

#include <QObject>
#include <QRegularExpression>

#include "../models/hist_model.hpp"

namespace hist {
    class HistController final : public QObject {
        Q_OBJECT

        struct Diffs {};

    public:
        explicit HistController(QObject* parent = nullptr) noexcept;

        ~HistController() = default;

        void init() noexcept;

    signals:
        void isReadingChanged(bool isReading);

    private:
        void setSelectedFilePath(QUrl path) noexcept;
        void read() noexcept;
        Diffs getDiffs(const structures::WordsStatistics::topWords_t& topWords) const noexcept;

        std::unique_ptr<model::HistModel> _model;
        const QRegularExpression _nonWordRegExp;
    };
}
