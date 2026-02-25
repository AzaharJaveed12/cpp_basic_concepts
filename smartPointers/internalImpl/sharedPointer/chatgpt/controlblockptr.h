template<class T, class Deleter>
struct ControlBlockPtr : ControlBlockBase {
    T* ptr;
    Deleter del;

    ControlBlockPtr(T* p, Deleter d) : ptr(p), del(std::move(d)) {}

    void destroy_object() noexcept override {
        if (ptr) { del(ptr); ptr = nullptr; }
    }
};