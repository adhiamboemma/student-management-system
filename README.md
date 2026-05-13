[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/AKaeQwHN)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=23906928&assignment_repo_type=AssignmentRepo)
# Student Management System

## Overview

In this assignment, you are required to build a menu-driven Student Management System using the C programming language.

The purpose of this project is to help you practice and demonstrate your understanding of the things we have learnt through out our lab sessions.



## Project Requirements

Your program should manage student records. Each student record must contain:

- Name
- Admission Number
- Age
- Marks for 3 subjects
- Average Marks
- Grade


## Required Functionalities

Your program must include the following features:

### 1. Add Student

Allow the user to input student details. The program should:

- Store the student record
- Calculate the average marks automatically
- Determine the grade automatically

### 2. Display All Students

Display all student records in a clean and readable format.

Example output:

```text
Name: Alice
Admission Number: 1023
Age: 19
Average: 67.33
Grade: B
```

### 3. Search Student

Allow the user to search for a student using their admission number.

### 4. Update Student

Allow the user to:

- Update student marks
- Recalculate the average
- Recalculate the grade

### 5. Best Performing Student

Display the student with the highest average marks.



## Technical Requirements

Your program **must**:

- Use at least one `struct`
- Use an array of structs
- Use functions
- Use at least one pointer with a structure
- Use meaningful variable names
- Be menu-driven
- Compile successfully without errors or warnings



## Grade Calculation

Use the following grading system:

| Average Marks | Grade |
| ------------- | ----- |
| 70 – 100      | A     |
| 60 – 69       | B     |
| 50 – 59       | C     |
| 40 – 49       | D     |
| Below 40      | E     |



## File Structure

Your repository must contain:

```text
.
├── main.c
└── README.md
```


## Git Requirements

You are required to:

- Push your work to GitHub
- Make regular, incremental commits as you build each feature
- Use meaningful commit messages

Example commit messages:

```bash
git commit -m "Add student struct definition"
git commit -m "Implement add student functionality"
git commit -m "Add grade calculation logic"
git commit -m "Fix search function bug"
```


## Submission Rules

- Late submissions will not be accepted
- Your code must be your own work — copying from your colleagues is prohibited
- You must be able to explain your code, use comments where appropriate



## Bonus Features (Optional)

You may earn bonus points for implementing any of the following:

- File handling (save/load records from a file)
- Delete student functionality
- Sort students by average marks
- Improved menu and output formatting
- Input validation
- Nested structures


<!-- Edit the section below -->
## Student Submission Section

> **Instructions:** Fill in all sections below before submitting. Incomplete README sections may affect your marks.

---

## Student Information

**Full Name:**
Write your full name here.

**Admission Number:**
Write your admission number here.

**Class:**
Computer Science / Maths and Modelling

---

## Program Explanation

### Structures Used

Explain the structures you defined and why you used them.

```text
Example:
I used the ------- structure to ------
```

---

### Functions Used

List and briefly explain each function in your program. Add more functions if you have more,....

```text
Example:
addStudent()      - 
displayStudents() - 
searchStudent()   - 
updateStudent()   - 
bestStudent()     - 
calculateGrade()  - 
```

---

### Pointer Usage

Explain where and why you used pointers in your program.

```text
Example:
I used a pointer to ----
```

---

### Challenges Faced

Describe any difficulties you encountered and how you resolved them.

```text
Write your answer here.
```

*Good luck — focus on understanding the logic, not just making the program run.*
