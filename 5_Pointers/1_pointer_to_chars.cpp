#include <iostream>

using namespace std;

int main () {
    const char *c_ptr = "hello"; // moderen c++ we can assing cstring to const char* only
    cout << "(*c_ptr)  : " << (*c_ptr) << "   c_ptr : " << c_ptr << "\n";

    // takes 90 x 3 = 270bytes
    char paragraphs[][90] {
        "India is my country",
        "all indians are my brothers and sisters",
        "I love my country"
    };

    // takes 20 + 42 + 18 bytes only..!!
    const char* paragraphs_ptr[] = {
        "India is my country",
        "all indians are my brothers and sisters",
        "I love my country"
    }; 

    // cout << size(paragraphs[0]) << " " << size(paragraphs_ptr[0]) << "\n";
    return 0;
}