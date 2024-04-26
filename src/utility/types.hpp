#pragma once

#include <string>

namespace hist::types {
    #define H_MODULE_INFO(_uri, _major, _minor) \
        inline static const std::string uri = _uri; \
        inline static const int major = _major; \
        inline static const int minor = _minor;

    struct utility {
        H_MODULE_INFO("Hist.Utility", 1, 0)
    };

    struct navigation {
        H_MODULE_INFO("Hist.Navigation", 1, 0)
    };
}
