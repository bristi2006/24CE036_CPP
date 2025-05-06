#include <iostream>
#include <vector>
#include <string>
using namespace std;
class GradingCriteria {
protected:
double marks;
public:
GradingCriteria(double m) : marks(m) {}

    virtual ~GradingCriteria() {}
    virtual string computeGrade() const = 0;
};
class UndergraduateStudent : public GradingCriteria {
public:
    UndergraduateStudent(double m) : GradingCriteria(m) {}
  string computeGrade() const override {
        if (marks >= 90) return "A";
        else if (marks >= 80) return "B";
        else if (marks >= 70) return "C";
        else if (marks >= 60) return "D";
        else return "F";
    }
};
class PostgraduateStudent : public GradingCriteria {
public:
    PostgraduateStudent(double m) : GradingCriteria(m) {}

    string computeGrade() const override {
        if (marks >= 85) return "A";
        else if (marks >= 75) return "B";
        else if (marks >= 65) return "C";
        else if (marks >= 55) return "D";

        else return "F";
    }
};
void displayGrades(vector<GradingCriteria*>& students) {
    cout << "\nStudent Grades (Using Vector):\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "Student " << i+1 << ": " << students[i]->computeGrade() << endl;
    }
}
void displayGradesArray(GradingCriteria* students[], int count) {
    cout << "\nStudent Grades (Using Array):\n";
    for (int i = 0; i < count; ++i) {
        cout << "Student " << i+1 << ": " << students[i]->computeGrade() << endl;
    }
}
int main() {
    int choice;
    cout << "Select Approach:\n1. STL Vector\n2. Non-STL Array\nEnter choice: ";
    cin >> choice;
 if (choice == 1) {
        vector<GradingCriteria*> students;
        int n;
        cout << "Enter number of students: ";
        cin >> n;
 for (int i = 0; i < n; ++i) {
            int type;
            double marks;
            cout << "Student " << i+1 << ":\n";
            cout << "1. Undergraduate\n2. Postgraduate\nEnter type: ";
            cin >> type;
            cout << "Enter marks: ";
            cin >> marks;
  if (type == 1)
                students.push_back(new UndergraduateStudent(marks));
            else if (type == 2)
                students.push_back(new PostgraduateStudent(marks));
            else
                cout << "Invalid type!\n";
        }
 displayGrades(students);
 for (auto student : students)
            delete student;
 } else if (choice == 2) {
        GradingCriteria* students[100];
        int n;
        cout << "Enter number of students: ";

        cin >> n;
for (int i = 0; i < n; ++i) {
            int type;
            double marks;
            cout << "Student " << i+1 << ":\n";
            cout << "1. Undergraduate\n2. Postgraduate\nEnter type: ";
            cin >> type;
            cout << "Enter marks: ";
            cin >> marks;
 if (type == 1)
                students[i] = new UndergraduateStudent(marks);
            else if (type == 2)
                students[i] = new PostgraduateStudent(marks);
            else
                cout << "Invalid type!\n";
        }
 displayGradesArray(students, n);
 for (int i = 0; i < n; ++i)
            delete students[i];
 } else {
        cout << "Invalid choice!\n";
    }
return 0;
}
