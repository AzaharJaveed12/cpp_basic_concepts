#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(const string& name , const int& age): name{name} , age{age} {}

    void getInfo() {
        std:: cout << "name = " << name << "  age = " << age << "\n";
    }
};

class Teacher: public Person {
private:
    string subject;
    double salary;
public:
    Teacher(const string& name , const int& age, const string& subject , const double& salary ):
        Person(name , age) {
        this -> subject = subject;
        this -> salary = salary;
    }
    
    void getInfo() {
        Person::getInfo();
        std::cout << "      subject = " << subject << " salary = " << salary << "\n";
    }
};

int main() {
    Person  p1("shareef" , 27);
    p1.getInfo();
    Teacher t1("javeed" , 27, "cpp" , 250000.51);
    t1.getInfo();
    
    Person pt = Teacher("javeed" , 27 , "cpp" , 250000.51);
    pt.getInfo();

    Person *pt_ptr = new Teacher("javeed" , 27 , "cpp" , 2500000.52);
    pt_ptr -> getInfo();

    Person& t_ref = t1;
    t_ref.getInfo();
    return 0;
}