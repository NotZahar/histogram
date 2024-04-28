#include "messages.hpp"

namespace hist {
    Messages::Messages(QObject* parent) noexcept
        : QObject{ parent },
          open_btn{ "Открыть" },
          start_btn{ "Старт" },
          cancel_btn{ "Отмена" }
    {}

    Messages& Messages::instance() noexcept {
        static Messages instance;
        return instance;
    }
}
