# User Guide — Student Gradebook Management System (C++)

## Run (Windows)
### g++
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp -o gradebook
.\gradebook.exe
```

### MSVC
```bat
cl /EHsc /std:c++17 main.cpp
main.exe
```

## Startup
Enter the number of assessments per student (1–8). This value stays fixed for the entire run.

## Rules
### Student ID
- Must start with `ets` or `ETS`
- Must include characters after the prefix
- Normalized to lowercase for consistent lookup

### Marks
- Must be numeric
- Must be in range 0–100

## Menu options
1. Add student record
2. Update a student's assessment score
3. Generate an individual student report
4. Generate class summary and performance ranking
5. Display all student records
6. Delete a student record
0. Exit

## Important note
Records are stored **in memory only**; exiting clears all data.