#include "app.h"

int main(int argc, char** argv) {
    auto& histogram = hist::App::instance(argc, argv);
    return histogram.run();
}
