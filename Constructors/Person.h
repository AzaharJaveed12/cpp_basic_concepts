#include <iostream>

class Person {
public:
    // DEFAULT CONSTRUCTORS
    Person() = default;

    // PARAMETERIZED CONSTRUCTOR
    Person(const std::string f_name ,const std::string l_name); 
    Person(const std::string f_name , const std::string l_name , const int a);
    
    // COPY CONSTRUCTOR
    Person(const Person& person);

    //NORMAL METHODS
    void persons_info();
    void set_age(const int& age) {
        *(this -> age) = age;
    }

    ~Person();
private:
    std::string f_name;
    std::string l_name;
    int* age;
};