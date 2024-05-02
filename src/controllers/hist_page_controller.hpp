#pragma once

#include <QObject>
#include <QUrl>
#include <QSharedPointer>

#include "../utility/structures.hpp"

namespace hist {
    class HistPageController final : public QObject {
        Q_OBJECT

        Q_PROPERTY(bool openEnabled READ openEnabled WRITE setOpenEnabled NOTIFY openEnabledChanged)
        Q_PROPERTY(bool startEnabled READ startEnabled WRITE setStartEnabled NOTIFY startEnabledChanged)
        Q_PROPERTY(bool cancelEnabled READ cancelEnabled WRITE setCancelEnabled NOTIFY cancelEnabledChanged)

    public:
        static HistPageController& instance() noexcept;

        bool openEnabled() const noexcept;
        void setOpenEnabled(bool enabled) noexcept;

        bool startEnabled() const noexcept;
        void setStartEnabled(bool enabled) noexcept;

        bool cancelEnabled() const noexcept;
        void setCancelEnabled(bool enabled) noexcept;

    signals:
        void fileSelected(QUrl path);
        void startRead();

        void openEnabledChanged();
        void startEnabledChanged();
        void cancelEnabledChanged();

        void histDataWordUpdated(int position, QString word);
        void histDataQuantityUpdated(int position, int quantity);
        void histDataAdded(int position, QString word, int quantity);
        void histDataRemoved(int position);

        void readedWordsCountChanged(int words);
        void readProgressChanged(qreal progress);
        void clearData();

    public slots:
        void onFileSelected(QUrl path) noexcept;
        void onStarted() noexcept;
        void onCanceled() noexcept;

        void onIsReadingChanged(bool isReading) noexcept;
        void onHistDataChanged(std::list<QSharedPointer<structures::Diff>> diffs) noexcept;
        void onReadedWordsCountChanged(int words) noexcept;
        void onReadedProgressChanged(qreal progress) noexcept;
        void onClearHistView() noexcept;

    private:
        explicit HistPageController(QObject* parent = nullptr) noexcept;

        ~HistPageController() = default;

        bool _openEnabled;
        bool _startEnabled;
        bool _cancelEnabled;

        bool _isReading;
    };
}
