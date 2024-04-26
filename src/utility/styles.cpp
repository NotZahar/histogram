#include "styles.hpp"

namespace hist {
    Styles::Styles(QObject* parent) noexcept
        : QObject{ parent },
          _standardMargin{ 10 },
          _standardRadius{ 10 },
          _defaultButtonWidth{ 180 },
          _defaultButtonHeight{ 55 },
          _defaultButtonFontSize{ 25 },
          _defaultSpacing{ 8 },
          _background_c{ "#1e1e1e" },
          _primary_c{ "#171717" },
          _secondary_c{ "#0c0039" },
          _white_c{ "#e9e9e9" },
          _gray_c{ "#b9b9b9" },
          _defaultButton_c{ "#070021" }
    {}

    QString Styles::background_c() const noexcept {
        return _background_c;
    }

    QString Styles::primary_c() const noexcept {
        return _primary_c;
    }

    QString Styles::secondary_c() const noexcept {
        return _secondary_c;
    }

    QString Styles::white_c() const noexcept {
        return _white_c;
    }

    QString Styles::gray_c() const noexcept {
        return _gray_c;
    }

    QString Styles::defaultButton_c() const noexcept {
        return _defaultButton_c;
    }

    qreal Styles::standardMargin() const noexcept {
        return _standardMargin;
    }

    qreal Styles::standardRadius() const noexcept {
        return _standardRadius;
    }

    qreal Styles::defaultButtonWidth() const noexcept {
        return _defaultButtonWidth;
    }

    qreal Styles::defaultButtonHeight() const noexcept {
        return _defaultButtonHeight;
    }

    int Styles::defaultButtonFontSize() const noexcept {
        return _defaultButtonFontSize;
    }

    qreal Styles::defaultSpacing() const noexcept {
        return _defaultSpacing;
    }

    Styles& Styles::instance() noexcept {
        static Styles instance;
        return instance;
    }
}
