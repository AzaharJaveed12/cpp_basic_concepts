#include<iostream>
#include <cstddef>
#include "functionParameters.h"

using namespace std;

int main() {
    int age{40};

    cout<< " Pass by value               :  addr  "<< (&age) <<"value: " << age << "\n";
    passByValue(age);
    cout<< " Pass by value after function :  addr  "<< (&age) << " value: " << age << "\n\n\n";
    
    cout<< " Pass by const value         :  addr  "<< (&age) <<"\n";
    passByConstValue(age);
    cout<< " Pass by const value after function :  addr  "<< (&age) << " value: " << age << "\n\n\n";

    cout<< " Pass by pointer             :  addr  "<< (&age) << " value: " << age << "\n";
    passByPointer( &age );
    cout<< " Pass by pointer after function :  addr  "<< (&age) << " value: " << age << "\n\n\n";
   
    cout << "\n\n ======================= array as param ============================\n\n";
    int arr[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = size(arr);
    auto print = [&]() {
        for(int i = 0 ;i < size(arr); i++) cout <<arr[i] << " "; cout <<"\n";
    };
    passArrayToFunction_A(arr , len);
    print();
    passArrayToFunction_B(arr, len);
    print();
    passArrayToFunctionAsReference(arr); // as we are passing using ref, that fun can compute arr size.
    print();


    cout << "\n\n ======================= array as param ============================\n\n";
    int data = 5;
    const int& c_data = data;
    double double_data = 5.55;
    cout << "inside main : " << ( &data ) << " " << ( &c_data ) << "\n";
    constParamFunctions(data);
    constParamFunctions(c_data);
    constParamFunctions(double_data);
    return 0;
}