# Student Management System (C++)

An application to manage student records, written in C++ on Linux (WSL). It has a console menu and a Qt desktop window (GUI) that share the same `StudentManager` class. I rebuilt it step by step to refresh my C++ skills after a career break, adding one new idea at each stage.

## Features

### Console app (`./build/app`)

- Show all students
- Add a student (ID, name, marks)
- Search for a student by ID
- Update a student's marks
- Delete a student
- Sort students by marks (highest first)
- Check the result for a student (pass if marks are 40 or more)

### Qt GUI (`./build/gui`)

- Shows all students in a list
- **Add Student** shows the ID, Name and Marks boxes only when needed; pressing Enter moves to the next box, and Enter in the last box adds the student
- Refuses an ID that is already used (even by a deleted student) and shows a warning pop-up
- **Delete** keeps the student in the list but crosses the name out (a "soft delete"), like a university that never reuses a roll number
- **Restore** brings back a student who was deleted by mistake
- Every change is saved to `students.txt` and loaded again when the app starts

## What I used

- **A class:** `StudentManager` keeps the student list private and gives public functions for each menu option.
- **Separate files:** `StudentManager.h` (declarations), `StudentManager.cpp` (function bodies) and `main.cpp` (the menu).
- **STL:** `std::vector`, `std::find_if` and `std::sort` with lambdas.
- **`std::optional`:** `findStudent` returns a student, or nothing if the ID is not found.
- **Qt 6 Widgets:** `QListWidget`, `QLineEdit`, `QPushButton`, `QVBoxLayout`, `QMessageBox`, and signals connected to lambdas with `QObject::connect`.
- **File saving:** `std::ofstream` and `std::ifstream` read and write `students.txt`.
- **Function overloading:** `addStudent` and `deleteStudent` have a console version (asks with `cin`) and a version that takes the data as a parameter, for the GUI.
- **CMake:** builds the console app, the GUI and the tests.
- **Google Test:** unit tests for `findStudent`.
- **Git and GitHub:** one commit for each step.

## Project files

| File | What it contains |
|------|------------------|
| `StudentManager.h` | The `Student` struct and the `StudentManager` class declaration |
| `StudentManager.cpp` | The code for each `StudentManager` function |
| `main.cpp` | The console menu that calls the class functions |
| `gui_main.cpp` | The Qt window that calls the same class functions |
| `test_student.cpp` | Google Test unit tests |
| `CMakeLists.txt` | Build instructions for CMake |

## How to build and run

You need `g++`, CMake, Google Test and Qt 6 (`sudo apt install cmake libgtest-dev qt6-base-dev` on Ubuntu).

```bash
cmake -S . -B build
cmake --build build
./build/app    # console menu
./build/gui    # Qt window
```

The GUI creates `students.txt` in the folder you run it from. This file is in `.gitignore`, so each person starts with their own data.

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
- How one class can serve two front ends (console and GUI) without changing its data.
- How Qt signals work: connect *who* (a button), *when* (clicked) and *what to do* (a lambda).
- How to save data to a file and load it back, and why a "soft delete" is safer than erasing records.