#pragma once

#include <memory>

#include <QObject>
#include <QRegularExpression>

#include "../models/hist_model.hpp"

namespace hist {
    class HistController final : public QObject {
        Q_OBJECT

    public:
        explicit HistController(QObject* parent = nullptr) noexcept;

        ~HistController() = default;

        void init() noexcept;

    signals:
        void fileSizeChanged(qint64 size);
        void handleWord(QString word);
        void isReadingChanged(bool isReading);

    private:
        void setSelectedFilePath(QUrl path) noexcept;
        void setSelectedFileSize(qint64 size) noexcept;
        void read() noexcept;
        void toStatistics(QString word) noexcept;

        std::unique_ptr<model::HistModel> _model;
        const QRegularExpression _nonWordRegExp;
    };
}
