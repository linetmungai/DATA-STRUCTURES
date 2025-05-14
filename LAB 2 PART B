#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char course_code[20];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char the_grade;
    int is_finalized;
} Grade;

typedef struct student {
    char reg_number[21];
    char name[51];
    int age;
    Course course;
    Grade grade;
    struct student* next; // Pointer to the next student
} Student;

// Function to calculate grade based on marks
void calculate_grade(Student* s) {
    int mark = s->grade.mark;

    if (mark >= 0 && mark <= 100) {
        if (mark > 69) s->grade.the_grade = 'A';
        else if (mark > 59) s->grade.the_grade = 'B';
        else if (mark > 49) s->grade.the_grade = 'C';
        else if (mark > 39) s->grade.the_grade = 'D';
        else s->grade.the_grade = 'E';

        s->grade.is_finalized = 1;
    } else {
        printf("Invalid mark for %s. Grade not assigned.\n", s->reg_number);
    }
}

// Function to create a new student
Student* create_student(char* reg_number) {
    Student* new_student = (Student*)malloc(sizeof(Student));

    // Input student details
    strcpy(new_student->reg_number, reg_number);
    printf("Enter name: ");
    scanf(" %[^\n]", new_student->name);
    printf("Enter age: ");
    scanf("%d", &new_student->age);
    printf("Enter course code: ");
    scanf(" %[^\n]", new_student->course.course_code);
    printf("Enter course name: ");
    scanf(" %[^\n]", new_student->course.course_name);

    new_student->grade.mark = -1;
    new_student->grade.the_grade = 'N';
    new_student->grade.is_finalized = 0;
    new_student->next = NULL; // Initially the next pointer is NULL

    return new_student;
}

// Function to add student to the list
void add_student(Student** head, Student* new_student) {
    if (*head == NULL) {
        *head = new_student; // If the list is empty, new student becomes the head
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = new_student; // Add new student at the end
    }
}

// Function to assign marks to a student
void assign_mark(Student* head, char* reg_number, int mark) {
    Student* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->reg_number, reg_number) == 0) {
            temp->grade.mark = mark;
            calculate_grade(temp);
            printf("Mark assigned for %s. Grade: %c\n", temp->name, temp->grade.the_grade);
            return;
        }
        temp = temp->next;
    }
    printf("Student with reg number %s not found.\n", reg_number);
}

// Function to display all students
void display_students(Student* head) {
    Student* temp = head;

    while (temp != NULL) {
        printf("\nStudent:\n");
        printf("Reg No: %s\n", temp->reg_number);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Course: %s (%s)\n", temp->course.course_name, temp->course.course_code);
        if (temp->grade.is_finalized) {
            printf("Mark: %d, Grade: %c\n", temp->grade.mark, temp->grade.the_grade);
        } else {
            printf("Grade not assigned yet.\n");
        }
        temp = temp->next;
    }
}

// main code
int main() {
    Student* student_list = NULL; // Initially, the list is empty

    // Sample Student Registration Numbers
    char* reg_numbers[15] = {
        "S1001", "S1002", "S1003", "S1004", "S1005", "S1006", "S1007", "S1008",
        "S1009", "S1010", "S1011", "S1012", "S1013", "S1014", "S1015"
    };

    // Creating and adding 15 students to the list
    for (int i = 0; i < 15; i++) {
        Student* s = create_student(reg_numbers[i]);
        add_student(&student_list, s);
    }

    // Assign marks and calculate grade for each student
    for (int i = 0; i < 15; i++) {
        int mark;
        printf("Enter mark for student %s: ", reg_numbers[i]);
        scanf("%d", &mark);
        assign_mark(student_list, reg_numbers[i], mark);
    }

    // Display all students with their marks and grades
    printf("\n--- All Students ---\n");
    display_students(student_list);

    return 0;
}
