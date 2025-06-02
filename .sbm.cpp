#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    int age;
    char course[50];
};

struct Student students[MAX] = {
    {101, "Nanditha",19, "B.Tech"},
    {102, "Mubeen", 18, "B.Tech"},
    {103, "Charlie", 22, "B. "},
    {104, "David", 20, "BA"},
    {105, "Eva", 19, "BBA"},
    {106, "Frank", 23, "BCA"},
    {107, "Grace", 20, "B.Sc"},
    {108, "Hannah", 21, "B.Tech"},
    {109, "Ian", 22, "B.Com"},
    {110, "Julia", 20, "BA"}
};

int count = 10;  

void displayAll() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n=== List of Students ===\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d, Name: %s, Age: %d, Course: %s\n",
               students[i].rollNo, students[i].name, students[i].age, students[i].course);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Student found:\n");
            printf("Roll No: %d, Name: %s, Age: %d, Course: %s\n",
                   students[i].rollNo, students[i].name, students[i].age, students[i].course);
            return;
        }
    }
    printf("Student not found.\n");
}
void deleteStudent() {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Enter new name: ");
            getchar(); // Clear newline
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline

            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            getchar();

            printf("Enter new course: ");
            fgets(students[i].course, sizeof(students[i].course), stdin);
            students[i].course[strcspn(students[i].course, "\n")] = '\0';

            printf("Student updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n==== Student Management System ====\n");
        printf("1. Display All Students\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayAll(); break;
            case 2: searchStudent(); break;
            case 3: deleteStudent(); break;
            case 4: updateStudent(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);
    
    return 0;
}
