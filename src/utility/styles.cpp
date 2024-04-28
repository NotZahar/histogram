#include "styles.hpp"

namespace hist {
    Styles::Styles(QObject* parent) noexcept
        : QObject{ parent },
          standardMargin{ 10 },
          standardRadius{ 10 },
          defaultButtonWidth{ 180 },
          defaultButtonHeight{ 55 },
          defaultButtonFontSize{ 25 },
          defaultSpacing{ 8 },
          background_c{ "#1e1e1e" },
          primary_c{ "#171717" },
          secondary_c{ "#0c0039" },
          white_c{ "#e9e9e9" },
          gray_c{ "#b9b9b9" },
          darkGray_c{ "#101010" },
          black_c{ "#0a0a0a" },
          pink_c{ "#844040" },
          defaultButton_c{ "#070021" }
    {}

    Styles& Styles::instance() noexcept {
        static Styles instance;
        return instance;
    }
}
