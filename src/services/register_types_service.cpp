#include "register_types_service.hpp"

#include "../utility/types.hpp"
#include "../utility/styles.hpp"
#include "navigation_service.hpp"

namespace hist {
    RegisterTypesService::RegisterTypesService() noexcept
    {
        using namespace types;

        registerSingletonType<Styles>(ui::uri, ui::major, ui::minor, "Styles");
        registerSingletonType<NavigationService>(navigation::uri, navigation::major, navigation::minor, "NavigationService");
    }

    RegisterTypesService& RegisterTypesService::instance() noexcept {
        static RegisterTypesService instance;
        return instance;
    }

}

