#include <iostream> 
#include <cinttypes>

#include "Person.h"

using namespace std;

class Animal {
public:
    Animal(int age): age{new int(age)} {}
    int* age;
};

int main() {

    // DEFAULT COPY CONSTRUCTOR CALLING
    Animal lion(50);
    Animal tiger(lion);
    *(tiger.age) = 25;
    cout << lion.age << " <----- lion\n" << tiger.age << " <----- tiger\n";
    
    // OUR DEFINED COPY CONSTRUCTOR
    Person p1("Javeed Meera Shareef" , "Shaik" , 27);
    Person p2(p1);
    p2.set_age(28);
    p1.persons_info();cout << "\n";
    p2.persons_info(); cout <<"\n";
    return 0;
}