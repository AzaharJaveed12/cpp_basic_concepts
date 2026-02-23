#include <iostream>
#include <cstring>
#include <cmath>

#include "TemplateSyntax.h"
#include "TemplateOverload.h"
#include "MultipleTypesTemplate.h"
#include "TemplateUniqueConcepts.h"

using namespace std;

template<typename T>
T maximum(T a, T b) {
    cout << "Maximum template \n";
    return a < b ? b : a;
}

template<typename T>
const T& maximumByRef(const T& a, const T& b) {
    cout << "IN - " <<(&a) <<" " << (&b) << "\n";
    return a < b ? b : a;
}


/*
In this case:
a prints the string: "hello"
(void*)a prints the address: "0x401000"
&a prints the stack location of the pointer variable itself
*/
template<>
const char* maximum(const char* a , const char* b) {
    std::cout << "IN [template specilization] - " << a << " &a " << (void*)a << " |||| &b " << (void*)b << " " << b << "\n";
    return strcmp(a , b ) ? b : a;
}

// ================= TemplateOverloading.h ==================
template<typename T>
T minimum(T a, T b) {
    cout << "[templateOverloading (T)] "  << &a <<" " << &b << "\n";
    return a < b ? a : b;
}

template<typename T>
T* minimum(T* a, T* b) {
    cout << "[templateOverlaoding] (T*) " <<  a << " " << b << "\n";
    return *a < *b ? a : b;
}

template<>
const char* minimum(const char* a, const char* b) {
    std::cout << "[templateOverloading (const char*)] " << (void*)a << " " << (void*)b << "\n"; 
    return strcmp(a , b ) < 0 ? a  : b;
}
// ===========================================================


// ================ MultipleTypesTemplate.h ====================
template<typename ReturnType , typename T, typename P>
ReturnType maximumInArray(T array , T find, P size) {
    ReturnType x{};
    return x;
}

template<typename T , typename P >
auto maximumInArray(T array, P size) -> decltype(size) {
    return 5;
}

/*

auto — when to use: return a new value (type verbose or unimportant).
Example: factory that constructs a complex container.

decltype(auto) — when to use: preserve the exact type of an expression (including references) — especially in forwarding/getter wrappers.
Example: return whatever front() yields (lvalue reference for lvalue container, rvalue for temporaries).

Use auto by default for value returns; use decltype(auto) only when you need to preserve reference-ness or exact type of the returned expression.

*/
template<typename T,typename P >
decltype(auto) maximumInArray(T array, P size) {
    T a{};
    return a;
}
// ==============================================================


// =============== TemplateUniqueConcepts.h ========================

template<typename R = double , typename T>
R square(const T& n) {
    return sqrt(n);
}

template<typename T , T maxHeightAllowed>
bool condition_met(const T heights[], size_t n) {
    for(int i = 0 ; i < n ; i++ ) {
        if(heights[i] > maxHeightAllowed) return false;
    }
    return true;
}
// =================================================================
int main() {
    int a{5} , b {7};
    double c{10.5} , d{33.3};
    string e{"JMS"} , f{"JS"}; 
    
    maximum(a , b);
    maximum(c , d);
    maximum(e, f);
    auto ans = maximum<double>(a , b); // explicitly saying type is double.
    
    cout << "OUT -  " << (&a) <<" " << (&b) << "\n";
    auto& res = maximumByRef(a , b); 
    cout << "OUT -  " << (&a) <<" " << (&b) << " = " << (&res) << "\n";
    

    // Template specification
    const char* g{"hello"};
    const char* h{"world"};

    /*
    
    */
    cout << (void*)g << " -- g   h --- " << (void*)h << "\n";
    const char* result = maximum(g , h);
    cout << (void*)result << " " << result << "\n";


    // TemplateOverloading.h
    int varA{4} , varB{5};
    cout << &varA << " <----- varA   , varB ----> " << &varB <<"\n";
    const char* varC{"JJJ"} , *varD{"SSSS"};
    cout << (void*)varC << " <----- varC   , varC ----> " << (void*)varC <<"\n";

    auto minimumT = minimum(varA , varB);
    cout << minimumT <<" " << (&minimumT) << "\n";
    
    /*
        The const is mandatory because minimum() returns a temporary value (not a reference).
    */
    const auto& minimumTR = minimum(varA , varB);
    cout << minimumTR <<" " << (&minimumTR) << "\n";


    auto minimumTP = minimum(&varA , &varB);
    cout << minimumTP << " " << &minimumTP << " \n";

    // const auto &minimumTR = minimum(varA , varB);
    auto minimumCC = minimum(varC , varD);
    cout << (void*)minimumCC << " *** " << &minimumCC << " \n";


    auto squareRoot = square(5);
    auto squareRoot2 = square(5.5);

    cout << squareRoot << " <---- squareRot squareRoot2 --> " <<squareRoot2 <<"\n";

    double basketBallPlayers[]{4.4,5.5,6.2,4.3}; // heights in inches
    bool validPlayers = condition_met<double , 6.1>(basketBallPlayers , 4);

    cout <<boolalpha <<  validPlayers <<"\n";
    int navySelection[] {178 , 160 , 120 , 112,180 , 199};
    bool validSoldiers = condition_met<int , 200> (navySelection , sizeof(navySelection) / sizeof(int));
    cout <<boolalpha <<  validSoldiers <<"\n";
    return 0;
}