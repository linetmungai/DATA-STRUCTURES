#include <iostream>
#include <string>

#define MAX_STUDENTS 40

using namespace std;

class Course {
public:
    string courseCode;
    string courseName;
};

class Grade {
public:
    int mark;
    char theGrade;
    bool isFinalized;

    Grade() {
        mark = -1;
        theGrade = 'N';
        isFinalized = false;
    }

    char calculateGrade(int m) {
        if (m > 69) return 'A';
        else if (m > 59) return 'B';
        else if (m > 49) return 'C';
        else if (m > 39) return 'D';
        else return 'E';
    }
};

class Student {
public:
    string regNumber;
    string name;
    int age;
    Course course;
    Grade grade;

    void input() {
        cin.ignore();
        cout << "Enter registration number: ";
        getline(cin, regNumber);
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter course code: ";
        getline(cin, course.courseCode);
        cout << "Enter course name: ";
        getline(cin, course.courseName);
    }

    void display() const {
        cout << "Reg No: " << regNumber << ", Name: " << name << ", Age: " << age << "\n";
        cout << "Course: " << course.courseName << " (" << course.courseCode << ")\n";
        if (grade.mark != -1)
            cout << "Mark: " << grade.mark << ", Grade: " << grade.theGrade << "\n";
        else
            cout << "Grade not assigned.\n";
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
    // Constructor - Empty List
    List() {
        size = 0;
    }

    // Constructor - List with one student
    List(const Student& s) {
        students[0] = s;
        size = 1;
    }

    // Constructor - Copy constructor
    List(const List& other) {
        size = other.size;
        for (int i = 0; i < size; ++i) {
            students[i] = other.students[i];
        }
    }

    // Add a student to the end
    void add(const Student& s) {
        if (size >= MAX_STUDENTS) {
            cout << "List is full.\n";
            return;
        }
        students[size++] = s;
        cout << "Student added.\n";
    }

    // Adding a student at a specific position
    void addAt(const Student& s, int position) {
        if (position < 0 || position > size || size >= MAX_STUDENTS) {
            cout << "Invalid position or list full.\n";
            return;
        }
        for (int i = size; i > position; --i) {
            students[i] = students[i - 1];
        }
        students[position] = s;
        ++size;
        cout << "Student inserted at position " << position << ".\n";
    }

    // Removing a student (by regNumber)
    void remove(const Student& s) {
        for (int i = 0; i < size; ++i) {
            if (students[i].equals(s)) {
                for (int j = i; j < size - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --size;
                cout << "Student removed.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Remove student at position
    void removeAt(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = position; i < size - 1; ++i) {
            students[i] = students[i + 1];
        }
        --size;
        cout << "Student at position " << position << " removed.\n";
    }

    // Get current size
    int getSize() const {
        return size;
    }

    // Destroy the list
    void destroy() {
        size = 0;
        cout << "List destroyed.\n";
    }

    // Display all students
    void displayAll() const {
        for (int i = 0; i < size; ++i) {
            cout << "\nStudent " << (i + 1) << ":\n";
            students[i].display();
        }
    }
};

int main() {
    List studentList;
    int choice;

    do {
        cout << "\n--- Student List Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Add Student at Position\n";
        cout << "3. Remove Student by Registration Number\n";
        cout << "4. Remove Student at Position\n";
        cout << "5. Display All Students\n";
        cout << "6. Get List Size\n";
        cout << "7. Destroy List\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        Student temp;
        int pos;

        switch (choice) {
            case 1:
                temp.input();
                studentList.add(temp);
                break;

            case 2:
                temp.input();
                cout << "Enter position (0-based): ";
                cin >> pos;
                studentList.addAt(temp, pos);
                break;

            case 3:
                cin.ignore();
                cout << "Enter reg number to remove: ";
                getline(cin, temp.regNumber);
                studentList.remove(temp);
                break;

            case 4:
                cout << "Enter position to remove (0-based): ";
                cin >> pos;
                studentList.removeAt(pos);
                break;

            case 5:
                studentList.displayAll();
                break;

            case 6:
                cout << "List size: " << studentList.getSize() << "\n";
                break;

            case 7:
                studentList.destroy();
                break;

            case 8:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
