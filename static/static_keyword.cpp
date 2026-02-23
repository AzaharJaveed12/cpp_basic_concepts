#include <iostream>
using namespace std;

/*
================================================================================
COMPLETE GUIDE: static + const + constexpr (C++14 vs C++17) — SINGLE CLASS DEMO
================================================================================

This class demonstrates ALL important combinations:
    static
    const
    constexpr
    static const
    static constexpr
    inline static (C++17)

-------------------------------------------------------------------------------
1) static (Storage Duration / Class-Level Sharing)
-------------------------------------------------------------------------------
- One copy shared across all objects
- Lifetime = entire program
- Not part of object memory
- Needs OUTSIDE definition in C++14 (unless inline static in C++17)

-------------------------------------------------------------------------------
2) const (Read-Only After Initialization)
-------------------------------------------------------------------------------
- Value cannot be modified after initialization
- Can be runtime or compile-time constant
- For non-static const members -> must initialize via constructor

-------------------------------------------------------------------------------
3) constexpr (Compile-Time Constant, Stronger than const)
-------------------------------------------------------------------------------
- Must be known at compile time
- Implicitly const
- Can be used in:
    - array sizes
    - template parameters
    - compile-time computations

-------------------------------------------------------------------------------
4) static const vs static constexpr (VERY IMPORTANT)
-------------------------------------------------------------------------------
C++14:
    static const int x = 10;       // OK for integral types (compile-time usable)
    static constexpr int y = 20;   // Preferred (true compile-time constant)
    BUT:
        static const double d = 3.14; // Requires definition outside class

C++17:
    inline static const / constexpr can be fully defined inside class
    No external definition needed.

-------------------------------------------------------------------------------
5) Inline Static (C++17 FEATURE)
-------------------------------------------------------------------------------
- Allows definition + declaration inside class
- Avoids multiple definition & linker errors
- Best practice for header-only designs

-------------------------------------------------------------------------------
6) STATIC LOCAL + CONSTEXPR + CONST INTERACTION
-------------------------------------------------------------------------------
- static local: persists across calls
- constexpr: compile-time evaluation
- const: runtime or compile-time (depends on context)

================================================================================
*/

class StaticConstexprDemo {
private:
    // (1) STATIC DATA MEMBER (C++14 requires outside definition)
    static int objectCount;  // Shared across all objects (runtime modifiable)

    // (2) STATIC CONST (Integral) — Compile-time usable (C++14 OK)
    static const int maxObjects = 100;

    // NOTE:
    // In C++14: static const int can be initialized inside class (only integral types)
    // But still may require definition if ODR-used.

    // (3) STATIC CONSTEXPR — True compile-time constant (Best Practice)
    static constexpr int bufferSize = 64;

    // (4) C++17: INLINE STATIC CONSTEXPR (No external definition needed)
    inline static constexpr int version = 2;

    // (5) STATIC CONST (Non-integral) — Needs definition outside in C++14
    static const double pi;  // Declaration only

    // (6) NON-STATIC CONST MEMBER (Per-object constant)
    const int id;  // Must be initialized via constructor initializer list

public:
    // Constructor
    StaticConstexprDemo() : id(++objectCount) {
        cout << "Constructor -> Object ID (const): " << id << endl;
    }

    // Destructor
    ~StaticConstexprDemo() {
        --objectCount;
        cout << "Destructor -> Remaining Objects: " << objectCount << endl;
    }

    // (7) STATIC MEMBER FUNCTION
    static void showStaticInfo() {
        cout << "\n[Static Info]\n";
        cout << "Object Count (static): " << objectCount << endl;
        cout << "Max Objects (static const): " << maxObjects << endl;
        cout << "Buffer Size (static constexpr): " << bufferSize << endl;
        cout << "Version (inline static constexpr - C++17): " << version << endl;
        cout << "PI (static const double): " << pi << endl;
    }

    // (8) CONST MEMBER FUNCTION (cannot modify object state)
    void showObjectInfo() const {
        cout << "\n[Object Info]\n";
        cout << "Object ID (const member): " << id << endl;
        cout << "Shared Object Count (static): " << objectCount << endl;
    }

    // (9) constexpr MEMBER FUNCTION (compile-time capable)
    static constexpr int square(int x) {
        return x * x;  // Can be evaluated at compile time
    }

    // (10) Demonstrates static local + const + constexpr together
    void functionWithStaticLocal() const {
        static int callCount = 0;        // Persists across calls
        const int runtimeConst = 5;      // Runtime const
        constexpr int compileConst = 10; // Compile-time const

        ++callCount;

        cout << "\n[Function Call Details]\n";
        cout << "Static Local Call Count: " << callCount << endl;
        cout << "Runtime const value: " << runtimeConst << endl;
        cout << "Compile-time constexpr value: " << compileConst << endl;
    }

    // (11) Using constexpr in array size (Compile-time usage)
    void compileTimeArrayDemo() const {
        int arr[bufferSize];  // Allowed: bufferSize is constexpr
        cout << "\nArray created with constexpr size: " << bufferSize << endl;
        cout << "Array memory (bytes): " << sizeof(arr) << endl;
    }

    // (12) Getter for static const
    static int getMaxObjects() {
        return maxObjects;
    }
};

// ====== REQUIRED DEFINITIONS (C++14 RULES) ======

// Definition of static runtime variable
int StaticConstexprDemo::objectCount = 0;

// Definition of static const non-integral type (MANDATORY in C++14)
const double StaticConstexprDemo::pi = 3.141592653589793;


// ================== MAIN ==================
int main() {
    cout << "==== Static + Const + Constexpr Complete Demo ====\n";

    // Static function call (no object needed)
    StaticConstexprDemo::showStaticInfo();

    cout << "\n==== Creating Objects ====\n";
    StaticConstexprDemo a;
    StaticConstexprDemo b;

    a.showObjectInfo();
    b.showObjectInfo();

    // constexpr function usage (compile-time evaluation)
    constexpr int val = StaticConstexprDemo::square(5);
    cout << "\nConstexpr square(5): " << val << endl;

    // Static local + const + constexpr demo
    a.functionWithStaticLocal();
    a.functionWithStaticLocal();

    // Compile-time array demo
    a.compileTimeArrayDemo();

    // Access static const via class
    cout << "\nAccess static const via class: "
         << StaticConstexprDemo::getMaxObjects() << endl;

    return 0;
}