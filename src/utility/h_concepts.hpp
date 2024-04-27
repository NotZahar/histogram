#include <concepts>

namespace hist {
    template<class T>
    concept Instanceable =
        requires(T) {
            { T::instance() } -> std::convertible_to<T&>;
        };
}
