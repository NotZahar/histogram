#pragma once

#include <string>

namespace hist::types {
    #define H_MODULE_INFO(_uri, _major, _minor) \
        inline static const std::string uri = _uri; \
        inline static const int major = _major; \
        inline static const int minor = _minor;

    struct ui {
        H_MODULE_INFO("Hist.UI", 1, 0)
    };

    struct navigation {
        H_MODULE_INFO("Hist.Navigation", 1, 0)
    };

    struct controller {
        H_MODULE_INFO("Hist.Control", 1, 0)
    };

    class WordsStatistics {
    public:
        WordsStatistics() noexcept;

        ~WordsStatistics() = default;

        void addWord();

    private:
        inline static constexpr int INVALID_POSITION = -1;

        const int _numberOfTopWords;
        std::unordered_map<int, int> _statistics;
        std::vector<QString> _topWords;
    };
}
