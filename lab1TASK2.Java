import java.util.*;

class Course {
    String courseCode;
    String courseName;
}

class Grade {
    int mark = -1;
    char theGrade = 'N';
    boolean isFinalized = false;
}

class Student {
    String regNumber;
    String name;
    int age;
    Course course = new Course();
    Grade grade = new Grade();
}

public class StudentManagement {
    static final int MAX_STUDENTS = 40;
    static Student[] students = new Student[MAX_STUDENTS];
    static int studentCount = 0;
    static Scanner scanner = new Scanner(System.in);

    public static char calculateGrade(int mark) {
        if (mark > 69) return 'A';
        else if (mark > 59) return 'B';
        else if (mark > 49) return 'C';
        else if (mark > 39) return 'D';
        else return 'E';
    }

    public static void addStudent() {
        if (studentCount >= MAX_STUDENTS) {
            System.out.println("Maximum number of students reached.");
            return;
        }

        Student s = new Student();
        System.out.print("Enter reg number: ");
        s.regNumber = scanner.nextLine();

        System.out.print("Enter name: ");
        s.name = scanner.nextLine();

        System.out.print("Enter age: ");
        s.age = Integer.parseInt(scanner.nextLine());

        System.out.print("Enter course code: ");
        s.course.courseCode = scanner.nextLine();

        System.out.print("Enter course name: ");
        s.course.courseName = scanner.nextLine();

        students[studentCount++] = s;
        System.out.println("Student added successfully!");
    }

    public static void editStudent() {
        System.out.print("Enter registration number of the student to edit: ");
        String reg = scanner.nextLine();

        for (int i = 0; i < studentCount; i++) {
            if (students[i].regNumber.equals(reg)) {
                System.out.println("Editing student: " + students[i].name);

                System.out.print("Enter new name: ");
                students[i].name = scanner.nextLine();

                System.out.print("Enter new age: ");
                students[i].age = Integer.parseInt(scanner.nextLine());

                System.out.print("Enter new course code: ");
                students[i].course.courseCode = scanner.nextLine();

                System.out.print("Enter new course name: ");
                students[i].course.courseName = scanner.nextLine();

                System.out.println("Details updated.");
                return;
            }
        }

        System.out.println("Student with reg number " + reg + " not found.");
    }

    public static void assignMark() {
        System.out.print("Enter reg number of the student: ");
        String reg = scanner.nextLine();

        for (int i = 0; i < studentCount; i++) {
            if (students[i].regNumber.equals(reg)) {
                if (students[i].grade.isFinalized) {
                    System.out.println("Grade already finalized and cannot be changed.");
                    return;
                }

                System.out.print("Enter mark (0-100): ");
                int mark = Integer.parseInt(scanner.nextLine());

                if (mark < 0 || mark > 100) {
                    System.out.println("Invalid mark. Must be between 0 and 100.");
                    return;
                }

                students[i].grade.mark = mark;
                students[i].grade.theGrade = calculateGrade(mark);
                students[i].grade.isFinalized = true;

                System.out.println("Mark and grade assigned. Grade: " + students[i].grade.theGrade);
                return;
            }
        }

        System.out.println("Student not found.");
    }

    public static void displayStudents() {
        for (int i = 0; i < studentCount; i++) {
            Student s = students[i];
            System.out.println("\nStudent " + (i + 1));
            System.out.println("Reg No: " + s.regNumber);
            System.out.println("Name: " + s.name);
            System.out.println("Age: " + s.age);
            System.out.println("Course: " + s.course.courseName + " (" + s.course.courseCode + ")");
            if (s.grade.mark != -1) {
                System.out.println("Mark: " + s.grade.mark + ", Grade: " + s.grade.theGrade);
            } else {
                System.out.println("Grade not assigned yet.");
            }
        }
    }

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n--- Student Management System ---");
            System.out.println("1. Add Student");
            System.out.println("2. Edit Student");
            System.out.println("3. Assign Mark & Calculate Grade");
            System.out.println("4. Display Students");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            choice = Integer.parseInt(scanner.nextLine());

            switch (choice) {
                case 1 -> addStudent();
                case 2 -> editStudent();
                case 3 -> assignMark();
                case 4 -> displayStudents();
                case 5 -> System.out.println("Exiting program.");
                default -> System.out.println("Invalid choice.");
            }
        } while (choice != 5);
    }
}
