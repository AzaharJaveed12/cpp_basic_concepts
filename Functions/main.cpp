#include<iostream>
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
    
    return 0;
}