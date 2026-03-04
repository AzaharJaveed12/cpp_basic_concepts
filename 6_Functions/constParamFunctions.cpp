#include <iostream>
void constParamFunctions(const int &data)
{
    std::cout << "[constParamFunctions]  (const int& data) : " << (&data) <<"\n";
}