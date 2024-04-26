#include <QObject>

namespace hist {
    class Styles final : public QObject {
        Q_OBJECT

        Q_PROPERTY(qreal standardMargin READ standardMargin CONSTANT)
        Q_PROPERTY(qreal standardRadius READ standardRadius CONSTANT)
        Q_PROPERTY(qreal defaultButtonWidth READ defaultButtonWidth CONSTANT)
        Q_PROPERTY(qreal defaultButtonHeight READ defaultButtonHeight CONSTANT)
        Q_PROPERTY(int defaultButtonFontSize READ defaultButtonFontSize CONSTANT)
        Q_PROPERTY(qreal defaultSpacing READ defaultSpacing CONSTANT)
        Q_PROPERTY(QString background_c READ background_c CONSTANT)
        Q_PROPERTY(QString primary_c READ primary_c CONSTANT)
        Q_PROPERTY(QString secondary_c READ secondary_c CONSTANT)
        Q_PROPERTY(QString white_c READ white_c CONSTANT)
        Q_PROPERTY(QString gray_c READ gray_c CONSTANT)
        Q_PROPERTY(QString defaultButton_c READ defaultButton_c CONSTANT)

    public:
        static Styles& instance() noexcept;

        qreal standardMargin() const noexcept;
        qreal standardRadius() const noexcept;
        qreal defaultButtonWidth() const noexcept;
        qreal defaultButtonHeight() const noexcept;
        int defaultButtonFontSize() const noexcept;
        qreal defaultSpacing() const noexcept;
        QString background_c() const noexcept;
        QString primary_c() const noexcept;
        QString secondary_c() const noexcept;
        QString white_c() const noexcept;
        QString gray_c() const noexcept;
        QString defaultButton_c() const noexcept;

    private:
        explicit Styles(QObject* parent = nullptr) noexcept;

        ~Styles() = default;

        const qreal _standardMargin;
        const qreal _standardRadius;
        const qreal _defaultButtonWidth;
        const qreal _defaultButtonHeight;
        const int _defaultButtonFontSize;
        const qreal _defaultSpacing;
        const QString _background_c;
        const QString _primary_c;
        const QString _secondary_c;
        const QString _white_c;
        const QString _gray_c;
        const QString _defaultButton_c;
    };
}
