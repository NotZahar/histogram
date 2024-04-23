#pragma once

#include <QGuiApplication>

#include "utility/types.hpp"

namespace hist {
    class App final {
    public:
        H_NCM(App)

        static App& instance(int argc, char **argv);

        int run();

    private:
        App() = delete;
        App(int argc, char** argv) noexcept;

        ~App() = default;

        QGuiApplication _app;
    };
}
