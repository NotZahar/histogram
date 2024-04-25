#include <concepts>

namespace hist {
    template<class T>
    concept HasInstance =
        requires(T) {
            { T::instance() } -> std::convertible_to<T&>;
        };
}
