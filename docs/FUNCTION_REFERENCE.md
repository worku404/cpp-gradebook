# Function Reference — Student Gradebook Management System (C++)

## Input helpers
- `clearBadInput()` — clears `cin` error state and discards rest of line.
- `readNum(text)` — reads a numeric value; reprompts until valid.
- `readNumRange(text, min, max)` — reads a number within `[min, max]`.
- `readName(text, out, maxsize)` — reads a non-empty line within buffer limit.
- `readId(text, out, maxsize)` — validates ID starts with ets/ETS, normalizes to lowercase.

## Search
- `findStudentById(ids, id, studentCount)` — returns index or `-1`.

## Calculations
- `sumRow(row, tests)` — sum of marks.
- `minScore(row, tests)` — minimum mark.
- `maxScore(row, tests)` — maximum mark (note: return type is `int` in current code).
- `average(row, tests)` — arithmetic mean.
- `letterGrade(avg)` — converts average to letter grade string.

## Menu actions
- `addStudent(...)` — adds a new student (unique ID + marks).
- `updateMarks(...)` — updates a selected assessment mark.
- `printStudentReport(...)` — prints full report for one student.
- `listStudents(...)` — prints summary table for all students.
- `deleteStudent(...)` — removes a student and shifts arrays.
- `classSummaryAndRanging(...)` — prints class stats and ranking.