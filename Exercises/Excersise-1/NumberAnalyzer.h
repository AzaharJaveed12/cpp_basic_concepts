#include<iostream>
#include<array>
#include <cmath>

struct AnalysisResult {
    bool    isPrime;
    int     primeCountUpto;
    double  logValue;
};

bool is_prime(int n);

int count_prime_numbers_upto(int n);

/*
    we cannot use this directly here as returntype is deduced by evaluating the returned value.
    soo defination is required.
*/
//template<typename T> decltype(auto) safe_log(T n);

/*
              RULE YOU MUST MEMORIZE
Function templates must be fully defined in headers OR
Explicitly instantiated for known types
*/
template<typename T>
decltype(auto) safe_log(const T& n) {
    return log10(n);
}

template<typename T>
constexpr AnalysisResult analyze_number(const T& num);
