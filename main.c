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

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
char calculateGrade(float avg);

int main()
{
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

    } while (choice != 5);

    return 0;
}