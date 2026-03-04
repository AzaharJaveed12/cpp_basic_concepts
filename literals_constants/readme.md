## 1) Variables first

### “constant” (the idea, not a keyword)

In C++, a *constant* is usually “a value you can’t modify” (const-qualified) **or** “a value that is known at compile time” (a *constant expression*). These are different.

* `const int x = 5;` → **read-only**, but not necessarily compile-time.
* `constexpr int y = 5;` → **must be compile-time evaluatable** (with rules), so it *is* a compile-time constant.

---

## `const` (since C++98)

**Meaning for variables:** “This object is not modifiable through this name/type.”

Key points:

* `const` does **not** guarantee compile-time evaluation.
* Whether it becomes a compile-time constant depends on initialization and rules for “constant expression”.

```cpp
const int a = 10;        // can be a constant expression (if initialized with const-exp)
int n = 3;
const int b = n;         // NOT a constant expression (runtime value)
```

**Linkage nuance (important):**

* A namespace-scope `const` variable has **internal linkage by default** (unless `extern`), which affects ODR and headers.

---

## `constexpr` for variables (since C++11)

**Meaning for variables:** “This variable is a constant expression (where required) and is implicitly `const`.”

* Must be initialized immediately.
* The initializer must be evaluatable at compile time.
* The value is usable in contexts requiring compile-time constants: array bounds, `case` labels, template non-type params, etc.

```cpp
constexpr int k = 64;           // compile-time
int n = 2;
// constexpr int bad = n;       // ERROR: not constant expression
```

**Important nuance:** `constexpr` does **not** always mean “no storage / no runtime at all”. The compiler can still allocate storage if it’s ODR-used.

---

## `constinit` (since C++20)

**Meaning for variables:** “This object must be *statically initialized* (no dynamic initialization).”

What it guarantees:

* The initialization happens **at program start without running runtime code** (no “dynamic initialization” / no “static init order fiasco” due to runtime init).
* It **does not** mean “compile-time constant” like `constexpr`.

```cpp
constinit int g = 42;       // OK: constant initialization
int f();
constinit int h = f();      // ERROR: would require dynamic init
```

**Why it exists:** You may want a **mutable global/static** that’s guaranteed to be initialized safely before any dynamic initialization order issues:

```cpp
constinit int global_counter = 0;  // mutable, but safe static initialization
```

---

## `consteval` (C++20) — **not for variables directly**

`consteval` is a **function specifier only**. It makes a function an *immediate function*: every call must be evaluated at compile time (more on this in the functions section).

---

### Will variable forms be “defined at compile time”?

* `const` → **maybe**. Only if it qualifies as a constant expression and is used in compile-time contexts.
* `constexpr` → **yes, the initializer must be compile-time** (subject to rules).
* `constinit` → **static initialization**, but not necessarily a constant expression usable everywhere. It’s about *when/how it initializes*, not “usable as compile-time value”.

---

## 2) Functions next

### `constexpr` functions (since C++11; expanded significantly in C++14/17/20)

**Meaning:** the function *can* be evaluated at compile time **if** called with constant-expression arguments and if the body obeys constexpr rules.

* It’s *dual-use*: can run at runtime too.
* Rules loosened over versions:

  * **C++11**: very restricted (single return statement, etc.)
  * **C++14**: allowed more statements (loops, locals)
  * **C++20**: even richer (more standard library made `constexpr`, allowing wider compile-time computation)

```cpp
constexpr int sq(int x) { return x * x; }

constexpr int a = sq(5); // compile-time
int n = 4;
int b = sq(n);           // runtime (still allowed)
```

### `consteval` functions (since C++20)

**Meaning:** every call **must** be compile-time. If the call can’t be evaluated at compile time, it’s an error.

```cpp
consteval int id(int x) { return x; }

constexpr int a = id(10); // OK
int n = 3;
// int b = id(n);         // ERROR: n not constant expression => cannot call consteval
```

**Common use:** enforce compile-time validation / parsing:

* validate format strings, IDs, bitmasks
* compute lookup tables at compile time

---

## 3) Classes / types (and objects of class type)

### `constexpr` objects of class type (since C++11, improved later)

You can have `constexpr` variables whose type is a literal type and whose construction is constexpr-capable.

```cpp
struct Vec {
    int x, y;
    constexpr Vec(int a, int b) : x(a), y(b) {}
    constexpr int sum() const { return x + y; }
};

constexpr Vec v{2, 3};           // compile-time construction
static_assert(v.sum() == 5);
```

### `constexpr` constructors / member functions

* Mark constructors and member functions `constexpr` to allow compile-time construction and use.
* This gets more powerful as constexpr rules expanded in later standards (C++14/17/20).

### `constinit` with class types (since C++20)

You can require static initialization for global/static objects even for class types **only if** they qualify for constant initialization.

```cpp
struct S {
    int x;
    constexpr S(int v) : x(v) {}
};

constinit S s{10};   // OK if this is constant initialization
```

If the initialization would require runtime work, it’s rejected.

### `consteval` and classes

Again, `consteval` is for functions. You might use consteval factory functions that return class objects, forcing compile-time construction/validation:

```cpp
struct Token { int v; };

consteval Token make_token(int x) {
    // validate x at compile time
    if (x <= 0) throw "invalid"; // conceptually; usually use static_assert-like patterns
    return Token{x};
}

constexpr Token t = make_token(7); // OK
```

(Real code usually uses `static_assert` via templates or conditional compilation patterns rather than `throw`.)

---

## So… will *all this* be defined at compile time?

No—**only some of it is guaranteed**:

* `constexpr` variable: initializer must be compile-time evaluatable.
* `constexpr` function: may be compile-time *or* runtime depending on call site.
* `consteval` function: **always compile-time**.
* `constinit` variable: **initialization is static** (no dynamic init), but the value might not be usable as a compile-time constant expression in every context.
* `const`: does not guarantee compile time.

---

## Comparison table (variables → functions → classes)

| Feature                         |                                     Introduced | Applies to                                          | What it guarantees                                                                | Compile-time required? | Can still run at runtime?                      | Typical use                                                         |
| ------------------------------- | ---------------------------------------------: | --------------------------------------------------- | --------------------------------------------------------------------------------- | ---------------------- | ---------------------------------------------- | ------------------------------------------------------------------- |
| `const`                         |                                          C++98 | variables, members, params, funcs (`const` methods) | “not modifiable through this type/name”                                           | ❌                      | ✅                                              | API contracts, immutability, overload selection (`T const&`)        |
| “constant expression” (concept) | C++11 formalized (exists earlier conceptually) | expressions/values                                  | usable where compile-time value required                                          | ✅ (when required)      | n/a                                            | array sizes, `case`, template NTTP, `static_assert`                 |
| `constexpr` variable            |                                          C++11 | variables                                           | initializer must be constant evaluatable; value usable as const-exp               | ✅                      | n/a (value may still have storage if ODR-used) | compile-time values, NTTP, headers, config constants                |
| `constinit` variable            |                                          C++20 | variables with static storage duration              | **no dynamic initialization** (prevents static init order issues)                 | ❌ (not necessarily)    | n/a                                            | safe globals/statics that must be initialized early and predictably |
| `constexpr` function            |                   C++11 (expanded C++14/17/20) | functions/ctors/members                             | may be evaluated at compile time when used in const-exp context                   | ❌ (depends on call)    | ✅                                              | single-source logic for compile-time + runtime                      |
| `consteval` function            |                                          C++20 | functions/ctors (immediate)                         | every call is evaluated at compile time                                           | ✅                      | ❌                                              | compile-time validation, parsing, generating tables/IDs             |
| `constexpr` class object        |                                          C++11 | objects of literal types                            | object can be created/used in const-exp context if constructors/members constexpr | ✅ (when used that way) | ✅ (same type can exist at runtime too)         | compile-time geometry, fixed config objects                         |
| `constinit` class object        |                                          C++20 | static storage objects                              | static initialization only (rejects dynamic init)                                 | ❌                      | n/a                                            | safe singletons/globals without init-order bugs                     |

If you want, next I can add **edge cases** you’ll get asked in interviews (ODR-use, storage, `inline constexpr` variables in headers, `constinit` vs function-local statics, and why `constinit` doesn’t imply “compile-time constant”).
