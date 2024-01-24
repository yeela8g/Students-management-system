# Student Management System

## Project Overview

This C++ project implements a Student Management System, allowing users to manage students details, courses, and perform various operations related to student data.

This student management project reflects work with:
- structs
- pointers
- files
- input validation
- binary search
- structured data
- employing dinamic allocation
- incorporating principles such as separating implementation from declaration, as well as modular design.

## The structure of the system
main students management struct containing students counter and a pointer to a dynamic array that points to the students and their courses. First, the data is built according to 2 files - "courses info" and "students info". Students are entered in ascending order of their ID. Each student contains a name, an ID, a number of courses and a pointer to an array of courses, where a course contains a course number and the grade of the student in it. After the data structure of the system is ready, the menu will be printed and the user will be asked to choose an action from the following - add/delete a student, add a new course for a student, print a student/all, print an average of a student/all, reset the system or exit.

Illustrative scheme:

![image](https://github.com/yeela8g/Students-management-system/assets/118124478/36241cc9-b643-4683-8548-e48583a9107a)


![image](https://github.com/yeela8g/Students-management-system/assets/118124478/cd329f7a-97d6-47be-a2fc-7072df2706f6)

menu is presented, choose the required operation:

![image](https://github.com/yeela8g/Students-management-system/assets/118124478/abf75c52-f931-4659-b9dc-6f20a8894a32)

> and repeat!


## Code Writing Principles

- **Modularity**: Code is organized into modular functions handling specific tasks.
- **Dynamic Memory Allocation**: Utilizes dynamic memory for managing arrays of students and their courses.
- **Binary Search**: Includes a binary search function for efficient student lookup based on ID.
- **Input Validation**: Ensures user input in the menu is within valid range.
- **File Handling**: Reads initial student and course data from text files with error handling.
- **Structured Data**: Uses structs to convenient use of data organization.
- **Pointer Arithmetic**: Employed for managing dynamic memory efficiently.

  
## Files

  1. **main.cpp**: Main program file initializing the student manager and calling the menu function.
  2. **Student_info.txt**: Text file containing initial student information (IDs and names).
  3. **Course_info.txt**: Text file containing initial course information (student IDs, course numbers, and grades).
  4. **students_dec.h**: Header file with declarations of structs, constants, and function prototypes.
  5. **students_imp.cpp**: Implementation file with code for functions declared in students_dec.h.
  6. **students_mng.cpp**: Implementation file containing the menu function and supporting functions


## How to Run

1. Compile the code using a C++ compiler.
2. Ensure `Student_info.txt` and `Course_info.txt` are present in the project directory.
3. Run the compiled executable.
4. Follow the on-screen menu to perform various operations on student data.

### hope the system will be useful and helpful!
