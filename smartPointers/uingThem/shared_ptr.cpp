#include <iostream>
#include <memory>

using namespace std;

void shared_pointers_inbuild_types() {
    shared_ptr<int> s_ptr{ new int(5)};
    cout << *s_ptr << " value \n";
    *s_ptr = 100;
    cout << *s_ptr << " value \n";
    cout << s_ptr.use_count() << "\n";

    shared_ptr<int> s_ptr_1{nullptr};
    s_ptr_1 = s_ptr;
    cout << s_ptr.use_count() << "\n";

    shared_ptr<int> s_ptr_2{s_ptr};
    cout << s_ptr.use_count() << "\n";

    *s_ptr_2 = 44;
    cout << *s_ptr << " value\n";
}

void uniqueptr_to_sharedptr() {
    unique_ptr<int> u_ptr {new int(5)};
    cout << u_ptr.get() << " u_ptr addr\n";
    shared_ptr<int> s_ptr = move(u_ptr);
    cout << s_ptr.use_count() << " " << s_ptr.get() << "  s_ptr addr\n";
}

int main() {
    shared_pointers_inbuild_types();
    uniqueptr_to_sharedptr();
}