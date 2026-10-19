# Student Management System (C++)

A console application to manage student records, written in C++ on Linux (WSL). I rebuilt it step by step to refresh my C++ skills after a career break, adding one new idea at each stage.

## Features

- Show all students
- Add a student (ID, name, marks)
- Search for a student by ID
- Update a student's marks
- Delete a student
- Sort students by marks (highest first)
- Check the result for a student (pass if marks are 40 or more)

## What I used

- **A class:** `StudentManager` keeps the student list private and gives public functions for each menu option.
- **Separate files:** `StudentManager.h` (declarations), `StudentManager.cpp` (function bodies) and `main.cpp` (the menu).
- **STL:** `std::vector`, `std::find_if` and `std::sort` with lambdas.
- **`std::optional`:** `findStudent` returns a student, or nothing if the ID is not found.
- **CMake:** builds the program and the tests.
- **Google Test:** unit tests for `findStudent`.
- **Git and GitHub:** one commit for each step.

## Project files

| File | What it contains |
|------|------------------|
| `StudentManager.h` | The `Student` struct and the `StudentManager` class declaration |
| `StudentManager.cpp` | The code for each `StudentManager` function |
| `main.cpp` | The menu that calls the class functions |
| `test_student.cpp` | Google Test unit tests |
| `CMakeLists.txt` | Build instructions for CMake |

## How to build and run

You need `g++`, CMake and Google Test (`sudo apt install cmake libgtest-dev` on Ubuntu).

```bash
cmake -S . -B build
cmake --build build
./build/app
```

## How to run the tests

```bash
./build/tests
```

Current tests:

- `FindsAnuById`: searching for ID 2 finds the student Anu.
- `StudentNotFound`: searching for ID 99 finds no student.

## What I learned

- Why a class keeps data private and exposes only the functions that are needed.
- How to return "maybe a value" safely with `std::optional`, and never read from an empty result.
- How header and source files work together, and why CMake lists only the `.cpp` files.
- How to write unit tests that check both the "found" and the "not found" cases.
