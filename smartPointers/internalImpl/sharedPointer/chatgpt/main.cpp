#include <iostream>
#include <string>
#include "shared_pointer.h"

struct Resource {
    std::string name;
    Resource(std::string n) : name(std::move(n)) { std::cout << "Acquire " << name << "\n"; }
    ~Resource() { std::cout << "Release " << name << "\n"; }
};

void subsystemA(my::shared_ptr<Resource> r) {
    std::cout << "A uses " << r->name << " count=" << r.use_count() << "\n";
}
void subsystemB(my::shared_ptr<Resource> r) {
    std::cout << "B uses " << r->name << " count=" << r.use_count() << "\n";
}

int main() {
    auto r = my::shared_ptr<Resource>(new Resource("DB-Connection"));
    subsystemA(r);
    subsystemB(r);
    std::cout << "main count=" << r.use_count() << "\n";
} // released when last owner dies