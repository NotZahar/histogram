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
        connect(this, &HistController::fileSizeChanged,
                this, &HistController::setSelectedFileSize,
                Qt::QueuedConnection);
        connect(this, &HistController::handleWord,
                this, &HistController::toStatistics,
                Qt::QueuedConnection);
        connect(this, &HistController::isReadingChanged,
                histPageController, &HistPageController::setIsReading,
                Qt::QueuedConnection);
    }

    void HistController::init() noexcept {
        emit NavigationService::instance().changePage("qrc:/qml/pages/Hist.qml");
    }

    void HistController::setSelectedFileSize(qint64 size) noexcept {
        _model->setSelectedFileSize(size);
    }

    void HistController::setSelectedFilePath(QUrl path) noexcept {
        _model->setSelectedFilePath(std::move(path));
    }

    void HistController::read() noexcept {
        const QUrl selectedFilePath = _model->getSelectedFilePath();

        emit isReadingChanged(true);
        QFuture<void> readFuture = QtConcurrent::run([this, filePath = selectedFilePath.toLocalFile()]() {
            QFile file(filePath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

            emit fileSizeChanged(file.size());

            while (!file.atEnd()) {
                const QString line = file.readLine();
                const QStringList words = line.split(_nonWordRegExp, Qt::SkipEmptyParts);
                for (const auto& word : words)
                   emit handleWord(word);
            }
        }).then([this]() {
            emit isReadingChanged(false);
        });
    }

    void HistController::toStatistics(QString word) noexcept {
        (void)word;
    }
}

