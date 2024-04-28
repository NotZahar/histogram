#include "register_types_service.hpp"

#include "../utility/types.hpp"
#include "../utility/styles.hpp"
#include "../utility/messages.hpp"
#include "navigation_service.hpp"
#include "../controllers/hist_page_controller.hpp"

namespace hist {
    RegisterTypesService::RegisterTypesService() noexcept
    {
        using namespace types;

        // ui
        registerSingletonType<Styles>(ui::uri, ui::major, ui::minor, "Styles");
        registerSingletonType<Messages>(ui::uri, ui::major, ui::minor, "Messages");

        // services
        registerSingletonType<NavigationService>(navigation::uri, navigation::major, navigation::minor, "NavigationService");

        // controllers
        registerSingletonType<HistPageController>(controller::uri, controller::major, controller::minor, "HistPageController");
    }

    RegisterTypesService& RegisterTypesService::instance() noexcept {
        static RegisterTypesService instance;
        return instance;
    }

}

