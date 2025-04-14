/* Programmer: Bristi Gopani
   Aim: To create a student management system for academic performance tracking */
#include <iostream>
#include <string>
using namespace std;

// Student class to manage personal and academic details
class Student
{
    int rollNumber;      // Student's roll number
    string name;         // Student's name
    float marks[3];      // Marks in three subjects

public:
    // Default constructor to initialize with test data
    Student()
    {
        rollNumber = 0;
        name = "Test Student";
        marks[0] = marks[1] = marks[2] = 0.0;
    }

    // Parameterized constructor to initialize with specific values
    Student(int roll, string studentName, float m1, float m2, float m3)
    {
        rollNumber = roll;
        name = studentName;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Function to calculate the average marks
    float calculateAverage()
     {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Function to display student details
    void displayDetails()
    {
        cout << "\nRoll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
    }
};

int main()
 {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[20]; // Array to store multiple student records

    // Populate the array with a mix of default and user-defined values
    for (int i = 0; i < n; i++) {
        int roll;
        string name;
        float m1, m2, m3;

        cout << "\nEnter details for Student " << (i + 1) << ":" << endl;
        cout << "Enter Roll Number (or 0 for default): ";
        cin >> roll;

        if (roll == 0)
        {
            // Use default constructor
            students[i] = Student();
            cout << "Default student record added." << endl;
        } else
         {
            cout << "Enter Name: ";
            cin>>name;
            cout << "Enter Marks in 3 subjects: ";
            cin >> m1 >> m2 >> m3;

            // Initialize with specific input values
            students[i] = Student(roll, name, m1, m2, m3);
        }
    }
    // Display all student records
    cout << "\nDisplaying Student Records:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].displayDetails();
    }

    cout << "\n24CE036_Bristi\n";
    return 0;
}
