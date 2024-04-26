#pragma once

#include <QObject>
#include <QQmlEngine>

#include "../utility/h_concepts.hpp"

namespace hist {
    class RegisterTypesService final {
    public:
        Q_DISABLE_COPY_MOVE(RegisterTypesService)

        static RegisterTypesService& instance() noexcept;

    private:
        RegisterTypesService() noexcept;

        ~RegisterTypesService() = default;

        template <HasInstance T>
        void registerSingletonType(
                const std::string uri,
                const int major,
                const int minor,
                const std::string name) const noexcept {
            qmlRegisterSingletonType<T>(uri.c_str(), major, minor, name.c_str(),
                [](QQmlEngine*, QJSEngine*) -> QObject* {
                    T* singleton = &T::instance();
                    QQmlEngine::setObjectOwnership(singleton, QQmlEngine::CppOwnership);

                    return singleton;
                }
            );
        }
    };
}
