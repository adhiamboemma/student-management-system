#include <stdio.h>
#include <string.h>

/* ─────────────────────────────────────────
   STRUCT DEFINITION
   A Student holds all information for one
   student record in the system.
───────────────────────────────────────── */
typedef struct
{
    char name[50];       
    int admissionNo;   
    int age;             
    float marks[3];      
    float average;       
    char grade;          
} Student;

/* ─────────────────────────────────────────
   FUNCTION PROTOTYPES
   These announce all functions to the
   compiler before they are defined below.
───────────────────────────────────────── */
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void bestStudent(Student students[], int count);
char calculateGrade(float avg);
float calculateAverage(float marks[]);


/* ─────────────────────────────────────────
   calculateGrade()
   Takes an average mark and returns the
   corresponding letter grade.
   Uses the grading scale:
     70-100 = A, 60-69 = B, 50-59 = C,
     40-49 = D, below 40 = E
───────────────────────────────────────── */
char calculateGrade(float avg) {
    if (avg >= 70) return 'A';
    else if (avg >= 60) return 'B';
    else if (avg >= 50) return 'C';
    else if (avg >= 40) return 'D';
    else return 'E';
}

/* ─────────────────────────────────────────
   calculateAverage()
   Takes an array of 3 marks and returns
   their average as a float.
   Divides by 3.0 to ensure decimal result.
───────────────────────────────────────── */
float calculateAverage(float marks[]) {
    return (marks[0] + marks[1] + marks[2]) / 3.0;
}

/* ─────────────────────────────────────────
   addStudent()
   Asks the user to enter student details,
   stores them in the array, automatically
   calculates average and grade, then
   increases the student count by 1.
───────────────────────────────────────── */
void addStudent(Student students[], int *count) {

    /* check if the array is already full */
    if (*count >= 100) {
        printf("System is full. Cannot add more students.\n");
        return;
    }

    /* consume leftover newline from previous scanf */
    getchar();

    printf("Enter name: ");
    fgets(students[*count].name, 50, stdin);

    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    
    printf("Enter admission number: ");
    scanf("%d", &students[*count].admissionNo);

    
    printf("Enter age: ");
    scanf("%d", &students[*count].age);


    printf("Enter mark for subject 1: ");
    scanf("%f", &students[*count].marks[0]);

    printf("Enter mark for subject 2: ");
    scanf("%f", &students[*count].marks[1]);

    printf("Enter mark for subject 3: ");
    scanf("%f", &students[*count].marks[2]);

    students[*count].average = calculateAverage(students[*count].marks);
    students[*count].grade = calculateGrade(students[*count].average);

    
    (*count)++;

    printf("Student added successfully!\n");
}

/* ─────────────────────────────────────────
   displayStudents()
   Loops through all student records and
   prints each one in a readable format.
───────────────────────────────────────── */
void displayStudents(Student students[], int count) {

    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== ALL STUDENT RECORDS =====\n");

    /* loop through every student from index 0 to count-1 */
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Admission Number: %d\n", students[i].admissionNo);
        printf("Age: %d\n", students[i].age);
        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
        printf("---------------------------\n");
    }
}

/* ─────────────────────────────────────────
   searchStudent()
   Asks user for an admission number, loops
   through all students to find a match,
   prints details if found.
───────────────────────────────────────── */
void searchStudent(Student students[], int count) {

    
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    
    int searchNo;
    printf("\nEnter admission number to search: ");
    scanf("%d", &searchNo);
    int found = 0;

    /* loop through all students comparing admission numbers */
    for (int i = 0; i < count; i++) {
        if (students[i].admissionNo == searchNo) {
            /* match found — print details */
            printf("\n===== STUDENT FOUND =====\n");
            printf("Name: %s\n", students[i].name);
            printf("Admission Number: %d\n", students[i].admissionNo);
            printf("Age: %d\n", students[i].age);
            printf("Average: %.2f\n", students[i].average);
            printf("Grade: %c\n", students[i].grade);
            found = 1;  /* mark as found */
            break;      /* stop searching, no need to continue */
        }
    }

    /* after loop — if flag is still 0, nobody matched */
    if (found == 0) {
        printf("\nStudent with admission number %d not found.\n", searchNo);
    }
}

/* ─────────────────────────────────────────
   updateStudent()
   Finds a student by admission number,
   asks for new marks, then automatically
   recalculates their average and grade.
───────────────────────────────────────── */
void updateStudent(Student students[], int count) {

    /* nothing to update if no students exist */
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    /* ask which student to update */
    int searchNo;
    printf("\nEnter admission number to update: ");
    scanf("%d", &searchNo);

    /* flag starts at 0 (not found) */
    int found = 0;

    /* search for the student */
    for (int i = 0; i < count; i++) {
        if (students[i].admissionNo == searchNo) {

            /* found — ask for new marks */
            printf("Enter new mark for subject 1: ");
            scanf("%f", &students[i].marks[0]);

            printf("Enter new mark for subject 2: ");
            scanf("%f", &students[i].marks[1]);

            printf("Enter new mark for subject 3: ");
            scanf("%f", &students[i].marks[2]);

            /* recalculate average and grade automatically */
            students[i].average = calculateAverage(students[i].marks);
            students[i].grade = calculateGrade(students[i].average);

            printf("\nStudent updated successfully!\n");
            printf("New Average: %.2f\n", students[i].average);
            printf("New Grade: %c\n", students[i].grade);

            found = 1;
            break;
        }
    }

    /* after loop — nobody matched */
    if (found == 0) {
        printf("\nStudent with admission number %d not found.\n", searchNo);
    }
}

/* ─────────────────────────────────────────
   deleteStudent()
   Finds a student by admission number and
   removes them from the array by shifting
   all students after them one position
   to the left, then decreasing count by 1.
───────────────────────────────────────── */
void deleteStudent(Student students[], int *count) {

    /* nothing to delete if no students exist */
    if (*count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    /* ask which student to delete */
    int searchNo;
    printf("\nEnter admission number to delete: ");
    scanf("%d", &searchNo);

    /* flag starts at 0 (not found) */
    int found = 0;

    /* search for the student */
    for (int i = 0; i < *count; i++) {
        if (students[i].admissionNo == searchNo) {

            /* found — shift every student after this one left by 1 */
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            /* decrease count — one fewer student now */
            (*count)--;

            printf("\nStudent deleted successfully.\n");
            found = 1;
            break;
        }
    }

    /* after loop — nobody matched */
    if (found == 0) {
        printf("\nStudent with admission number %d not found.\n", searchNo);
    }
}

/* ─────────────────────────────────────────
   bestStudent()
   Uses a pointer to track the best student
   as it loops through the array.
   The pointer starts at students[0] and
   moves whenever a higher average is found.
   ──────────── */
void bestStudent(Student students[], int count) {

    /* nothing to check if no students exist */
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    /* pointer starts pointing at the first student */
    Student *best = &students[0];

    /* loop from second student onwards */
    for (int i = 1; i < count; i++) {
        /* compare current student's average to whoever best points at */
        if (students[i].average > best->average) {
            /* this student is better — move pointer to them */
            best = &students[i];
        }
    }

    /* best now points at the top student — print using arrow operator */
    printf("\n===== BEST PERFORMING STUDENT =====\n");
    printf("Name: %s\n", best->name);
    printf("Admission Number: %d\n", best->admissionNo);
    printf("Age: %d\n", best->age);
    printf("Average: %.2f\n", best->average);
    printf("Grade: %c\n", best->grade);
}

/* ─────────────────────────────────────────
   main()
   Entry point of the program.
───────────────────────────────────────── */
int main()
{
    Student students[100];  
    int count = 0;          
    int choice;             

    do
    {
        
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Best Performing Student\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        
        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: updateStudent(students, count); break;
            case 5: deleteStudent(students, &count); break;
            case 6: bestStudent(students, count); break;
            case 7: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}