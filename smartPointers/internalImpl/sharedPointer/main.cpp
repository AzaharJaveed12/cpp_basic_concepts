#include <iostream>
#include "Data.h"
#include "basicSharedPointer.h"

int main() {
    smart_pointer::shared_ptr<std::Data> s_ptr{new std::Data()};
    std::cout << s_ptr.use_count() << "\n";
    
    // copy
    smart_pointer::shared_ptr<std::Data> s_ptr_copy = s_ptr;
    std::cout << s_ptr_copy.use_count() << "\n";
    smart_pointer::shared_ptr<std::Data> s_ptr_copy_assign(nullptr);
    s_ptr_copy_assign = s_ptr;
    std::cout << s_ptr_copy_assign.use_count() << " " << s_ptr_copy.use_count() << " " << s_ptr.use_count() << "\n";
    
    // move
    smart_pointer::shared_ptr<std::Data> s_ptr_dup{new std::Data()};
    std:: cout << "another pointer count " << s_ptr_dup.use_count() << "\n";
    smart_pointer::shared_ptr<std::Data> s_ptr_move = move(s_ptr_dup);
    std:: cout << "another pointer moved count " << s_ptr_move.use_count() << " -- " << s_ptr_dup.use_count() << "\n";
    return 0;
}