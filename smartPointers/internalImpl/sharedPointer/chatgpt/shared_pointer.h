#include <atomic>
#include <utility>
#include <cstddef>
#include "codeblockbase.h"
#include "controlblockptr.h"

namespace my {
template<class T>
struct DefaultDelete {
    void operator()(T* p) const noexcept { delete p; }
};

inline void inc_strong(ControlBlockBase* cb) noexcept {
    if (cb) cb->strong.fetch_add(1, std::memory_order_relaxed);
}

inline void dec_strong(ControlBlockBase* cb) noexcept {
    if (!cb) return;

    // if this was the last strong ref
    if (cb->strong.fetch_sub(1, std::memory_order_acq_rel) == 1) {
        cb->destroy_object();
        // drop the "object-alive" weak reference
        if (cb->weak.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete cb;
        }
    }
}

template<class T>
class shared_ptr {
    T* px = nullptr;
    ControlBlockBase* cb = nullptr;

public:
    // 1) default
    shared_ptr() noexcept = default;

    // 2) construct from raw pointer (separate allocation)
    explicit shared_ptr(T* p) : px(p) {
        if (p) cb = new ControlBlockPtr<T, DefaultDelete<T>>(p, DefaultDelete<T>{});
    }

    // 3) custom deleter
    template<class Deleter>
    shared_ptr(T* p, Deleter d) : px(p) {
        if (p) cb = new ControlBlockPtr<T, Deleter>(p, std::move(d));
    }

    // 4) copy
    shared_ptr(const shared_ptr& other) noexcept : px(other.px), cb(other.cb) {
        inc_strong(cb);
    }

    // 5) move
    shared_ptr(shared_ptr&& other) noexcept : px(other.px), cb(other.cb) {
        other.px = nullptr;
        other.cb = nullptr;
    }

    // 6) copy assign (copy-and-swap style)
    shared_ptr& operator=(const shared_ptr& other) noexcept {
        if (this == &other) return *this;
        dec_strong(cb);
        px = other.px;
        cb = other.cb;
        inc_strong(cb);
        return *this;
    }

    // 7) move assign
    shared_ptr& operator=(shared_ptr&& other) noexcept {
        if (this == &other) return *this;
        dec_strong(cb);
        px = other.px;
        cb = other.cb;
        other.px = nullptr;
        other.cb = nullptr;
        return *this;
    }

    // 8) destructor
    ~shared_ptr() {
        dec_strong(cb);
    }

    void reset() noexcept {
        dec_strong(cb);
        px = nullptr;
        cb = nullptr;
    }

    void reset(T* p) {
        shared_ptr tmp(p);
        *this = std::move(tmp);
    }

    T* get() const noexcept { return px; }
    long use_count() const noexcept { return cb ? cb->strong.load(std::memory_order_relaxed) : 0; }

    T& operator*() const noexcept { return *px; }
    T* operator->() const noexcept { return px; }
    explicit operator bool() const noexcept { return px != nullptr; }
};

} // namespace my