#include <QGuiApplication>

#include "config/settings.hpp"
#include "app_states/state_manager.hpp"
#include "app_states/init_state.hpp"
#include "services/storage.hpp"

int main(int argc, char** argv) {
    QCoreApplication::setOrganizationName(hist::settings::organizationName);
    QCoreApplication::setApplicationName(hist::settings::applicationName);

    QGuiApplication app(argc, argv);
    hist::Storage::instance().setAppPtr(&app);

    auto& stateManager = hist::StateManager::instance();
    stateManager.addNewState(std::make_unique<hist::InitState>());
    stateManager.init(hist::state::init);

    return app.exec();
}
