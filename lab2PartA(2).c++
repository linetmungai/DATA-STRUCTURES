#include <iostream>
#include <string>
using namespace std;

#define MAX_STUDENTS 100

class Course {
private:
    string course_code;
    string course_name;

public:
    Course() : course_code(""), course_name("") {}
    Course(string code, string name) : course_code(code), course_name(name) {}

    void set_course_code(string code) { course_code = code; }
    void set_course_name(string name) { course_name = name; }

    string get_course_code() const { return course_code; }
    string get_course_name() const { return course_name; }
};

class Grade {
private:
    int mark;
    char the_grade;
    bool is_finalized;

public:
    Grade() : mark(-1), the_grade('N'), is_finalized(false) {}

    void set_mark(int m) {
        if (m >= 0 && m <= 100) {
            mark = m;
            the_grade = calculate_grade(m);
            is_finalized = true;
        }
    }

    int get_mark() const { return mark; }
    char get_the_grade() const { return the_grade; }
    bool get_is_finalized() const { return is_finalized; }

    static char calculate_grade(int m) {
        if (m > 69) return 'A';
        else if (m > 59) return 'B';
        else if (m > 49) return 'C';
        else if (m > 39) return 'D';
        else return 'E';
    }
};
class Student {
private:
    string regNumber;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    Student() : regNumber(""), name(""), age(0) {}
    Student(string regNo, string name, int age, Course c)
        : regNumber(regNo), name(name), age(age), course(c) {}

    void set_regNo(string reg) { regNumber = reg; }
    string get_regNo() const { return regNumber; }

    void set_name(string n) { name = n; }
    string get_name() const { return name; }

    void set_age(int a) { age = a; }
    int get_age() const { return age; }

    void set_course(const Course& c) { course = c; }
    Course get_course() const { return course; }

    void set_grade(const Grade& g) { grade = g; }
    Grade get_grade() const { return grade; }

    void set_marks(int m) { grade.set_mark(m); }
    int get_marks() const { return grade.get_mark(); }

    void display() const {
        cout << "Reg No: " << regNumber << ", Name: " << name << ", Age: " << age << endl;
        cout << "Course: " << course.get_course_name() << " (" << course.get_course_code() << ")" << endl;
        if (grade.get_mark() != -1) {
            cout << "Mark: " << grade.get_mark() << ", Grade: " << grade.get_the_grade() << endl;
        } else {
            cout << "Grade not assigned." << endl;
        }
    }

    bool equals(const Student& other) const {
        return regNumber == other.regNumber;
    }
};
class List {
private:
    Student students[MAX_STUDENTS];
    int size;

public:
    // Empty list constructor
    List() : size(0) {}

    // Constructor with one student
    List(const Student& s) {
        students[0] = s;
        size = 1;
    }

    // Copy constructor
    List(const List& other) {
        size = other.size;
        for (int i = 0; i < size; i++) {
            students[i] = other.students[i];
        }
    }

    // Add to end
    void add(const Student& s) {
        if (size >= MAX_STUDENTS) {
            cout << "List is full.\n";
            return;
        }
        students[size++] = s;
    }

    // Add at specific position
    void addAt(const Student& s, int pos) {
        if (pos < 0 || pos > size || size >= MAX_STUDENTS) {
            cout << "Invalid position or list is full.\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            students[i] = students[i - 1];
        }
        students[pos] = s;
        size++;
    }

    // Remove by object
    void remove(const Student& s) {
        for (int i = 0; i < size; i++) {
            if (students[i].equals(s)) {
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                cout << "Student removed.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Remove at position
    void removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
        cout << "Student at position " << pos << " removed.\n";
    }

    // Return size
    int getSize() const { return size; }

    // Destroy list
    void destroy() {
        size = 0;
        cout << "List destroyed.\n";
    }

    // Display list
    void displayAll() const {
        if (size == 0) {
            cout << "List is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "Student " << (i + 1) << ":\n";
            students[i].display();
            cout << endl;
        }
    }
};

int main() {
    List studentList;

    Course c1("ICS2105", "Data Structures");
    Student s1("REG001", "Alice", 20, c1);
    Student s2("REG002", "Bob", 21, c1);
    Student s3("REG003", "Charlie", 22, c1);

    s1.set_marks(85);
    s2.set_marks(66);
    s3.set_marks(50);

    studentList.add(s1);
    studentList.add(s2);
    studentList.addAt(s3, 1); // insert at position 1

    studentList.displayAll();

    cout << "\nList size: " << studentList.getSize() << endl;

    studentList.removeAt(0); // remove Alice
    studentList.remove(s2);  // remove Bob

    studentList.displayAll();

    studentList.destroy();

    studentList.displayAll();

    return 0;
}
