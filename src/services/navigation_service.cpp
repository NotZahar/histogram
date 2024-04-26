#include "navigation_service.hpp"

namespace hist {
    NavigationService::NavigationService(QObject* parent) noexcept
        : QObject{ parent }
    {}

    NavigationService& NavigationService::instance() noexcept {
        static NavigationService instance;
        return instance;
    }
}
