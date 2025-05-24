class Course {
    private String courseCode;
    private String courseName;

    public Course(String courseCode, String courseName) {
        this.courseCode = courseCode;
        this.courseName = courseName;
    }

    public String getCourseCode() {
        return courseCode;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseCode(String code) {
        this.courseCode = code;
    }

    public void setCourseName(String name) {
        this.courseName = name;
    }
}

class Grade {
    private int mark;
    private char theGrade;
    private boolean isFinalized;

    public Grade() {
        this.mark = -1;
        this.theGrade = 'N';
        this.isFinalized = false;
    }

    public void setMark(int mark) {
        this.mark = mark;
        finalizeGrade();
    }

    private void finalizeGrade() {
        if (mark >= 70) theGrade = 'A';
        else if (mark >= 60) theGrade = 'B';
        else if (mark >= 50) theGrade = 'C';
        else if (mark >= 40) theGrade = 'D';
        else theGrade = 'E';
        isFinalized = true;
    }

    public int getMark() {
        return mark;
    }

    public char getTheGrade() {
        return theGrade;
    }

    public boolean isFinalized() {
        return isFinalized;
    }
}

class Student {
    private String regNumber;
    private String name;
    private int age;
    private Course course;
    private Grade grade;

    public Student(String regNumber, String name, int age, Course course) {
        this.regNumber = regNumber;
        this.name = name;
        this.age = age;
        this.course = course;
        this.grade = new Grade();
    }

    public String getRegNumber() {
        return regNumber;
    }

    public void setRegNumber(String regNumber) {
        this.regNumber = regNumber;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Course getCourse() {
        return course;
    }

    public void setCourse(Course course) {
        this.course = course;
    }

    public Grade getGrade() {
        return grade;
    }

    public void setGrade(Grade grade) {
        this.grade = grade;
    }

    public void assignMark(int mark) {
        this.grade.setMark(mark);
    }
}

// Linked List Node
class StudentNode {
    Student student;
    StudentNode next;

    public StudentNode(Student student) {
        this.student = student;
        this.next = null;
    }
}

// Linked List ADT
class StudentList {
    private StudentNode head;

    public void addStudent(Student student) {
        StudentNode newNode = new StudentNode(student);
        if (head == null) {
            head = newNode;
        } else {
            StudentNode temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    public Student findStudentByRegNo(String regNumber) {
        StudentNode current = head;
        while (current != null) {
            if (current.student.getRegNumber().equalsIgnoreCase(regNumber)) {
                return current.student;
            }
            current = current.next;
        }
        return null;
    }

    public void displayAllStudents() {
        StudentNode current = head;
        while (current != null) {
            Student s = current.student;
            System.out.println("Reg No: " + s.getRegNumber());
            System.out.println("Name: " + s.getName());
            System.out.println("Age: " + s.getAge());
            System.out.println("Course: " + s.getCourse().getCourseName() + " (" + s.getCourse().getCourseCode() + ")");
            if (s.getGrade().isFinalized()) {
                System.out.println("Mark: " + s.getGrade().getMark() + ", Grade: " + s.getGrade().getTheGrade());
            } else {
                System.out.println("Grade not assigned.");
            }
            System.out.println("-----------------------------");
            current = current.next;
        }
    }
}

// Main code
public class StudentManagementSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StudentList list = new StudentList();

        // Add 15 students
        for (int i = 1; i <= 15; i++) {
            System.out.println("Enter details for student " + i);
            System.out.print("Reg No: ");
            String regNo = scanner.nextLine();
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Age: ");
            int age = Integer.parseInt(scanner.nextLine());
            System.out.print("Course Code: ");
            String code = scanner.nextLine();
            System.out.print("Course Name: ");
            String cname = scanner.nextLine();

            Course course = new Course(code, cname);
            Student student = new Student(regNo, name, age, course);
            list.addStudent(student);
        }

        // Assign marks
        for (int i = 1; i <= 15; i++) {
            System.out.print("Enter Reg No to assign mark: ");
            String reg = scanner.nextLine();
            Student s = list.findStudentByRegNo(reg);
            if (s != null) {
                System.out.print("Enter mark for " + s.getName() + ": ");
                int mark = Integer.parseInt(scanner.nextLine());
                s.assignMark(mark);
            } else {
                System.out.println("Student not found.");
            }
        }

        // Display all students
        System.out.println("\n--- All Students ---");
        list.displayAllStudents();

        scanner.close();
    }
}
