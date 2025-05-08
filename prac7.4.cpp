#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const char* FILE_NAME = "students.txt";

struct Student {
    char name[50];
    int marks;
    char grade;
};

ostream& col(ostream& os) {
    return os << left << setw(20);
}
void displayHeader() {
    cout << col << "Name" << setw(10) << "Marks" << setw(10) << "Grade" << "\n";
    cout << "------------------------------------------\n";
}
void processDirectFromFile() {
    ifstream fin(FILE_NAME);
    if (!fin) {
        cerr << "Error: Cannot open file '" << FILE_NAME << "'\n";
        return;
    }

    Student s;
    displayHeader();

    while (fin >> s.name >> s.marks >> s.grade) {
        cout << col << s.name << setw(10) << s.marks << setw(10) << s.grade << "\n";
    }

    fin.close();
}
void processWithMemory() {
    ifstream fin(FILE_NAME);
    if (!fin) {
        cerr << "Error: Cannot open file '" << FILE_NAME << "'\n";
        return;
    }
    int capacity = 10, count = 0;
    Student* students = new Student[capacity];

    Student temp;
    while (fin >> temp.name >> temp.marks >> temp.grade) {
        if (count == capacity) {
            capacity *= 2;

            Student* newArray = new Student[capacity];
            for (int i = 0; i < count; ++i)
                newArray[i] = students[i];
            delete[] students;
            students = newArray;
        }
        students[count++] = temp;
    }
    fin.close();
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (students[j].marks > students[i].marks) {
                Student t = students[i];
                students[i] = students[j];
                students[j] = t;
            }
        }
    }

    displayHeader();
    for (int i = 0; i < count; ++i) {
        cout << col << students[i].name << setw(10) << students[i].marks << setw(10)
<< students[i].grade << "\n";

    }

    delete[] students;
}
int main() {
    int choice;
    do {
        cout << "\nStudent Report System\n";
        cout << "1. Display Direct from File\n";
        cout << "2. Load to Memory and Sort\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
 switch (choice) {
            case 1: processDirectFromFile(); break;
            case 2: processWithMemory(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 3);
    cout<<"24CE036_Bristi"<<endl;
 return 0;
}
