namespace hist {
    /*
        \brief Non-copyable and non-movable
    */
    #define H_NCM(T) T(const T&) = delete; \
        T& operator=(const T&) = delete;   \
        T(T&&) = delete;                   \
        T& operator=(T&&) = delete;
}
