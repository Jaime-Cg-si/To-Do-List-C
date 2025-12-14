# C-Task-Manager

A simple yet powerful command-line task manager built purely in C, focusing on efficient memory management and a clean, modular project structure. This project serves as a practical exercise in applying core computer science concepts, including data structures (singly linked lists), memory-safe programming, and professional development workflows in C.

## Project Status

**Current Phase:** Core Data Structures and Logic Implementation.
*   ✅ **Module `task`:** Fully implemented and tested. Provides a robust, memory-safe API for all CRUD operations on individual task objects.
*   ✅ **Module `list`:** Fully implemented. Provides a complete API for managing a singly linked list of tasks, including creation, destruction, addition, removal, and searching.
*   ❌ **CLI (Command-Line Interface):** Not started. The `main` executable currently serves as a test driver for the core modules.

## Features

### Implemented
*   **Modular Task & List APIs:** Dedicated modules for `task` and `list` with clean public APIs (`task.h`, `list.h`) that enforce encapsulation.
*   **Singly Linked List Data Structure:** A from-scratch implementation of a singly linked list to manage a dynamic collection of tasks.
*   **Full CRUD Functionality:** Both modules support complete Create, Read, Update (for tasks), and Delete operations.
*   **Efficient Insertion:** Task addition to the list is an O(1) operation, ensuring high performance.
*   **Robust Memory Management:** Safe, dynamic allocation and deallocation for all data structures, preventing memory leaks.
*   **Defensive Data Validation:** Rigorous validation of all inputs to ensure data integrity and prevent common C pitfalls.

### Planned
*   A command-line interface for user interaction (add, view, update, delete tasks).
*   Saving and loading tasks to/from a file (persistence).
*   Sorting and filtering tasks (by priority, deadline, etc.).

## Getting Started

### Prerequisites

To compile and run this project, you will need:
*   A C compiler (e.g., GCC or Clang)
*   The `make` build automation tool

### Installation & Execution

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/SEU-USUARIO/SEU-REPOSITORIO.git
    cd SEU-REPOSITORIO
    ```

2.  **Compile the project:**
    ```bash
    make
    ```
    This will compile all source files and create the `task_manager` executable.

3.  **Run the integrated tests:**
    ```bash
    ./task_manager
    ```
    The executable currently serves as a test driver that validates the functionality of the `task` and `list` modules.

## Technical Overview

The project is architected around modularity, safety, and efficiency, implementing classic C programming patterns.

Key technical decisions implemented so far include:
*   **Data Structure Implementation:** A custom **singly linked list** was built from scratch to manage tasks. This choice provides dynamic resizing and highly efficient O(1) insertion at the head of the list.
*   **Header/Implementation Separation:** A clear distinction between public interfaces (`include/*.h`) and private implementations (`src/*.c`) to enforce encapsulation and reduce module coupling.
*   **Defensive Programming:** All API functions rigorously validate their input parameters (e.g., checking for `NULL` pointers) and internal state.
*   **Advanced Pointer-to-Pointer Usage:** The `destroy` functions for both `task` and `list` use a pointer-to-pointer (`Task**`, `List**`) to safely nullify the caller's pointer after freeing memory, effectively preventing dangling pointers.
*   **Single-Pass Removal Algorithm:** The `list_remove_task` function implements an efficient "trailing pointer" technique to find and remove a node from the linked list in a single pass, demonstrating a core data structure algorithm.

## Contributing

This is a personal learning project, but feedback is welcome. The development follows a simplified GitFlow model:
- `main` contains stable, tested features.
- New features are developed in `feature/` branches and merged into `main` upon completion.