# 🚀 Complete C++ Mastery Checklist
## Beginner → C++17 Interview Ready → C++20 Aware

> 🎯 Goal: Crack C++17 Interviews  
> 🎯 Bonus: Confidently say you know Modern C++ (C++20 aware)  
> 📅 Each topic includes version introduced  
> 🔥 Includes daily industry-use concepts  

---

# 🟢 PHASE 1 — Core Foundation (C++98 / C++03)

## ✅ Program Structure (C++98)

- [✅ ] Structure of C++ program
- [ ✅] main() function
- [ ✅] Compilation process (Preprocess → Compile → Link)
- [ ✅] Header files
- [ ✅] Namespaces
- [ ✅] Using vs fully qualified names
- [ ✅] Basic I/O (cin, cout)
- [✅] endl vs "\n"
- [✅] Data types
- [✅] sizeof
- [✅] enum vs enum class (enum class C++11)
- [✅ ] const correctness basics
- [✅] typedef (using alias C++11)

📅 Introduced: C++98

---

## ✅ Control Flow (C++98)

- [✅] if / else
- [✅] switch
- [✅] for / while / do-while
- [✅] break / continue
- [✅] Scope rules
- [✅] Ternary operator

---

## ✅ Functions (C++98)

- [✅] Declaration vs definition
- [✅] Overloading
- [✅] Default arguments
- [✅] Inline functions -- 🧐
- [✅] Pass by value
- [✅] Pass by reference
- [✅] Pass by const reference
- [✅] Function pointers
- [✅] Pointer to member function

---

# 🟡 PHASE 2 — Memory, Pointers & References

## ✅ Pointers (C++98)

- [ ] Pointer basics
- [ ] Dereferencing
- [ ] Double pointer
- [ ] new / delete
- [ ] Memory leaks
- [ ] Dangling pointer
- [ ] nullptr (C++11)

---

## ✅ References (C++98 / C++11)

### Basic
- [ ] lvalue reference (T&)
- [ ] const reference (const T&)
- [ ] Lifetime extension rule
- [ ] Why const T& binds temporary

### Rvalue References (C++11)
- [ ] T&&
- [ ] std::move
- [ ] std::forward
- [ ] Named rvalue reference is lvalue
- [ ] Reference collapsing rules
- [ ] Forwarding reference

### In Multithreading
- [ ] std::ref
- [ ] std::cref

📅 Rvalue reference introduced: C++11

---

## ✅ Value Categories (C++11)

- [ ] lvalue
- [ ] prvalue
- [ ] xvalue
- [ ] glvalue
- [ ] rvalue
- [ ] Temporary materialization (C++17)

---

# 🟠 PHASE 3 — OOP & Object Lifetime

## ✅ Classes & Objects (C++98)

- [ ] Constructors
- [ ] Destructor
- [ ] Member initializer list
- [ ] const member functions
- [ ] Static members
- [ ] Friend

---

## ✅ Rule of 3 / 5 / 0

- [ ] Copy constructor (C++98)
- [ ] Copy assignment (C++98)
- [ ] Destructor (C++98)
- [ ] Move constructor (C++11)
- [ ] Move assignment (C++11)
- [ ] Rule of Zero

🔥 Interview Critical

---

## ✅ Inheritance & Polymorphism (C++98)

- [ ] Virtual functions
- [ ] Virtual destructor
- [ ] override (C++11)
- [ ] final (C++11)
- [ ] Object slicing
- [ ] Diamond problem
- [ ] Virtual inheritance

---

# 🔵 PHASE 4 — STL & Algorithms

## ✅ Containers

### Sequence
- [ ] vector
- [ ] deque
- [ ] list
- [ ] array (C++11)
- [ ] forward_list (C++11)

### Associative
- [ ] map
- [ ] set
- [ ] multimap
- [ ] multiset

### Unordered (C++11)
- [ ] unordered_map
- [ ] unordered_set

---

## ✅ Iterator Mastery

- [ ] Iterator categories
- [ ] begin / end
- [ ] const_iterator
- [ ] reverse_iterator
- [ ] Invalidation rules

---

## ✅ Algorithms (C++98)

- [ ] sort
- [ ] find
- [ ] transform
- [ ] accumulate
- [ ] remove_if
- [ ] lower_bound
- [ ] binary_search
- [ ] erase-remove idiom

---

## ✅ Lambda (C++11)

- [ ] Capture by value
- [ ] Capture by reference
- [ ] Mutable lambda
- [ ] Generic lambda (C++14)

---

# 🟣 PHASE 5 — Modern C++ Core (C++11 → C++17)

## ✅ auto (C++11)

- [ ] Type deduction rules
- [ ] auto&
- [ ] auto&&

---

## ✅ Smart Pointers (C++11)

- [ ] unique_ptr
- [ ] shared_ptr
- [ ] weak_ptr
- [ ] make_unique (C++14)
- [ ] Custom deleter
- [ ] Circular reference problem

---

## ✅ Move Semantics (C++11)

- [ ] Move vs Copy
- [ ] std::move
- [ ] Perfect forwarding
- [ ] std::move_if_noexcept

---

## ✅ constexpr

📅 C++11 (basic)  
📅 C++14 (relaxed)  
📅 C++17 (stronger)

- [ ] constexpr variable
- [ ] constexpr function
- [ ] constexpr constructor
- [ ] if constexpr (C++17)
- [ ] Compile-time recursion
- [ ] const vs constexpr difference

---

## ✅ Variadic Templates (C++11)

- [ ] Parameter packs
- [ ] Fold expressions (C++17)

---

## ✅ Type Traits (C++11)

- [ ] is_integral
- [ ] is_same
- [ ] enable_if
- [ ] void_t (C++17)

---

## ✅ Casting Types

- [ ] C-style cast
- [ ] static_cast
- [ ] dynamic_cast
- [ ] const_cast
- [ ] reinterpret_cast
- [ ] When dynamic_cast works
- [ ] Safe downcasting

---

## ✅ C++17 Additions

- [ ] Structured bindings
- [ ] std::optional
- [ ] std::variant
- [ ] std::any
- [ ] Filesystem
- [ ] Inline variables
- [ ] if constexpr

---

# 🔴 PHASE 6 — Multithreading (C++11+)

## ✅ Threads

- [ ] std::thread
- [ ] join
- [ ] detach
- [ ] RAII thread wrapper

---

## ✅ Synchronization

- [ ] mutex
- [ ] lock_guard
- [ ] unique_lock
- [ ] recursive_mutex
- [ ] scoped_lock (C++17)
- [ ] condition_variable
- [ ] atomic
- [ ] Memory order basics

---

# 🟡 PHASE 7 — Exception Safety

- [ ] try / catch
- [ ] Stack unwinding
- [ ] noexcept (C++11)
- [ ] Strong vs Basic guarantee
- [ ] noexcept in move constructor

---

# 🟣 PHASE 8 — C++20 Awareness

## ✅ Concepts (C++20)

- [ ] Define concept
- [ ] requires clause
- [ ] Replace enable_if

---

## ✅ Three-way comparison <=> (C++20)

---

## ✅ Ranges (C++20)

- [ ] views::filter
- [ ] views::transform

---

## ✅ consteval (C++20)

---

## ✅ constinit (C++20)

---

# 🔥 FINAL INTERVIEW READINESS CHECK

You are C++17 ready if:

- [ ] You deeply understand object lifetime
- [ ] You can implement a simple smart pointer
- [ ] You understand move semantics deeply
- [ ] You know STL internals (vector growth, map tree)
- [ ] You understand threading basics
- [ ] You understand references deeply
- [ ] You can explain constexpr clearly

---

# 🚀 If You Complete All Above

You can confidently say:

"I am strong in C++17 and familiar with modern C++20 features including concepts and ranges."
