#include<iostream>
#include<array>
#include "NumberAnalyzer.h"

using namespace std;

int main() {
    //cout << primes[3] << " <---3 1000 -->" <<primes[1000] << "\n";
    cout << is_prime(1000) <<"\n";
    cout << count_prime_numbers_upto(12) <<"\n";
    auto data = safe_log(20);
    static_assert(std::is_same_v<decltype(data), double>, "my_var is not an double");

    cout << data << "< --- log\n";
    return 0;
}