#include <atomic>

struct ControlBlockBase {
    std::atomic<long> strong{1}; // shared owners
    std::atomic<long> weak{1};   // weak refs + 1 while object alive
    virtual void destroy_object() noexcept = 0;
    virtual ~ControlBlockBase() = default;
};