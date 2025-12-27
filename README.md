# C-Task-Manager

A robust and efficient command-line task manager built purely in C, focusing on safe memory management, data persistence, and a clean, modular project structure. This project has evolved from an academic exercise into a fully functional console application.

## Project Status

**Current Phase:** Functional Command-Line Application (MVP - Minimum Viable Product).

The project is a complete and usable application with the following core features implemented and tested:

*   ✅ **`task` Module:** A complete API for CRUD operations on individual task objects.
*   ✅ **`list` Module:** A complete API for managing a singly linked list of tasks.
*   ✅ **Command-Line Interface (CLI):** An interactive user interface that allows for adding, listing, and saving tasks.
*   ✅ **Data Persistence:** The application state is automatically saved to a `tasks.csv` file on exit and reloaded on startup.

## Features

### Implemented
*   **Modular Architecture:** Dedicated modules for `task`, `list`, `file_io`, and `cli` with clean public interfaces (`.h`) that enforce encapsulation.
*   **Singly Linked List Data Structure:** A from-scratch implementation of a singly linked list to manage a dynamic collection of tasks.
*   **Interactive User Interface:** A robust CLI that accepts user commands (`add`, `list`, `save`, `exit`).
*   **Data Persistence in CSV:**
    *   Automatically saves the task list to a `tasks.csv` file upon exiting the program.
    *   Automatically loads tasks from `tasks.csv` when the program starts.
    *   Provides an explicit `save` command for manual persistence.
*   **Robust Memory Management:** Safe, dynamic allocation and deallocation for all data structures, preventing memory leaks.
*   **Defensive Data Validation:** Rigorous validation of all inputs to ensure data integrity.

### Planned
*   **Task Management:** Commands to `delete` and `edit` existing tasks.
*   **Advanced Search:** A `find` command to locate tasks by ID or by keywords in the name/description.
*   **Sorting and Filtering:** Features to sort tasks (by priority, deadline, etc.).

## Getting Started

### Prerequisites

To compile and run this project, you will need:
*   A C compiler (e.g., GCC or Clang)
*   The `make` build automation tool

### Installation & Execution

1.  **Clone the repository:**
```bash
    git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
    cd YOUR-REPOSITORY