#include "hist_controller.hpp"

#include <QDebug> // TODO: delete
#include <QFile>

#include "../services/navigation_service.hpp"
#include "hist_page_controller.hpp"
#include "../utility/thread_pool.hpp"

namespace hist {
    HistController::HistController(QObject* parent) noexcept
        : QObject{ parent },
          _model{ std::make_unique<model::HistModel>() },
          _nonWordRegExp{ "\\W+" }
    {
        auto* histPageController = &HistPageController::instance();
        connect(histPageController, &HistPageController::fileSelected,
                this, &HistController::saveSelectedFilePath);
        connect(histPageController, &HistPageController::startRead,
                this, &HistController::read);
        connect(this, &HistController::fileSizeChanged,
                histPageController, &HistPageController::onFileSizeChanged,
                Qt::QueuedConnection);
        connect(this, &HistController::handleWord,
                histPageController, &HistPageController::onHandleWord,
                Qt::QueuedConnection);
    }

    void HistController::init() noexcept {
        emit NavigationService::instance().changePage("qrc:/qml/pages/Hist.qml");
    }

    void HistController::saveSelectedFilePath(QUrl path) noexcept {
        _model->setSelectedFilePath(std::move(path));
    }

    void HistController::read() noexcept {
        const QUrl selectedFilePath = _model->getSelectedFilePath();

        tools::ThreadPool pool{ 1 };
        pool.addTask([this, filePath = selectedFilePath.toLocalFile()]() {
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
        });
        pool.wait();
    }
}

