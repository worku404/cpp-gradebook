# Requirements — Student Gradebook Management System (C++)

## 1. Purpose
Define the functional and non-functional requirements for a console-based system that manages student grade records (IDs, names, and assessment marks) and generates student and class reports.

---

## 2. Scope
### In Scope
- Create, read, update, and delete (CRUD) student records in memory.
- Generate formatted reports:
  - Individual student report
  - Class summary + performance ranking
  - List of all students with averages/grades
- Input validation for IDs, names, numeric values, and ranges.

### Out of Scope
- File/database persistence (save/load).
- Authentication/authorization.
- GUI/web UI.
- Weighted grading, curves, drops, penalties.
- Concurrent access / multi-user support.

---

## 3. Definitions
- **Student record**: `{ id, name, marks[assessmentCount] }`
- **Assessment**: one score in range 0–100.
- **Average**: arithmetic mean of a student’s assessment scores.
- **Pass**: average ≥ 50; otherwise Fail.

---

## 4. Constraints
- Maximum students: **50**
- Maximum assessments per student: **8**
- Student ID storage length: **10 characters max** (+ null terminator)
- Student name storage length: **31 characters max** (+ null terminator)
- Console-based execution on Windows.

---

## 5. Assumptions
- All assessment marks use a 0–100 scale.
- The number of assessments is configured once at program start and remains constant for the session.
- Student IDs are unique.

---

## 6. Functional Requirements (FR)

### FR-1 — Configure Assessment Count
- The system **shall** prompt the user to enter the number of assessments per student.
- The system **shall** accept values only in the range **[1, 8]**.

**Acceptance Criteria**
- If the user enters a value outside [1, 8] or non-numeric input, the system reprompts until valid.

---

### FR-2 — Add Student Record
- The system **shall** allow adding a new student record containing:
  - Student ID
  - Student name
  - Marks for each assessment (count = configured assessment count)
- The system **shall** reject adding a student when capacity (**50 students**) is reached.

**Acceptance Criteria**
- Given a non-full class, when a new unique ID and valid name/marks are provided, studentCount increases by 1 and the record appears in list output.
- Given a full class, adding is refused with a message and studentCount does not change.

---

### FR-3 — Validate and Normalize Student ID
- The system **shall** require a student ID to start with `ets` or `ETS`.
- The system **shall** require the ID to contain additional characters beyond the prefix.
- The system **shall** normalize the stored/used ID to **lowercase** for consistent lookup.

**Acceptance Criteria**
- IDs not starting with ets/ETS are rejected and reprompted.
- IDs with only `ets` (length ≤ 3) are rejected and reprompted.
- Lookups succeed regardless of whether the user enters `ETS...` or `ets...`.

---

### FR-4 — Prevent Duplicate Student IDs
- The system **shall** prevent adding a new student whose ID already exists.

**Acceptance Criteria**
- Attempting to add an existing ID fails with a message and does not modify existing records.

---

### FR-5 — Capture Valid Student Name
- The system **shall** accept a non-empty student name up to the maximum supported length.

**Acceptance Criteria**
- If the name input exceeds the maximum length, the system reprompts.
- If the name is empty, the system reprompts.

---

### FR-6 — Enter Marks with Range Checking
- The system **shall** require each assessment mark to be numeric and within **[0, 100]**.

**Acceptance Criteria**
- Non-numeric or out-of-range values are rejected and reprompted until valid.

---

### FR-7 — Update a Student’s Assessment Score
- The system **shall** allow updating exactly one assessment score for an existing student.
- The system **shall** prompt the user to select which assessment (1..assessmentCount).
- The system **shall** apply the same mark validation as FR-6.

**Acceptance Criteria**
- Given a valid student ID, selecting an assessment number in range and a valid new mark updates only that mark.
- Given an invalid ID, no marks change and the system reports “Student not found”.

---

### FR-8 — Generate Individual Student Report
- The system **shall** generate a report for a selected student by ID including:
  - ID, name
  - All marks
  - Total, minimum, maximum, average
  - Letter grade
  - Pass/Fail status

**Acceptance Criteria**
- For an existing student, the displayed totals and averages match the marks entered.
- For a non-existing student, the system prints “Student not found” and returns to menu.

---

### FR-9 — List All Students
- The system **shall** display a list of all students showing at least:
  - ID, name, average, letter grade

**Acceptance Criteria**
- When there are no students, the system prints “No students yet.”
- When students exist, the list includes one row per student.

---

### FR-10 — Delete Student Record
- The system **shall** delete a student record by ID.
- The system **shall** maintain contiguous storage (shift remaining records to fill the gap).
- The system **shall** decrease studentCount by 1 when deletion succeeds.

**Acceptance Criteria**
- Deleting an existing student removes them from list output and reduces studentCount by 1.
- Deleting a non-existing student does not change studentCount and reports “Student not found”.

---

### FR-11 — Class Summary
- The system **shall** compute and display:
  - number of students
  - class average (mean of student averages)
  - highest student average
  - lowest student average
  - pass rate (percentage with average ≥ 50)

**Acceptance Criteria**
- With at least 1 student, all values are computed and displayed.
- With 0 students, the system displays “No Students yet.”

---

### FR-12 — Performance Ranking
- The system **shall** produce a ranking of students ordered by average score (highest to lowest).

**Acceptance Criteria**
- Ranking order is strictly non-increasing by average.
- Each student appears exactly once in the ranking.

---

### FR-13 — Menu Navigation and Exit
- The system **shall** present a menu of operations continuously until the user chooses Exit.
- The system **shall** exit cleanly when the user selects `0`.

**Acceptance Criteria**
- Selecting `0` terminates the program without crashing.

---

## 7. Non-Functional Requirements (NFR)

### NFR-1 — Reliability / Robust Input Handling
- The system **shall** recover from invalid console input (non-numeric where numeric expected, overly long text input) by reprompting without terminating.

### NFR-2 — Correctness
- All calculations (sum, min, max, average, grade mapping, pass/fail, pass rate) **shall** be mathematically correct for the stored marks.

### NFR-3 — Usability (Console)
- Prompts **shall** be clear and outputs **shall** be readable (aligned tables where applicable).

### NFR-4 — Performance
- The system **should** respond instantly for the maximum dataset (50 students × 8 assessments). (Any O(n²) sorting at this size is acceptable.)

### NFR-5 — Maintainability
- The program **should** keep logic separated into small functions for validation, search, calculations, and reporting.

---

## 8. Traceability (Vision Alignment)
- CRUD + reporting focus: FR-2, FR-7, FR-8, FR-9, FR-10, FR-11, FR-12
- Data integrity & validation: FR-3, FR-4, FR-5, FR-6, NFR-1, NFR-2
- Predictable constraints: Section 4 (Constraints)

---