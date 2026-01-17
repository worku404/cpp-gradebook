#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ctype.h>

/*
  Team collaboration plan (tracked via Issues + PRs):

  - wubet:    Input/validation improvements (readNum/readNumRange/readName/readId) + consistent error messages
  - yasmin:   Stats correctness (maxScore return type, tests==0 guards, average/sumRow edge cases)
  - yared:    UI formatting (printStudentReport + listStudents alignment, fixed precision consistency)
  - yonas: CRUD robustness (addStudent/updateMarks/deleteStudent confirmations + clearer prompts)
  - worku:    Summary/ranking (classSummaryAndRanging: cached averages, readable selection sort, correct pass rate)
  d:    UI formatting (printStudentReport + listStudents alignment, fixed precision consistency)
  - yonas: CRUD robustness (addStudent/updateMarks/deleteStudent confirmations + clearer prompts)
  - worku:    Summary/ranking (classSummaryAndRanging: cached averages, readable selection sort, correct pass rate)
  Rule: main must always build; all changes go through PR review.
*/
