# Project Description

## Project Overview
The goal of this project was to build an efficient Course Registration System for the Indian Institute of Technology Madras (IITM) using Object-Oriented Programming (OOP) principles. The system manages student enrollment in various courses, ensures course prerequisites and capacity constraints are respected, and handles potential scheduling conflicts.

The system was designed to handle up to 10,000 operations and needed to maintain efficiency with logarithmic time complexity per operation wherever possible. Each student and course is uniquely identified and stored using custom class structures, with internal validation checks and fast lookups using hash maps or similar data structures.

## Key Functionalities
The key functionalities include:

- **Adding new students with academic history.**
- **Adding courses with defined prerequisites and scheduling time slots.**
- **Enrolling students only if all criteria are met (prerequisites completed, time slots don't clash, seats available, etc.).**
- **Printing the enrolled students in a specific course or handling invalid course queries.**

## Input Format
A. The first line of the input contains an integer Q, which represents the total number of operations to be performed by the system.

B. Each of the next Q operations can be one of the following four types:
-  **Add Student**: When adding a student (add_student), the system expects the student's unique ID, name, and current year of study, followed by the number of courses they have already completed. After this, a space-separated list of course codes is provided, each representing a course the student has previously passed.

- **Add Course**: When adding a course (add_course), the input includes the course's unique code, name, number of credits, maximum capacity, and the designated time slot. This is followed by the number of prerequisite courses required for enrollment. A list of course codes is then provided, representing those prerequisites. If any of the prerequisites do not exist in the system at the time of course addition, the operation is silently rejected.
  
- **Enroll Student in a Course**: For enrollment (enroll), the input consists of a student ID and the course code in which the student wishes to enroll. The system checks whether both the student and course exist, whether the student has completed all the required prerequisites, whether the course has capacity, and whether there are no time slot conflicts with other courses the student is enrolled in.
  
- **Print Course Enrollment**: Finally, the print operation simply takes a course code as input and instructs the system to display the list of students currently enrolled in that course.

## Output Format
A. The system only produces output for print operations.

B. For each print command, the output is as follows:
- **If the course exists in the system**: The output for the print operation begins with a line stating “Enrolled students in <CourseCode>:”, where <CourseCode> is replaced by the actual code of the course being queried. This line serves as a header to indicate which course's enrollment list is being displayed. Following this, the system prints the student IDs of all students who are currently enrolled in that course. Each student ID is printed on a separate line, and the order in which they appear corresponds to the sequence in which the students were enrolled in the course. This ensures that the enrollment list reflects the chronological order of registrations.

- **If the course does not exist in the system**: The output for the print operation consists of a single line that clearly indicates the course is invalid. This line follows the format “Invalid Course <CourseCode>”, where <CourseCode> is replaced by the code of the course that was queried. This message informs the user that the specified course has not been added to the system and therefore cannot have any enrolled students. It provides a clear and concise way to handle invalid or non-existent course queries without disrupting the flow of the program.
