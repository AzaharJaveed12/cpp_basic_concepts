/*
    C++14 Fundamental Types Inspector
    ---------------------------------
    This program prints:
    1. Size of each fundamental type (in bytes)
    2. Minimum and maximum range (from <limits>)
    3. Alignment requirements (alignof)
    4. Signed vs Unsigned comparison

    Why this is important:
    - Type sizes are NOT fixed in C++
    - They depend on compiler, architecture, and ABI (LP64, LLP64, etc.)
    - Useful for systems programming, libraries, serialization, and portability
*/

#include <cstdint>
#include <iostream>
#include <limits>
#include <iomanip>
#include <type_traits>

class TypeInspector {
public:
    template<typename T>
    static void inspect(const std::string& type_name) {
        std::cout << std::left << std::setw(18) << type_name
                  << std::setw(8)  << sizeof(T)
                  << std::setw(10) << alignof(T)
                  << std::setw(10) << (std::is_signed<T>::value ? "Signed" : "Unsigned");

        print_range<T>();
        std::cout << "\n";
    }

private:
    template<typename T>
    static typename std::enable_if<std::is_arithmetic<T>::value>::type
    print_range() {
        std::cout << " Min: " << std::numeric_limits<T>::lowest()
                  << " Max: " << std::numeric_limits<T>::max();
    }

    template<typename T>
    static typename std::enable_if<!std::is_arithmetic<T>::value>::type
    print_range() {
        std::cout << " Min: N/A Max: N/A";
    }
};

int main() {
    std::cout << "==== C++14 Fundamental Types Analysis ====\n\n";

    std::cout << std::left
              << std::setw(18) << "Type"
              << std::setw(8)  << "Size"
              << std::setw(10) << "Align"
              << std::setw(10) << "Sign"
              << "Range\n";

    std::cout << "---------------------------------------------------------------\n";

    // Character types
    TypeInspector::inspect<char>("char");
    TypeInspector::inspect<signed char>("signed char");
    TypeInspector::inspect<unsigned char>("unsigned char");
    TypeInspector::inspect<wchar_t>("wchar_t");

    std::cout << "\n";

    // Integer types
    TypeInspector::inspect<short>("short");
    TypeInspector::inspect<unsigned short>("unsigned short");

    TypeInspector::inspect<int>("int");
    TypeInspector::inspect<unsigned int>("unsigned int");

    TypeInspector::inspect<long>("long");
    TypeInspector::inspect<unsigned long>("unsigned long");

    TypeInspector::inspect<long long>("long long");
    TypeInspector::inspect<unsigned long long>("unsigned long long");

    std::cout << "\n";

    // Floating point types
    TypeInspector::inspect<float>("float");
    TypeInspector::inspect<double>("double");
    TypeInspector::inspect<long double>("long double");

    std::cout << "\n";

    // Boolean and pointer (special cases)
    TypeInspector::inspect<bool>("bool");
    TypeInspector::inspect<void*>("void* (pointer)");

    std::cout << "\n==== Fixed Width Types (<cstdint>) ====\n\n";

    // Fixed-width types (portable)
    TypeInspector::inspect<int8_t>("int8_t");
    TypeInspector::inspect<uint8_t>("uint8_t");
    TypeInspector::inspect<int16_t>("int16_t");
    TypeInspector::inspect<uint16_t>("uint16_t");
    TypeInspector::inspect<int32_t>("int32_t");
    TypeInspector::inspect<uint32_t>("uint32_t");
    TypeInspector::inspect<int64_t>("int64_t");
    TypeInspector::inspect<uint64_t>("uint64_t");

    return 0;
}