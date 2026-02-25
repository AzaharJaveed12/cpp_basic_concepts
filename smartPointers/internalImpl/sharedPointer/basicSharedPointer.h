#include <iostream>

namespace smart_pointer {
    template<typename T>
    class shared_ptr {
    private:
        T* ptr;
        int* cnt;
    public:
        // constructor
        shared_ptr(): shared_ptr(nullptr) {}
        shared_ptr(T* ptr): ptr{ptr}, cnt{new int(1)} {}
        
        // copy constructor
        shared_ptr(shared_ptr& other) {
            std:: cout << "copy constructor got called\n";
            if( this != &other ) {
                this -> ptr = other.ptr;
                this -> cnt = other.cnt;
                (*cnt)++;
            }
        }

        // copy assignment operator
        shared_ptr& operator=(shared_ptr& other) {
            std:: cout << "copy assign operator got called\n";
            if( this != &other ) {
                this -> ptr = other.ptr;
                this -> cnt = other.cnt;
                (*cnt)++;
            }
            return *this;
        }

        // move constructor
        shared_ptr(shared_ptr&& other) {
            std:: cout << "move constructor got called\n";
            if(this != &other) {
                this -> ptr = other.ptr;
                this -> cnt = other.cnt;
                other.cnt = nullptr;
                other.ptr = nullptr;
                std::cout << this -> cnt << " ** " << this -> ptr << "\n";
            }
        }

        // move assign operator
        shared_ptr&& operator=(shared_ptr&& other) {
            if( this != &other ) {
                *(other -> cnt)--;
                this -> ptr = other.ptr;
                this -> cnt = other.cnt;
                *(this -> cnt)++;
            }
            return this;
        }

        // overloading dereferencing operator
        T& operator*() {
            return *(this -> ptr);
        }

        // overloading the arrow operator
        T* operator->() {
            return this -> ptr;
        }


        // utility functions
        T* get() {
            return this -> ptr;
        }

        // number of references
        int use_count() {
            if( cnt != nullptr) {
                return *cnt;
            }
            return 0;
        }
    };
}