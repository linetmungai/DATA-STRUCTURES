#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 40

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
    Student students[MAX_STUDENTS];
} StudentList;

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

void init_list(StudentList* list) {
    list->size = 0;
}

void add_student(StudentList* list, Student s) {
    if (list->size >= MAX_STUDENTS) {
        printf("List is full.\n");
        return;
    }
    list->students[list->size++] = s;
    printf("Student added successfully!\n");
}

void add_student_at(StudentList* list, Student s, int pos) {
    if (list->size >= MAX_STUDENTS || pos < 0 || pos > list->size) {
        printf("Invalid position or list full.\n");
        return;
    }
    for (int i = list->size; i > pos; i--) {
        list->students[i] = list->students[i - 1];
    }
    list->students[pos] = s;
    list->size++;
    printf("Student added at position %d.\n", pos);
}

void remove_student(StudentList* list, char* reg_number) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->students[i].reg_number, reg_number) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->size--;
            printf("Student removed.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void remove_student_at(StudentList* list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < list->size - 1; i++) {
        list->students[i] = list->students[i + 1];
    }
    list->size--;
    printf("Student at position %d removed.\n", pos);
}

int get_size(StudentList* list) {
    return list->size;
}

void destroy_list(StudentList* list) {
    list->size = 0;
    printf("Student list destroyed.\n");
}

Student input_student() {
    Student s;
    printf("Enter reg number: ");
    scanf(" %[^\n]", s.reg_number);
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

void assign_mark(StudentList* list) {
    char reg[21];
    printf("Enter registration number: ");
    scanf(" %[^\n]", reg);

    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->students[i].reg_number, reg) == 0) {
            if (list->students[i].grade.is_finalized) {
                printf("Grade is already finalized.\n");
                return;
            }
            printf("Enter mark (0-100): ");
            int mark;
            scanf("%d", &mark);
            list->students[i].grade.mark = mark;
            calculate_grade(&list->students[i]);
            printf("Mark assigned. Grade: %c\n", list->students[i].grade.the_grade);
            return;
        }
    }
    printf("Student not found.\n");
}

void display_students(StudentList* list) {
    if (list->size == 0) {
        printf("No students to display.\n");
        return;
    }
    for (int i = 0; i < list->size; i++) {
        Student s = list->students[i];
        printf("\nStudent %d:\n", i + 1);
        printf("Reg No: %s\n", s.reg_number);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Course: %s (%s)\n", s.course.course_name, s.course.course_code);
        if (s.grade.is_finalized)
            printf("Mark: %d, Grade: %c\n", s.grade.mark, s.grade.the_grade);
        else
            printf("Grade not assigned yet.\n");
    }
}
int main() {
    StudentList list;
    init_list(&list);

    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Add Student at Position\n");
        printf("3. Remove Student by Reg No\n");
        printf("4. Remove Student at Position\n");
        printf("5. Assign Mark and Calculate Grade\n");
        printf("6. Display All Students\n");
        printf("7. Get List Size\n");
        printf("8. Destroy List\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        Student s;
        int pos;

        switch (choice) {
            case 1:
                s = input_student();
                add_student(&list, s);
                break;
            case 2:
                s = input_student();
                printf("Enter position: ");
                scanf("%d", &pos);
                add_student_at(&list, s, pos);
                break;
            case 3:
                printf("Enter reg number to remove: ");
                char reg[21];
                scanf(" %[^\n]", reg);
                remove_student(&list, reg);
                break;
            case 4:
                printf("Enter position to remove: ");
                scanf("%d", &pos);
                remove_student_at(&list, pos);
                break;
            case 5:
                assign_mark(&list);
                break;
            case 6:
                display_students(&list);
                break;
            case 7:
                printf("List size: %d\n", get_size(&list));
                break;
            case 8:
                destroy_list(&list);
                break;
            case 9:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);

    return 0;
}
