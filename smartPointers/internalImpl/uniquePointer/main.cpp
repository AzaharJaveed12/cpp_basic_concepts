#include <iostream>
#include <memory>

#include "unique_ptr.h"
#include "uniquePtr.h"

using namespace std;

// smart_pointer::unique_ptr<int> makeInt() {
//     smart_pointer::unique_ptr<int> p(new int(3));
//     return p;
// }

UniquePtr<int> makeInt() {
    UniquePtr<int> p(new int(42));
    return p; // move (NRVO or move)
}

void use() {
    auto p = makeInt();
    // p owns the int, auto deleted when p goes out of scope
}
int main() {
    int *ptr = new int(4);
    
 //   smart_pointer::unique_ptr<int> u_ptr(5);
 //   smart_pointer::unique_ptr<int> u_ptr_using_ptr{ptr}; 
 //   auto p = makeInt();


    return 0;
}