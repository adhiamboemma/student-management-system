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
Emmaculate Adhiambo Ochieng

**Admission Number:**
C026-01-0978/2025

**Class:**
Computer Science 

---

## Program Explanation

### Structures Used

Explain the structures you defined and why you used them.

I used the Student structure to group together all the information 
belonging to one student in a single unit. This includes the student's 
name, admission number, age, marks for 3 subjects, average marks, and grade. 
I used typedef so that I could write "Student" instead of 
"struct Student" every time I needed to create a variable, which made 
the code cleaner and easier to read. Without the struct, I would have 
needed separate arrays for every field, which would have been very 
difficult to manage.

### Functions Used

List and briefly explain each function in your program. Add more functions if you have more,....

addStudent()      - Asks the user to enter a student's details and stores 
                    them in the array. 

displayStudents() - Loops through all stored student records and prints 
                    each one in a clean, readable format including name, 
                    admission number, age, marks, average and grade.

searchStudent()   - Asks the user to enter an admission number, then loops 
                    through the array to find a matching student.

updateStudent()   - Finds a student by their admission number and allows 
                    the user to enter new marks for all 3 subjects.  
                  
deleteStudent()   - Finds a student by admission number and removes them 
                    from the array by shifting all students after them one 
                    position to the left, then decreasing the count by 1. 

bestStudent()     - Loops through all student records using a pointer to 
                    track the student with the highest average. The pointer 
                    moves whenever a student with a higher average is found. 
                    

calculateGrade()  - Takes a student's average mark as input and returns the 
                    correct letter grade using the grading scale: 70-100 = A, 
                    60-69 = B, 50-59 = C, 40-49 = D, below 40 = E.

calculateAverage()- Takes the array of 3 subject marks and returns their 
                    average by adding them together and dividing by 3.0. 
                    Using 3.0 instead of 3 ensures the result is a decimal.

saveToFile()      - Opens students.txt and writes all current student records 
                    to it. It is called automatically after every add, update, 
                    and delete so that data is never lost when the program closes.

loadFromFile()    - Opens students.txt at the start of the program and reads 
                    all previously saved student records back into the array. 

### Pointer Usage

Explain where and why you used pointers in your program.

I used pointers in two places in my program:

1. int *count in addStudent() and deleteStudent()
   These functions need to change the value of count which lives in main(). 
   If I passed count normally, the function would only get a copy and any 
   changes would not affect the original. By passing &count (the address of 
   count) and using int *count in the function, the function can reach back 
   into main and change the real count directly.

2. Student *best in bestStudent()
   I used a pointer to a Student struct to track the best performing student 
   while looping through the array. The pointer starts at &students[0] and 
   moves to &students[i] whenever a student with a higher average is found. 
   At the end of the loop, the pointer is pointing directly at the best 
   student. I used the arrow operator (->) to access that student's fields 
   through the pointer, for example best->name and best->average.

### Challenges Faced

Describe any difficulties you encountered and how you resolved them.

1. Mixing scanf and fgets for input
   When reading names after reading numbers, the leftover newline character 
   from scanf was being picked up by fgets, causing the name to appear empty. 
   I resolved this by adding getchar() before fgets to consume the leftover 
   newline character.

2. Understanding pointers
   I found it difficult at first to understand why addStudent needed int *count 
   while displayStudents only needed int count. After studying the difference 
   between passing by value and passing by address, I understood that functions 
   that only read count just need a copy, but functions that change count need 
   the actual address so they can modify the original variable in main.

3. File handling
   I was unsure how to save and load student records from a file. I learned 
   to use fprintf to write data and fscanf and fgets to read it back. I also 
   learned to always check if fopen returns NULL before using the file, and 
   to always close the file with fclose when done.

4. Removing newlines from fgets
   The fgets function adds a newline character at the end of the string it reads. 
   I resolved this by using strcspn to find where the newline was and replacing 
   it with the null terminator '\0'.

*Good luck — focus on understanding the logic, not just making the program run.*
