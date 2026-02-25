#include <iostream>
#include "Data.h"

std::Data::Data(): Data("JMS" , 1)
{
    std::cout << "[Data] default constructor got called \n";
}

std::Data::Data(const char *name, const int &buffer): name{name} , buffer{buffer}
{
    std::cout << "[Data] parameterized constructor got called \n";
}

std::Data::~Data()
{
    std::cout << "[Data] distructor got called \n";
}

void std::Data::print_data() const
{
    std::cout << "[Data] printing data   name = " << name << " " << " buffer = " << buffer <<"\n";
}
