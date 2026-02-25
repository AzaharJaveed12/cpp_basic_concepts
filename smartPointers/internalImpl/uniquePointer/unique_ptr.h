#include <iostream>
#include <utility>

namespace smart_pointer {
    
    template<typename T>
    class unique_ptr {
    public:
        // basic constructors
        unique_ptr();
        unique_ptr(T);
        unique_ptr(T* ptr);
        
        // no copy constructors as we have only one pointer at a given time
        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr& copy) = delete;

        // we can move owmership of unique_ptr to the other unique pointer
        unique_ptr(unique_ptr&&);
        unique_ptr& operator=(unique_ptr&& move);

        // destructor
        ~unique_ptr();

        // some basic methods  (observers)
        T* get() const;
        T& operator*() const;
        T* operator->() const;
        operator bool() const;

        // modifiers
        T* release();
        void reset(T* ptr = nullptr);
        
        void swap(unique_ptr& other);
    private:
        T* ptr;
    };
}

template <typename T>
smart_pointer::unique_ptr<T>::unique_ptr() : ptr{nullptr} {
    std::cout << " [unique_ptr] " << "constructed\n";
}

template <typename T>
smart_pointer::unique_ptr<T>::unique_ptr(T val): ptr{new T(val)}
{
    std::cout << " [unique_ptr] " << "constructed\n";
}

template <typename T>
smart_pointer::unique_ptr<T>::unique_ptr(T *ptr) : ptr{ptr} {
    std::cout << " [unique_ptr] " << "constructed with params\n";
}

template <typename T>
smart_pointer::unique_ptr<T>::unique_ptr(unique_ptr &&other)
{
    std::cout << " [unique_ptr] " << " move constructor got called\n";
    if (other.ptr != nullptr)
    {
        ptr = other.ptr;
        other.ptr = nullptr;
        std::cout << " [unique_ptr] " << "moved\n";
    }
}

template <typename T>
smart_pointer::unique_ptr<T>& smart_pointer::unique_ptr<T>::operator=(unique_ptr &&move)
{
    if(this != &move) {
        delete ptr;
        ptr = move.ptr;
        move.ptr = nullptr;
    }
    return nullptr;
}

template <typename T>
smart_pointer::unique_ptr<T>::~unique_ptr()
{
    std::cout << " [unique_ptr] " << "destructor\n";
    delete ptr;
}

template <typename T>
T *smart_pointer::unique_ptr<T>::get() const
{
    std::cout << " [unique_ptr] " << "get\n";
    return ptr;
}

template <typename T>
T &smart_pointer::unique_ptr<T>::operator*() const
{
    std::cout << " [unique_ptr] " << " dereferencing operator overloading\n";
    return *ptr;
}

template <typename T>
T *smart_pointer::unique_ptr<T>::operator->() const
{
    std::cout << " [unique_ptr] " << " -> operator\n";
    return ptr;
}

template <typename T>
smart_pointer::unique_ptr<T>::operator bool() const
{
    std::cout << " [unique_ptr] " << " boolean \n";
    return ptr != nullptr;
}

template <typename T>
T *smart_pointer::unique_ptr<T>::release()
{
    std::cout << " [unique_ptr] " << " releasing\n";
    return std::exchange(ptr, nullptr);
}

template <typename T>
void smart_pointer::unique_ptr<T>::reset(T *ptr)
{
    std::cout << " [unique_ptr] " << " reseting to nullptr or ptr passed as param\n";
    if (ptr)
        delete ptr;

    this -> ptr = ptr;
}
template <typename T>
void smart_pointer::unique_ptr<T>::swap(unique_ptr &other)
{
    std::cout << " [unique_ptr] " << "swaped with other pointer sent\n";
    swap(ptr, other.ptr);
}