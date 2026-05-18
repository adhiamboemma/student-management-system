#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int admissionNo;
    int age;
    float marks[3];
    float average;
    char grade;
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void updateStudent(Student students[], int count);
void bestStudent(Student students[], int count);
char calculateGrade(float avg);
float calculateAverage(float marks[]);

char calculateGrade(float avg) {
    if (avg >= 70) return 'A';
    else if (avg >= 60) return 'B';
    else if (avg >= 50) return 'C';
    else if (avg >= 40) return 'D';
    else return 'E';
}

float calculateAverage(float marks[]) {
    return (marks[0] + marks[1] + marks[2]) / 3.0;
}

void addStudent(Student students[], int *count) {
    
    if (*count >= 100) {
        printf("System is full. Cannot add more students.\n");
        return;
    }


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
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: updateStudent(students, count); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}