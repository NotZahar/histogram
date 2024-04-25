#include "storage.hpp"

namespace hist {
    Storage& Storage::instance() noexcept {
        static Storage instance;
        return instance;
    }
}

