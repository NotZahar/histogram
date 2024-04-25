#include "styles.hpp"

namespace hist {
    Styles::Styles(QObject* parent) noexcept
        : QObject{ parent },
          _background_c{ "#1e1e1e" }
    {}

    QString Styles::background_c() const noexcept {
        return _background_c;
    }

    Styles& Styles::instance() noexcept {
        static Styles instance;
        return instance;
    }
}
