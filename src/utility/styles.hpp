#include <QObject>

namespace hist {
    class Styles final : public QObject {
        Q_OBJECT

        Q_PROPERTY(QString background_c READ background_c CONSTANT)

    public:
        QString background_c() const noexcept;

        static Styles& instance() noexcept;

    private:
        explicit Styles(QObject* parent = nullptr) noexcept;

        ~Styles() = default;

        const QString _background_c;
    };
}
