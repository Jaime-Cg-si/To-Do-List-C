# C-Task-Manager

A simple yet powerful command-line task manager built purely in C, focusing on efficient memory management and a clean, modular project structure. This project is a learning exercise to deepen skills in C programming, data structures, and professional development workflows.

## Project Status

**Current Phase:** Core logic implementation.
*   ✅ **Module `task`:** Fully implemented and tested. Provides a robust, memory-safe API for creating, updating, and destroying individual task objects.
*   ⏳ **Module `list`:** In development. This module will manage a linked list of tasks.
*   ❌ **CLI (Command-Line Interface):** Not started. The main executable currently serves as a test driver for the existing modules.

## Features

### Implemented
*   **Modular Task Object:** A dedicated `task` module with a clean public API (`task.h`).
*   **Dynamic Memory Management:** Safe allocation and deallocation for tasks and their properties.
*   **Data Validation:** Robust validation of all inputs to ensure data integrity (e.g., priority levels, valid deadlines).

### Planned
*   A linked-list data structure to manage multiple tasks.
*   A command-line interface for user interaction (add, view, update, delete tasks).
*   Saving and loading tasks from a file.
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
    This will compile all source files and create the `task_manager` executable in the root directory.

3.  **Run the tests:**
    ```bash
    ./task_manager
    ```
    Currently, this runs a "smoke test" to verify the functionality of the `task` module.

## Usage

The final application will be a command-line tool. Examples will be added here once the CLI is implemented.

For now, the main entry point (`src/main.c`) is used as a test driver to validate the implemented modules.

## Technical Overview

The project is architected around modularity and safety. The core component completed is the `task` module, which exposes a public API via `include/task.h` for all CRUD (Create, Read, Update, Delete) operations on a single task.

Key technical decisions implemented so far include:
*   **Header/Implementation Separation:** A clear distinction between the public interface (`.h`) and the private implementation (`.c`) to enforce encapsulation.
*   **Defensive Programming:** All functions rigorously validate their input parameters (e.g., checking for `NULL` pointers) and internal state to prevent common C pitfalls.
*   **Strict Memory Management:** No memory leaks. All dynamically allocated memory is meticulously tracked and freed, using tools like `valgrind` for verification (a future step). The `destroy_task` function uses a pointer-to-pointer (`Task**`) to safely nullify dangling pointers after freeing memory.

## Contributing

This is a personal learning project, but feedback is welcome. The development follows a simplified GitFlow model:
- `main` contains stable, tested features.
- New features are developed in `feature/` branches and merged into `main` upon completion.