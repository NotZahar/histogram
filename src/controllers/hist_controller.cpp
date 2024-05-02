#include "hist_controller.hpp"

#include <algorithm>

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
                histPageController, &HistPageController::onIsReadingChanged,
                Qt::QueuedConnection);
        connect(this, &HistController::readedWordsCountChanged,
                histPageController, &HistPageController::onReadedWordsCountChanged,
                Qt::QueuedConnection);
        connect(this, &HistController::readProgressChanged,
                histPageController, &HistPageController::onReadedProgressChanged,
                Qt::QueuedConnection);
        connect(this, &HistController::histDataChanged,
                histPageController, &HistPageController::onHistDataChanged,
                Qt::QueuedConnection);
        connect(this, &HistController::clearHistView,
                histPageController, &HistPageController::onClearHistView,
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

            clearHistData();
            const qint64 allBytesToRead = file.size();
            _model->setSelectedFileSize(allBytesToRead);
            auto& readedBytes = _model->readedBytes();
            auto& allReadedWords = _model->getAllReadedWords();
            const int maxTopWords = _model->getMaxTopWords();
            auto& statistics = _model->getStatistics();

            while (!file.atEnd()) {
                const QString line = file.readLine();
                const QStringList words = line.split(_nonWordRegExp, Qt::SkipEmptyParts);
                for (const auto& word : words)
                    statistics.addWord(word);

                allReadedWords += words.size();
                emit readedWordsCountChanged(allReadedWords);

                const auto stats = statistics.getTopNWords(maxTopWords);
                const auto diffs = getDiffs(std::move(stats));
                if (!diffs.empty())
                    emit histDataChanged(diffs);

                readedBytes += line.size();
                emit readProgressChanged((double)readedBytes / allBytesToRead);
            }
        }).then([this]() {
            emit isReadingChanged(false);
        });
    }

    std::list<QSharedPointer<structures::Diff>> HistController::getDiffs(structures::WordsStatistics::topWords_t topWords) noexcept {
        std::list<QSharedPointer<structures::Diff>> diffs;

        auto& currentTop = _model->getCurrentTop();
        const size_t currentSize = currentTop.size();
        const size_t actualSize = topWords.size();
        const size_t intersectingSize = std::min(currentSize, actualSize);

        auto currentIt = currentTop.cbegin();
        auto actualIt = topWords.cbegin();
        for (size_t i = 0; i < intersectingSize; ++i, ++currentIt, ++actualIt) {
            const auto currentPosition = currentIt->first;
            const auto& currentWord = currentIt->second.word;
            const auto currentQuantity = currentIt->second.quantity;

            const auto actualPosition = actualIt->first;
            const auto& actualWord = actualIt->second.word;
            const auto actualQuantity = actualIt->second.quantity;

            assert(currentPosition == actualPosition);

            if (currentWord != actualWord)
                diffs.push_back(QSharedPointer<structures::DiffUpdateWord>::create(actualPosition, actualWord));

            if (currentQuantity != actualQuantity)
                diffs.push_back(QSharedPointer<structures::DiffUpdateQuantity>::create(actualPosition, actualQuantity));
        }

        if (currentSize < actualSize)
            for (auto actualEnd = topWords.cend(); actualIt != actualEnd; ++actualIt)
                diffs.push_back(QSharedPointer<structures::DiffAdd>::create(actualIt->first, actualIt->second.word, actualIt->second.quantity));

        if (currentSize > actualSize)
            for (auto currentEnd = currentTop.cend(); currentIt != currentEnd; ++currentIt)
                diffs.push_back(QSharedPointer<structures::DiffRemove>::create(currentIt->first));

        currentTop = std::move(topWords);
        return diffs;
    }

    void HistController::clearHistData() noexcept {
        auto& readedWords = _model->getAllReadedWords();
        auto& readedBytes = _model->readedBytes();
        auto& stats = _model->getStatistics();
        auto& top = _model->getCurrentTop();

        readedWords = 0;
        readedBytes = 0;
        stats.clear();
        top.clear();

        emit clearHistView();
    }
}

