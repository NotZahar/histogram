#include <QObject>
#include <QUrl>

namespace hist {
    class HistPageController final : public QObject {
        Q_OBJECT

        Q_PROPERTY(bool openEnabled READ openEnabled WRITE setOpenEnabled NOTIFY openEnabledChanged)
        Q_PROPERTY(bool startEnabled READ startEnabled WRITE setStartEnabled NOTIFY startEnabledChanged)
        Q_PROPERTY(bool cancelEnabled READ cancelEnabled WRITE setCancelEnabled NOTIFY cancelEnabledChanged)
        Q_PROPERTY(int processProgressValue READ processProgressValue NOTIFY processProgressValueChanged)

    public:
        static HistPageController& instance() noexcept;

        bool openEnabled() const noexcept;
        void setOpenEnabled(bool enabled) noexcept;

        bool startEnabled() const noexcept;
        void setStartEnabled(bool enabled) noexcept;

        bool cancelEnabled() const noexcept;
        void setCancelEnabled(bool enabled) noexcept;

        int processProgressValue() const noexcept;
        void setProcessProgressValue(int value) noexcept;

    signals:
        void fileSelected(QUrl path);
        void startRead();

        void openEnabledChanged();
        void startEnabledChanged();
        void cancelEnabledChanged();

        void processProgressValueChanged();

    public slots:
        void onFileSelected(QUrl path) noexcept;
        void onStarted() noexcept;
        void onCanceled() noexcept;

        void setIsReading(bool isReading) noexcept;

    private:
        explicit HistPageController(QObject* parent = nullptr) noexcept;

        ~HistPageController() = default;

        bool _openEnabled;
        bool _startEnabled;
        bool _cancelEnabled;

        int _processProgressValue;
        bool _isReading;
    };
}
