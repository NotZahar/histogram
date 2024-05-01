#include "hist_controller.hpp"

#include <QDebug> // TODO: delete
#include <QFile>
#include <QtConcurrent>

#include "../services/navigation_service.hpp"
#include "hist_page_controller.hpp"

namespace hist {
    HistController::HistController(QObject* parent) noexcept
        : QObject{ parent },
          _model{ std::make_unique<model::HistModel>() },
          _nonWordRegExp{ "\\W+" }
    {
        auto* histPageController = &HistPageController::instance();
        connect(histPageController, &HistPageController::fileSelected,
                this, &HistController::setSelectedFilePath);
        connect(histPageController, &HistPageController::startRead,
                this, &HistController::read);
        connect(this, &HistController::isReadingChanged,
                histPageController, &HistPageController::setIsReading,
                Qt::QueuedConnection);
    }

    void HistController::init() noexcept {
        emit NavigationService::instance().changePage("qrc:/qml/pages/Hist.qml");
    }

    void HistController::setSelectedFilePath(QUrl path) noexcept {
        _model->setSelectedFilePath(std::move(path));
    }

    void HistController::read() noexcept {
        emit isReadingChanged(true);
        QFuture<void> readFuture = QtConcurrent::run([this]() {
            QFile file(_model->getSelectedFilePath().toLocalFile());
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

            _model->setSelectedFileSize(file.size());
            const int maxTopWords = _model->getMaxTopWords();
            auto& statistics = _model->getStatistics();

            while (!file.atEnd()) {
                const QString line = file.readLine();
                const QStringList words = line.split(_nonWordRegExp, Qt::SkipEmptyParts);
                for (const auto& word : words)
                    statistics.addWord(word);

                const auto stats = statistics.getTopNWords(maxTopWords);
                const auto diffs = getDiffs(stats); // TODO: [here]

                // TODO: diffs = getDiffs(currentStats, stats)
                //       if (!difs.empty())
                //            emit diffs
                for (const auto& s : stats) {
                    qDebug() << s.first << s.second.word << s.second.quantity;
                }
            }
        }).then([this]() {
            emit isReadingChanged(false);
        });
    }

    HistController::Diffs HistController::getDiffs(const structures::WordsStatistics::topWords_t &topWords) const noexcept {

    }
}

