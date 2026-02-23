#include <iostream>
#include <type_traits>


#include "NumberAnalyzer.h"


constexpr size_t MAX_SIZE = 100000;
/*

anonomus namespaces --> for hiding.
                        for consteval & constexpr methods better to place here only.

if one compiletime array is build and if we want to use that compile time build array
in another compiletime evaluating array, then we should be using constexpr but not the 
combination of (constinit & consteval)
*/
namespace {
    constexpr std::array<bool,MAX_SIZE> __fill_prime_array(size_t nax) {
        std::array<bool,MAX_SIZE> primes{};
        for(int i{0} ; i < MAX_SIZE; i++)
            primes[i] = true;
        primes[0] =false;
        primes[1] = false;
        for(int i{2}; i < nax; i++) {
            if(primes[i]) {
                int j = i + i;
                while(j < nax) {
                    primes[j] = false;
                    j += i;
                }
            }
        }
        return primes;
    }

    constexpr std::array<bool,MAX_SIZE>
    primes = __fill_prime_array(MAX_SIZE);

    consteval std::array<unsigned int,MAX_SIZE> primes_count_till_N() {
        std::array<unsigned int,MAX_SIZE> prefix_primes{};

        for(unsigned int i{2}; i < MAX_SIZE; i++ ) {
            prefix_primes[i] += prefix_primes[i - 1] + static_cast<unsigned int>(primes[i]); 
        }

        return prefix_primes;
    }


    constexpr std::array<unsigned int,MAX_SIZE> 
    prefix_primes = primes_count_till_N();
}

bool is_prime(int n) {
  //  assert(n >  100000 , "Given number should be less than 100000");
    return primes[n];
}

int count_prime_numbers_upto(int n) {
    return prefix_primes[n];
}
