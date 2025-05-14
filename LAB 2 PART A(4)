#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// from previous code 
typedef struct {
    char course_code[20];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char the_grade;
    int is_finalized;
} Grade;

typedef struct {
    char reg_number[21];
    char name[51];
    int age;
    Course course;
    Grade grade;
} Student;

typedef struct {
    int size;
    Student students[40];
} StudentList;

// Grade Calculation Function
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

// List Operations
void init_list(StudentList* list) {
    list->size = 0;
}

void add_student(StudentList* list, Student s) {
    if (list->size >= 40) {
        printf("List is full.\n");
        return;
    }
    list->students[list->size++] = s;
}

Student input_student(char* reg_number) {
    Student s;
    strcpy(s.reg_number, reg_number);  // Use the provided reg_number
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter course code: ");
    scanf(" %[^\n]", s.course.course_code);
    printf("Enter course name: ");
    scanf(" %[^\n]", s.course.course_name);
    s.grade.mark = -1;
    s.grade.the_grade = 'N';
    s.grade.is_finalized = 0;
    return s;
}

void assign_mark(StudentList* list, char* reg_number, int mark) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->students[i].reg_number, reg_number) == 0) {
            list->students[i].grade.mark = mark;
            calculate_grade(&list->students[i]);
            printf("Mark assigned for %s. Grade: %c\n", list->students[i].name, list->students[i].grade.the_grade);
            return;
        }
    }
    printf("Student with reg number %s not found.\n", reg_number);
}

void display_students(StudentList* list) {
    for (int i = 0; i < list->size; i++) {
        Student s = list->students[i];
        printf("\nStudent %d:\n", i + 1);
        printf("Reg No: %s\n", s.reg_number);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Course: %s (%s)\n", s.course.course_name, s.course.course_code);
        if (s.grade.is_finalized) {
            printf("Mark: %d, Grade: %c\n", s.grade.mark, s.grade.the_grade);
        } else {
            printf("Grade not assigned yet.\n");
        }
    }
}

// the client code 
int main() {
    StudentList list;
    init_list(&list);

    // Sample Student Registration Numbers
    char* reg_numbers[15] = {
        "S1001", "S1002", "S1003", "S1004", "S1005", "S1006", "S1007", "S1008", 
        "S1009", "S1010", "S1011", "S1012", "S1013", "S1014", "S1015"
    };

    // Creating and adding 15 students to the list
    for (int i = 0; i < 15; i++) {
        Student s = input_student(reg_numbers[i]);
        add_student(&list, s);
    }

    // Assign marks and calculate grade for each student
    for (int i = 0; i < 15; i++) {
        int mark;
        printf("Enter mark for student %s: ", reg_numbers[i]);
        scanf("%d", &mark);
        assign_mark(&list, reg_numbers[i], mark);
    }

    // Display all students with their marks and grades
    printf("\n--- All Students ---\n");
    display_students(&list);

    return 0;
}
