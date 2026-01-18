# Developer Guide — Student Gradebook Management System (C++)

## Function groups
### Input handling
- `clearBadInput()` resets `cin` after invalid input.
- `readNum()` reads a number safely (reprompts).
- `readNumRange()` enforces numeric bounds.
- `readName()` reads a non-empty name into a fixed buffer.
- `readId()` validates ID prefix and normalizes to lowercase.

### Search
- `findStudentById()` performs a linear search and returns index or -1.

### Calculations
- `sumRow()`, `minScore()`, `maxScore()`, `average()`, `letterGrade()`

### Features (menu actions)
- `addStudent()`, `updateMarks()`, `printStudentReport()`, `listStudents()`,
  `classSummaryAndRanging()`, `deleteStudent()`

## Ranking implementation
Ranking is produced by sorting an `order[]` array of indices (selection sort) by average descending. Student records are not physically moved.

## Known improvement opportunities
- `maxScore()` returns `int` while marks are `double`; return type should be `double`.
- Replace parallel arrays with `struct Student` + `std::vector<Student>` as a refactor step.
- Add unit tests for validation and calculations.