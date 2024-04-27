#include <QGuiApplication>

#include "utility/settings.hpp"
#include "services/register_types_service.hpp"
#include "services/states_service.hpp"

int main(int argc, char** argv) {
    QCoreApplication::setOrganizationName(hist::settings::organizationName);
    QCoreApplication::setApplicationName(hist::settings::applicationName);

    QGuiApplication app(argc, argv);

    hist::RegisterTypesService::instance();
    hist::StatesService::instance();

    return app.exec();
}
