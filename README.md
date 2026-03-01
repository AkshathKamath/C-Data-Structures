# Interpreted Language Runtime System

A dynamic runtime system and memory management implementation in C, along with Garbage Collection.

## Motivation

Learning systems programming in C by implementing the foundational runtime components of a programming language - managing dynamic types, heap memory, and garbage collection from scratch.

## Current Features

### Dynamic Type System

- **Tagged unions** for runtime type identification
- Heap-allocated objects (similar to Python)
- Support for: integers, floats, strings, arrays

### Data Structures

- Dynamic Arrays (for array objects)
- Stack (for VM frames and object storage)

### Memory Management

- Heap allocation for all objects
- Mark-and-Sweep Garbage Collector (with mark, trace, sweep phases)
- Reference counting infrastructure

### Virtual Machine

- Frame-based execution environment
- Root object tracking for GC
- Object and frame stacks

## Project Structure

```
.
├── main.c                    # Entry point
├── Virtual-Machine/          # VM implementation
│   ├── vm.h
│   └── vm.c
├── Heap-Objects/
│   ├── Primitive-Objects/    # Integer, float, string, array types
│   │   ├── object.h
│   │   └── object.c
│   ├── Dynamic-Array/        # Array container implementation
│   │   ├── dynamic_array.h
│   │   └── dynamic_array.c
│   └── Stack/                # Stack data structure
│       ├── stack.h
│       └── stack.c
└── Garbage-Collector/
    ├── Mark-and-Sweep/       # Full GC implementation
    │   ├── ms.h
    │   └── mark-and-sweep.c
    └── Reference-Counting/
        ├── ref_counter.h
        └── ref_counter.c
```
