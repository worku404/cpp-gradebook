# Student Gradebook Management System (C++)

A small, console-based **gradebook management system** that lets you maintain a class roster, record assessment scores, and generate both **individual student reports** and **class-level summaries**.  

From an industry perspective, this project practices what real software teams care about early: **input validation, consistent data representation, reporting, and maintaining state across user operations**—all common in admin tools, internal dashboards, and CRUD-style systems.

---

## What the Program Does

The application stores up to **50 students**, each with up to **8 assessments**. Through a menu-driven interface, you can:

- **Add** a new student (ID, name, and assessment scores)
- **Update** a student’s score for a chosen assessment
- **Generate** an **individual student report** (total, min, max, average, letter grade, pass/fail)
- **Generate** a **class summary** (class average, highest/lowest average, pass rate)
- Show a **performance ranking** (sorted by average, highest → lowest)
- **List** all student records (ID, name, average, grade)
- **Delete** a student record (and shift the arrays to close the gap)

---

## Core Constraints (Design Choices)

These constants control program limits:

- `MAX_STUDENT = 50` → maximum number of students in memory
- `MAX_TESTS = 8` → maximum number of assessments per student
- `ID_LEN = 11` → max characters for stored IDs (including null terminator)
- `NAME_LEN = 32` → max characters for stored names (including null terminator)

### Student ID rule
A student ID **must start with** `ets` or `ETS`.  
The program normalizes IDs to **lowercase** for consistent lookups.

---

## How Data Is Stored (Why This Matters)

The program uses **fixed-size arrays**:

- `char ids[MAX_STUDENT][ID_LEN]`
- `char names[MAX_STUDENT][NAME_LEN]`
- `double marks[MAX_STUDENT][MAX_TESTS]`
- `int studentCount`

This is a classic “static table” approach: fast, predictable, and simple.  
In real systems, you’d often replace this with `std::vector`, structs/classes, and persistent storage (files/DB). But for learning and for small tools, this is a solid way to practice correctness, boundaries, and indexing discipline.

---

## Menu Overview

When you run the program, it asks:

1. **Number of assessments** per student (1–8)

Then it loops over this menu:

- `1)` Add a student record  
- `2)` Update a student's assessment score  
- `3)` Generate an individual student report  
- `4)` Generate class summary and performance ranking  
- `5)` Display all student records  
- `6)` Delete a student record  
- `0)` Exit  

---

## Grading Logic

The program computes:

- **Total** = sum of assessment marks
- **Average** = total / number of assessments
- **Min/Max** marks across assessments
- **Letter grade** from the average:

| Average | Grade |
|--------:|:------|
| > 90    | A+ |
| ≥ 85    | A  |
| ≥ 80    | A- |
| ≥ 75    | B+ |
| ≥ 70    | B  |
| ≥ 65    | B- |
| ≥ 60    | C+ |
| ≥ 50    | C- |
| < 50    | F  |

**Pass/Fail:** Pass if average ≥ 50.

---

## Input Validation (Reliability)

This project emphasizes robust console input handling:

- `readNum()` repeats until a valid number is entered
- `readNumRange()` enforces numeric bounds (e.g., 0–100)
- `readName()` and `readId()` enforce maximum length and required format
- `clearBadInput()` resets `cin` after bad input to prevent infinite failure loops

This is exactly the kind of defensive programming that prevents “works on my machine” bugs in production tools.

---

## How to Build and Run (Windows)

### Option A: g++ (MinGW / MSYS2)
From the project folder:

```
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp -o gradebook
.\gradebook.exe
```

> If your file isn’t named `main.cpp`, replace it with your actual filename.

### Option B: Visual Studio / MSVC
If using the **Developer Command Prompt for VS**:

```
cl /EHsc /std:c++17 main.cpp
main.exe
```

---

## Typical Usage Flow

1. Choose number of assessments (e.g., 4)
2. Add students (ID, name, scores)
3. List students to verify data
4. Generate student reports or class summary/ranking
5. Update marks if needed
6. Delete a student if they drop the course

---

## Known Limitations (Future Engineering Improvements)

If you continue this project (good portfolio upgrade), here are high-value steps:

- Replace parallel arrays with a `struct Student { id, name, vector<double> marks; }`
- Use `std::vector<Student>` instead of fixed-size arrays
- Persist data to a file (CSV/JSON) so the gradebook survives program exit
- Improve ID rules (length, allowed characters) and ensure uniqueness reliably
- Fix minor type consistency: `maxScore()` currently returns `int` but works with `double`

These are the same refactors you’d do in industry when a prototype becomes a maintained tool.

---

## License / Academic Note

This project is intended for educational use in learning C++ fundamentals and basic software engineering practices (validation, reporting, and stateful CRUD operations).
