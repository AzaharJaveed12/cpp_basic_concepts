#include <iostream>

using namespace std;

class Dog {
private:
    int age;
    string name;
public:
    Dog(int age , string name): age{age} , name {name} {}
    friend class Cat;
};

class Cat {
private:
    int height;
    Dog d;
public:
    Cat(int height , Dog d): height{height} , d{d} {};

    void print_details() {
        cout << height << " " << d.age << " " << d.name << "\n";
    }
};

int main() {
    Cat cat{10 , Dog(11,"Puppy")};
    cat.print_details();
    return 0;
}