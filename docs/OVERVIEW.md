# Project Overview — Student Gradebook Management System (C++)

## What this project is
A console application that manages a small class gradebook in memory. It supports CRUD operations plus reporting:

- Add a student (ID, name, marks)
- Update one assessment mark
- Print an individual student report
- Print class summary + ranking
- List all students
- Delete a student

## Main limits (by design)
- Up to 50 students
- Up to 8 assessments per student
- IDs and names stored in fixed-size character arrays

## High-level flow
1. Ask for number of assessments (1–8)
2. Loop menu options until Exit
3. Each option calls a dedicated function that validates input and updates arrays

## Data storage model
The program uses three parallel arrays:
- `ids[i]`, `names[i]`, and `marks[i][...]` all belong to the same student index `i`.
`studentCount` tracks active records.