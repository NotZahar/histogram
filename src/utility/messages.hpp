#include <QObject>
#include <QString>

namespace hist {
    class Messages final : public QObject {
        Q_OBJECT

        Q_PROPERTY(QString open_btn MEMBER open_btn CONSTANT)
        Q_PROPERTY(QString start_btn MEMBER start_btn CONSTANT)
        Q_PROPERTY(QString cancel_btn MEMBER cancel_btn CONSTANT)

    public:
        static Messages& instance() noexcept;

        const QString open_btn;
        const QString start_btn;
        const QString cancel_btn;

    private:
        explicit Messages(QObject* parent = nullptr) noexcept;

        ~Messages() = default;
    };
}
