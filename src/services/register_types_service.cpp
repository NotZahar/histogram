#include "register_types_service.hpp"

#include "../utility/types.hpp"
#include "../utility/styles.hpp"

namespace hist {
    RegisterTypesService::RegisterTypesService() noexcept
    {
        using namespace types;

        registerSingletonType<Styles>(utility::uri, utility::major, utility::minor, "Styles");
    }

    RegisterTypesService& RegisterTypesService::instance() noexcept {
        static RegisterTypesService instance;
        return instance;
    }

}

