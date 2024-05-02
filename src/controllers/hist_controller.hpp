#pragma once

#include <memory>
#include <list>

#include <QObject>
#include <QRegularExpression>
#include <QSharedPointer>

#include "../models/hist_model.hpp"

namespace hist {
    class HistController final : public QObject {
        Q_OBJECT

    public:
        explicit HistController(QObject* parent = nullptr) noexcept;

        ~HistController() = default;

        void init() noexcept;

    signals:
        void isReadingChanged(bool isReading);
        void histDataChanged(std::list<QSharedPointer<structures::Diff>> diffs);
        void readedWordsCountChanged(int words);
        void readProgressChanged(qreal value);
        void clearHistView();

    private:
        void setSelectedFilePath(QUrl path) noexcept;
        void read() noexcept;
        std::list<QSharedPointer<structures::Diff>> getDiffs(structures::WordsStatistics::topWords_t topWords) noexcept;
        void clearHistData() noexcept;

        std::unique_ptr<model::HistModel> _model;
        const QRegularExpression _nonWordRegExp;
    };
}
