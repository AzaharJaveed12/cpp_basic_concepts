#include <iostream>

class Dog {
    Dog();
    Dog(const std::string &name, const std::string &breed ,const int& age);
    ~Dog();

    std::string& get_name();
    std::string& get_breed();
    std::string& get_age();

    const std::string& get_name() const;
    const std::string& get_breed() const;
    const std::string& get_age() const;

    void set_name(const std::string& name);
    void set_breed(const std::string& breed);
    void set_age(const int& age);

    void get_info() const;
};
