# Vision — Student Gradebook Management System (C++)

## 1. Product Vision (Why This Exists)

The **Student Gradebook Management System** is a simple, reliable, console-based application designed to manage a small class roster, record assessment scores, and generate both individual student reports and class-level summaries.

From **Group S’s** perspective, the project is not only about managing grades. It is an intentionally scoped **CRUD + reporting** system that emphasizes **data integrity**, **input validation**, **consistent identifiers**, and **predictable output generation**. These concerns closely mirror those found in real-world administrative tools, internal dashboards, and back-office software commonly built by software engineering teams.

---

## 2. Problem Statement

In many small academic or tutoring environments, grade tracking is handled manually using paper records, spreadsheets, or informal notes. These approaches often lead to:

- inconsistent student identifiers and naming conventions,
- accidental overwrites or lost data,
- time-consuming manual reporting,
- difficulty producing accurate summaries or rankings.

This project addresses these issues by providing a structured, validated workflow for entering, updating, and reporting student performance data with consistent rules and clear output.

---

## 3. Target Users & Stakeholders

### Primary User
- **Instructor / Teaching Assistant (TA)**  
  Responsible for maintaining the student roster, entering grades, and generating reports.

### Secondary Stakeholders
- **Students (indirect)**  
  Benefit from accurate and consistent grade reporting.

- **Academic programs or institutions (indirect)**  
  Expect standardized and reliable grading practices.

---

## 4. Goals (What Success Looks Like)

- **Accurate record management**  
  Enable safe creation, update, listing, and deletion of student records without data corruption.

- **Consistent student reporting**  
  Generate clear individual reports including totals, minimum, maximum, average, letter grade, and pass/fail status.

- **Class-level insight**  
  Compute class-wide statistics such as average score, pass rate, best and worst averages, and a performance ranking.

- **Robust input handling**  
  Prevent invalid numeric input, out-of-range marks, and malformed identifiers from entering the system.

- **Predictable constraints**  
  Operate within clearly defined limits (maximum number of students and assessments) to ensure correctness and simplicity.

---

## 5. Non-Goals (Explicitly Out of Scope)

The following are intentionally excluded from the current version:

- Persistent storage (no file or database saving/loading)
- Authentication, authorization, or privacy controls
- Graphical or web-based user interfaces
- Advanced grading policies (weighting, curves, drops, penalties)
- Concurrent or multi-user access

These features are valid future extensions but are not required for the current educational and architectural scope.

---

## 6. Scope Definition

### In Scope

**Menu-driven operations:**
- Add a student record
- Update an assessment score
- Generate an individual student report
- Generate a class summary and performance ranking
- List all student records
- Delete a student record

**Validation rules:**
- Assessment marks must be in the range **0–100**
- Number of assessments must be **1–8**
- Student IDs must start with **ets/ETS** and are normalized to lowercase for consistent lookup

**Sorting:**
- Performance ranking ordered by **average score (descending)**

### Out of Scope
- File import/export (CSV, JSON, etc.)
- Tie-breaking policies beyond simple ordering
- Weighted or configurable grading schemes

---

## 7. Key Use Cases (User-Oriented View)

- As an instructor, I can define the number of assessments for the course.
- As an instructor, I can add a student with a valid ID, name, and assessment scores.
- As an instructor, I can update a specific assessment score for an existing student.
- As an instructor, I can retrieve a detailed report for a student using their ID.
- As an instructor, I can view a class summary and ranking to assess overall performance.
- As an instructor, I can list all students with their averages and letter grades.
- As an instructor, I can delete a student record while maintaining internal consistency.

---

## 8. Quality Attributes (Beyond Features)

- **Correctness**  
  All calculations (sum, minimum, maximum, average, grading) must be accurate.

- **Input robustness**  
  The system must handle invalid input gracefully and recover without crashing.

- **Console usability**  
  Prompts should be clear, and output should be readable and well formatted.

- **Maintainability**  
  Code structure should favor small, well-defined functions (validation, reporting, CRUD).

- **Performance**  
  Performance requirements are minimal at this scale; clarity and correctness take priority.

---

## 9. Constraints & Assumptions

### Constraints
- Maximum of **50 students**
- Maximum of **8 assessments per student**
- Fixed-size, in-memory storage using C-style arrays
- Console-based execution environment (typical coursework setup)

### Assumptions
- All assessment marks use the same numeric scale (**0–100**).
- The number of assessments is fixed for the duration of a program run.
- Student ID uniqueness is enforced at the time of insertion.

---

## 10. Risks & Mitigation Strategies

- **Risk: Data loss on program exit**  
  **Mitigation:** clearly communicate in-memory-only behavior; future enhancement includes persistence.

- **Risk: Limited scalability due to fixed-size arrays**  
  **Mitigation:** acceptable for current scope; future refactor to `struct` + `std::vector`.

- **Risk: Edge-case input errors**  
  **Mitigation:** defensive input validation and recovery loops.

---

## 11. Success Criteria

The system is considered successful if an instructor can:

- Add at least one student,
- Update assessment scores,
- Generate individual and class-level reports,
- List and delete student records,

all without crashes, inconsistent state, or incorrect calculations, while invalid inputs are rejected with clear feedback.

---

## 12. Future Direction

Potential evolution paths include:

- Persistent storage (CSV or JSON)
- Structured data models (`struct` or class-based design)
- Automated testing for grading and validation logic
- Configurable grading policies
- Interface upgrades (GUI or API-based)

These extensions reflect common transitions from prototype systems to maintainable software products.