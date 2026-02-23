🧭 PHASE 0 — Ground Rules (Read Once)

Compiler & Tooling (fixed for entire journey):

Compiler: GCC ≥ 13 / Clang ≥ 16

Standard: C++20 only

Build system: CMake

OS target: Linux first (portable to macOS/Windows later)

IDE: VS Code / CLion

Why?
Adobe & Google care about modern, disciplined C++, not legacy tricks.

🧩 PHASE 1 — Modern C++20 Core (Deep, Not Wide)

Goal: Write clean, safe, expressive C++ without undefined behavior.

1.1 Language Fundamentals (C++20 mindset)
Concepts to master

Translation units & ODR

auto, decltype(auto)

Uniform initialization {} pitfalls

constexpr, consteval, constinit

Value categories (lvalue, rvalue, prvalue)

Copy elision & NRVO

explicit, =delete, =default

Why Adobe/Google care

Prevents subtle ABI & performance bugs

STL example using this

std::array

Fixed-size, constexpr-friendly

Zero-overhead abstraction vs C arrays

1.2 Type System & Templates (Critical)
Concepts

Function templates vs class templates

Template specialization (partial & full)

Concepts (requires)

Type traits (std::is_*)

SFINAE → replaced by concepts

std::enable_if (legacy but must know)

Key C++20 feature
template<typename T>
concept Serializable = requires(T a) {
    { a.serialize() } -> std::same_as<std::string>;
};

STL example

std::span

Template-based view

Zero copy, bounds-safe

Replaces raw pointer + size pairs

1.3 RAII & Object Lifetime (Non-Negotiable)
Concepts

RAII pattern

Rule of 0 / 3 / 5

Stack vs heap lifetime

Smart pointers (unique_ptr, shared_ptr, weak_ptr)

Custom deleters

Move semantics

STL example

std::unique_ptr

Enforces ownership

Eliminates entire class of memory leaks

1.4 Error Handling & Contracts
Concepts

Exceptions vs error codes

noexcept correctness

Strong / basic exception safety

std::optional

std::expected (C++23 — conceptually important)

Assertions (assert, static_assert)

STL example

std::optional

Explicit absence instead of null pointers

🧱 PHASE 2 — C++20 OOP (Industry Style)

Goal: Correct abstraction, not Java-style inheritance abuse.

2.1 OOP Fundamentals (Modern C++ flavor)
Concepts

Encapsulation with value semantics

Composition over inheritance

Polymorphism via interfaces

Virtual destructors

final, override

Non-virtual interface (NVI)

STL example

std::iostream

Polymorphic stream hierarchy

Base class interface + derived implementations

2.2 Interfaces & Dependency Injection
Concepts

Pure abstract base classes

Runtime vs compile-time polymorphism

Dependency injection (manual, no frameworks)

PIMPL idiom

STL example

std::allocator

Injected memory strategy

Used everywhere in STL containers

2.3 SOLID Principles (C++ Reality)
Principle	C++ Interpretation
SRP	Header/source separation
OCP	Templates + interfaces
LSP	No slicing, correct polymorphism
ISP	Fine-grained interfaces
DIP	Constructor injection
STL example

std::function

Type-erased callable

Dependency inversion tool

⚙️ PHASE 3 — Multithreading & Concurrency (C++20 Level)

This is where C++ beats Java & Python.

3.1 Threading Basics
Concepts

std::thread

Join vs detach

Race conditions

Data races vs race conditions

Mutex, lock_guard, unique_lock

STL example

std::mutex

Low-level primitive

Used by most STL thread-safe components

3.2 Modern Synchronization
Concepts

std::atomic

Memory ordering (acquire/release/relaxed)

Condition variables

std::barrier, std::latch

std::jthread (C++20)

STL example

std::atomic

Lock-free programming backbone

3.3 Thread Pools & Task Systems
Concepts

Producer–consumer

Work stealing

Futures & promises

Async execution models

STL example

std::async

Simplified task abstraction

🗂️ PHASE 4 — Project Structure (Maven-Level Discipline)

C++ projects fail due to bad structure, not language issues.

4.1 CMake (Mandatory)
Concepts

Targets, not variables

Interface vs static vs shared libraries

FetchContent

Toolchains

Presets (CMakePresets.json)

Example structure
inventory-system/
├── CMakeLists.txt
├── src/
│   ├── core/
│   ├── domain/
│   ├── storage/
│   └── api/
├── include/
├── tests/
├── docker/
└── third_party/

STL example

LLVM project

Massive modular CMake setup

Industry gold standard

4.2 Dependency Management
Tools

vcpkg

Conan

Why it matters

Reproducible builds (Google-level requirement)

🧠 PHASE 5 — Memory Management & Leak Detection

If you fail here, you fail interviews.

5.1 Common Memory Bugs

Use-after-free

Double delete

Dangling references

Memory fragmentation

5.2 Free Tools (Must Know)
Tool	Purpose
AddressSanitizer	Detect UAF, leaks
LeakSanitizer	Memory leaks
UndefinedBehaviorSanitizer	UB
Valgrind	Heap analysis
Heaptrack	Allocation profiling
STL example

std::vector

Exception-safe growth

Custom allocator support

🧩 PHASE 6 — Design Patterns (C++-Specific)

Learn why C++ implements patterns differently.

Must-know patterns
Creational

Factory

Abstract Factory

Builder

Singleton (careful!)

Structural

Adapter

Decorator

Proxy

PIMPL

Behavioral

Strategy

Observer

Command

State

C++-specific

RAII

Type erasure

CRTP

STL examples
Pattern	STL Example
Iterator	All containers
Strategy	std::sort comparator
Observer	std::condition_variable
Type Erasure	std::any, std::function
🏗️ PHASE 7 — System Design for C++ Backends

This is Adobe / Google territory.

7.1 Core Concepts

API design (header stability)

ABI compatibility

Zero-copy design

Cache locality

Latency vs throughput

Lock-free vs lock-based

Memory pools

7.2 Inventory Management Architecture
Components
API Layer (REST / gRPC)
↓
Service Layer (business rules)
↓
Domain Model (Product, Order, Stock)
↓
Storage Adapter (Redis)
↓
Persistence Cache

7.3 Redis Integration (C++)
Concepts

Connection pooling

Serialization (JSON / Protobuf)

Expiry & TTL

Atomic updates (Lua scripts)

Library

redis-plus-plus

🐳 PHASE 8 — Docker & Deployment
Concepts

Multi-stage Docker builds

Static vs dynamic linking

Alpine vs Ubuntu images

Health checks

Example
FROM gcc:13 AS build
FROM debian:bookworm-slim

🎯 FINAL PROJECT (Capstone)
Inventory Management System

Features

CRUD products

Stock tracking

Concurrent order processing

Redis-backed persistence

Thread-safe design

Dockerized deployment

Evaluation checklist (interview-ready)

No raw new/delete

Clear ownership

Lock-free where possible

Sanitizers clean

Modular CMake

Documented APIs

📌 How This Cracks Adobe & Google

They evaluate:
✔ Code clarity
✔ Ownership & lifetime
✔ Concurrency correctness
✔ Build discipline
✔ Design tradeoffs

This roadmap hits all of them.

If you want, next I can:

Break this into a 12-week daily study plan

Design the exact inventory system class diagram

Provide interview-grade C++ design questions based on this roadmap

Just tell me how deep you want to go 🔥