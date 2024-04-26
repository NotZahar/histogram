cmake_minimum_required(VERSION 3.21)

set(PATCH_VERSION 1 CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(histogram VERSION ${PROJECT_VESRION})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(
    Qt6 REQUIRED
        COMPONENTS
            Core
            Gui
            Qml
            Quick
)

qt_add_executable(
    ${PROJECT_NAME}
        # cpp
        src/main.cpp
        src/app_states/state.cpp
        src/app_states/state_manager.cpp
        src/app_states/init_state.cpp
        src/app_states/hist_state.cpp
        src/controllers/init_controller.cpp
        src/controllers/hist_controller.cpp
        src/services/qml_service.cpp
        src/services/storage.cpp
        src/services/register_types_service.cpp
        src/services/states_service.cpp
        src/services/navigation_service.cpp
        src/utility/styles.cpp

        # qml
        src/qml/qml.qrc

        # resources
        resources/app.qrc
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            Qt6::Core
            Qt6::Gui
            Qt6::Qml
            Qt6::Quick
)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
