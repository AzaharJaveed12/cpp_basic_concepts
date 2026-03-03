#include <iostream>

using namespace std;

class A{
private:
    string str;
public:
    A(string str): str{str} {}

    string getStr() {
        cout << &str << "\n";
        return str;
    }
};

int main() {
    A a("Javeed");
    string str_a = a.getStr();

    cout << &str_a << "\n";

    string str_temp = A("XYZ").getStr();
    cout << &str_temp << "\n";

    return 0;
}