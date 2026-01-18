# Test Plan — Student Gradebook Management System (C++)

## Goal
Confirm the application:
- rejects invalid input safely,
- stores records correctly,
- computes accurate reports and rankings,
- maintains consistent state after update/delete.

## Manual test cases

### TC-01: Assessment count validation
**Steps:** start program → enter `0`, `9`, then `4`  
**Expected:** first two rejected; `4` accepted.

### TC-02: Add student (happy path)
**Steps:** Add → ID `ETS1001` → Name `Alice Johnson` → enter valid marks  
**Expected:** “Student added.” Listing shows correct average/grade.

### TC-03: Duplicate ID
**Steps:** Add `ETS1001` then try `ets1001`  
**Expected:** second add rejected as duplicate.

### TC-04: Invalid ID formats
**Steps:** Add → enter `abc123`, then `ets`  
**Expected:** rejected and reprompted.

### TC-05: Out-of-range marks
**Steps:** when asked for mark enter `-1`, `101`, then `75`  
**Expected:** first two rejected; `75` accepted.

### TC-06: Update mark
**Steps:** Update → valid ID → choose assessment `1` → set `100`  
**Expected:** only that mark changes; average updates.

### TC-07: Report missing student
**Steps:** Report → enter `ets9999`  
**Expected:** “Student not found!”

### TC-08: Delete student and verify shift
**Steps:** add A, B, C → delete B → list  
**Expected:** only A and C remain; no blank row.

### TC-09: Class summary + ranking
**Steps:** add 3 students with different averages → run summary  
**Expected:** correct class stats; ranking highest → lowest average.

### TC-10: Exit
**Steps:** choose `0`  
**Expected:** program exits cleanly.