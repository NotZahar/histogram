#include "hist_page_controller.hpp"

namespace hist {
    HistPageController::HistPageController(QObject* parent) noexcept
        : QObject{ parent },
          _openEnabled{ true },
          _startEnabled{ false },
          _cancelEnabled{ true },
          _isReading{ false }
    {}

    HistPageController& HistPageController::instance() noexcept {
        static HistPageController instance;
        return instance;
    }

    bool HistPageController::openEnabled() const noexcept {
        return _openEnabled;
    }

    void HistPageController::setOpenEnabled(bool enabled) noexcept {
        if (_openEnabled == enabled)
            return;
        _openEnabled = enabled;
        emit openEnabledChanged();
    }

    bool HistPageController::startEnabled() const noexcept {
        return _startEnabled;
    }

    void HistPageController::setStartEnabled(bool enabled) noexcept {
        if (_startEnabled == enabled)
            return;
        _startEnabled = enabled;
        emit startEnabledChanged();
    }

    bool HistPageController::cancelEnabled() const noexcept {
        return _cancelEnabled;
    }

    void HistPageController::setCancelEnabled(bool enabled) noexcept {
        if (_cancelEnabled == enabled)
            return;
        _cancelEnabled = enabled;
        emit cancelEnabledChanged();
    }

    void HistPageController::onIsReadingChanged(bool isReading) noexcept {
        _isReading = isReading;
    }

    void HistPageController::onHistDataChanged(std::list<QSharedPointer<structures::Diff>> diffs) noexcept {
        assert(!diffs.empty());
        for (auto& diff : diffs) {
            if (auto* updateWord = dynamic_cast<structures::DiffUpdateWord*>(diff.get()); updateWord) {
                emit histDataWordUpdated(updateWord->position, updateWord->word);
                continue;
            }

            if (auto* updateQuantity = dynamic_cast<structures::DiffUpdateQuantity*>(diff.get()); updateQuantity) {
                emit histDataQuantityUpdated(updateQuantity->position, updateQuantity->quantity);
                continue;
            }

            if (auto* add = dynamic_cast<structures::DiffAdd*>(diff.get()); add) {
                emit histDataAdded(add->position, add->word, add->quantity);
                continue;
            }

            if (auto* remove = dynamic_cast<structures::DiffRemove*>(diff.get()); remove) {
                emit histDataRemoved(remove->position);
                continue;
            }
        }
    }

    void HistPageController::onReadedWordsCountChanged(int words) noexcept {
        emit readedWordsCountChanged(words);
    }

    void HistPageController::onReadedProgressChanged(qreal progress) noexcept {
        emit readProgressChanged(progress);
    }

    void HistPageController::onClearHistView() noexcept {
        emit clearData();
    }

    void HistPageController::onFileSelected(QUrl path) noexcept {
        setStartEnabled(true);
        emit fileSelected(path);
    }

    void HistPageController::onStarted() noexcept {
        if (_isReading)
            return;

        setStartEnabled(false);
        emit startRead();
    }

    void HistPageController::onCanceled() noexcept {
        // TODO: Implement logic!
    }
}
