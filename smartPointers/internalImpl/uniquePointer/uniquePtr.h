#include <utility>   // std::exchange
#include <cstddef>   // std::nullptr_t

template <class T>
struct DefaultDelete {
    void operator()(T* p) const noexcept { delete p; }
};

template <class T, class Deleter = DefaultDelete<T>>
class UniquePtr {
    T* ptr;
    [[no_unique_address]] Deleter del; // C++20: enables EBO-like storage
public:
    // constructors
    constexpr UniquePtr() noexcept : ptr(nullptr), del() {}
    explicit UniquePtr(T* p) noexcept : ptr(p), del() {}

    // non-copyable
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // movable
    UniquePtr(UniquePtr&& other) noexcept
        : ptr(std::exchange(other.ptr, nullptr)), del(std::move(other.del)) {
            std::cout << "Moved\n";
        }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            reset(); // delete current
            ptr = std::exchange(other.ptr, nullptr);
            del = std::move(other.del);
            std::cout << "moved\n";
        }
        return *this;
    }

    ~UniquePtr() { reset(); }

    // observers
    T* get() const noexcept { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const noexcept { return ptr; }
    explicit operator bool() const noexcept { return ptr != nullptr; }

    // modifiers
    T* release() noexcept { return std::exchange(ptr, nullptr); }

    void reset(T* p = nullptr) noexcept {
        if (ptr) del(ptr);
        ptr = p;
    }

    void swap(UniquePtr& other) noexcept {
        std::swap(ptr, other.ptr);
        std::swap(del, other.del);
    }
};