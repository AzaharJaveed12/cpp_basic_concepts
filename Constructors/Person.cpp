#include "Person.h"

Person::Person(const std::string f_name, const std::string l_name)
    : Person(f_name , l_name , 18) {}

Person::Person(const std::string f_name, const std::string l_name, const int a)
    : f_name{f_name} , l_name{l_name} , age{new int(a)} {}

Person::Person(const Person &person) 
    : Person(
        person.f_name,
        person.l_name,
        *person.age
    ){}

void Person::persons_info(){
    std::cout << " [Person] f_n : " << f_name << " l_n : " << l_name << " age : " << (age) << " " << (*age) << '\n';
}

Person::~Person(){
    delete age;
}
