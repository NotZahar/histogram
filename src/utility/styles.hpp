#include <QObject>
#include <QString>

namespace hist {
    class Styles final : public QObject {
        Q_OBJECT

        Q_PROPERTY(qreal standardMargin MEMBER standardMargin CONSTANT)
        Q_PROPERTY(qreal standardRadius MEMBER standardRadius CONSTANT)
        Q_PROPERTY(qreal defaultButtonWidth MEMBER defaultButtonWidth CONSTANT)
        Q_PROPERTY(qreal defaultButtonHeight MEMBER defaultButtonHeight CONSTANT)
        Q_PROPERTY(int defaultButtonFontSize MEMBER defaultButtonFontSize CONSTANT)
        Q_PROPERTY(qreal defaultSpacing MEMBER defaultSpacing CONSTANT)
        Q_PROPERTY(QString background_c MEMBER background_c CONSTANT)
        Q_PROPERTY(QString primary_c MEMBER primary_c CONSTANT)
        Q_PROPERTY(QString secondary_c MEMBER secondary_c CONSTANT)
        Q_PROPERTY(QString white_c MEMBER white_c CONSTANT)
        Q_PROPERTY(QString gray_c MEMBER gray_c CONSTANT)
        Q_PROPERTY(QString darkGray_c MEMBER darkGray_c CONSTANT)
        Q_PROPERTY(QString black_c MEMBER black_c CONSTANT)
        Q_PROPERTY(QString pink_c MEMBER pink_c CONSTANT)
        Q_PROPERTY(QString defaultButton_c MEMBER defaultButton_c CONSTANT)

    public:
        static Styles& instance() noexcept;

        const qreal standardMargin;
        const qreal standardRadius;
        const qreal defaultButtonWidth;
        const qreal defaultButtonHeight;
        const int defaultButtonFontSize;
        const qreal defaultSpacing;
        const QString background_c;
        const QString primary_c;
        const QString secondary_c;
        const QString white_c;
        const QString gray_c;
        const QString darkGray_c;
        const QString black_c;
        const QString pink_c;
        const QString defaultButton_c;

    private:
        explicit Styles(QObject* parent = nullptr) noexcept;

        ~Styles() = default;
    };
}
