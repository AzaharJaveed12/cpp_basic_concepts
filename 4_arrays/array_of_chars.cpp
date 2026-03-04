#include <iostream>
#include <set>

using namespace std;

int main() {
    char name[7]{'j','a','v','e','e','d'};
    cout << name << "  " << size(name) <<"\n";        // char array tries to find till null char and print data once it found that
    
    char name_2[4]{'a','b','c','d'};                  // if changes size to 5, will print exactly abcd or else abcd****  
    cout << name_2 << " -- " << size(name_2) << "\n"; // no null charector at end of name_2

    char name_3[]{'x','y'};                           // random data as null charector will not append automatically.
    cout << name_3 << " " << size(name_3) << "\n";

    char name_4[]{"Indian2"};                         // exact data as null charector appened at end automatically.
    cout << name_4 << " " <<size(name_4) <<"\n";
    return 0;    
}