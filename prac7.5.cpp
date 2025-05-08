#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
ostream& currency(ostream& os) {
os << "₹";

    return os;
}
struct Student {
    string name;
    double marks;
    double tuition;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    cout << "\nEnter student details:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Marks: ";
        cin >> students[i].marks;
        cout << "Tuition Fee: ";
        cin >> students[i].tuition;
    }
    cout << "\n" << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << left << setw(20) << "Name"
         << right << setw(10) << "Marks"
         << right << setw(20) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (const auto& s : students) {
        cout << left << setw(20) << s.name
             << right << setw(10) << fixed << setprecision(2) << s.marks
             << right << setw(7) << currency << fixed << setprecision(2) << s.tuition <<
endl;
    }

    cout << setfill('-') << setw(60) << "-" << endl;
    cout<<"24CE036_Bristi"<<endl;
    return 0;
}
