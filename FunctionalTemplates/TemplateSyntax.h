template <typename T>
T maximum(T a, T b);

// compailer confuses which one to call and throws error.
/*
template<typename T>
T& maximum(const T& a, const T& b);
*/

template<typename T>
const T& maximumByRef(const T& a, const T& b);

// template specilization
template <>
const char* maximum(const char* a, const char* b);