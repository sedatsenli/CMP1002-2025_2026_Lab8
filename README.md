# Lab: More Details about Classes

**Course:** Object-Oriented Programming (C++)  
**Level:** 2nd Year Engineering  
**Duration:** 60 minutes  

---

## Learning Objectives

By the end of this lab, students will be able to:

1. Define and use **const member functions** correctly
2. Call methods on **const objects** without compile errors
3. Initialize class members using **member initializer lists**
4. Design classes that use **composition** (objects as members)
5. Declare and implement **friend functions** and **friend classes**
6. Understand when a member initializer list is *required* (e.g., when a member has no default constructor)

---

## Prerequisites

- Basic class syntax (constructors, getters, private/public)
- Understanding of `const` for variables
- Familiarity with `std::abs`

---

## File Structure

```
lab/
├── student/
│   └── MainProgram.cpp       ← Your working file
├── teacher/
│   └── MainProgram.cpp       ← Reference solution (do not open until done)
├── test.cpp                  ← Catch2 automated tests
├── catch_amalgamated.hpp     ← Catch2 header
├── catch_amalgamated.cpp     ← Catch2 implementation
├── Makefile
├── README.md
├── explain.txt               ← Quick revision sheet (read first)
└── explain.md                ← Structured concept guide
```

---

## Instructions

### Step 1 — Read the revision sheet first
Open `explain.txt` for a 2-minute overview of all topics.

### Step 2 — Open `student/MainProgram.cpp`
Work through the TODO markers in order. Each TODO is numbered and corresponds to a specific concept.

### Step 3 — Compile your work

```bash
make
```

This compiles `student/MainProgram.cpp` into an executable called `program`.

### Step 4 — Run your program

```bash
./program
```

### Step 5 — Run the automated tests

```bash
make test
```

This runs all Catch2 unit tests against your implementation.  
Each TEST_CASE is labelled (A, B, C, D) to match the rubric below.

---

## How to Read Test Output

- `PASSED` — your implementation is correct for that case
- `FAILED` — something is wrong; read the assertion details
- Run a specific group only (example, group B):

```bash
./run_tests "[rectangle]"
```

---

## Submission Instructions

Submit only:  
```
student/MainProgram.cpp
```

Do **not** modify `test.cpp`, `catch_amalgamated.hpp`, or `catch_amalgamated.cpp`.

---

## Common Mistakes

| Mistake | Fix |
|---|---|
| Forgetting `const` on getter methods | Add `const` after the parameter list: `int getX() const` |
| Calling a non-const method on a const object | Make the method `const`, or don't call it on a const object |
| Not using member initializer list for `Point` inside `Rectangle` | `Rectangle(...) : topLeft(x1,y1), bottomRight(x2,y2) {}` |
| Forgetting to declare `friend` inside the class | `friend bool isSameSize(...)` goes *inside* the class body |
| Using `=` assignment inside constructor body instead of initializer list | Move initialization to `: member(value)` syntax |
| `getWidth()` returning negative values | Use `std::abs()` from `<cmath>` |

---

## Academic Integrity

All submitted work must be your own. You may discuss concepts with classmates, but do not share or copy code. Any form of plagiarism will result in a grade of zero and may be reported to the academic integrity office.
