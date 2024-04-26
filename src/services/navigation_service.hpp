#include <QObject>

namespace hist {
    class NavigationService final : public QObject {
        Q_OBJECT

    public:
        static NavigationService& instance() noexcept;

    signals:
        void changePage(QString pagePath);

    private:
        explicit NavigationService(QObject* parent = nullptr) noexcept;

        ~NavigationService() = default;
    };
}
