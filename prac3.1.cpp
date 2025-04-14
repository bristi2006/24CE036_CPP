/* Programmer: Bristi Gopani
   Aim:to create an employee payroll management system for a retail store*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Employee class to manage employee details
class Employee
{
    string Name;
    double BasicSalary;
    double Bonus;

public:
    // Constructor to initialize employee details (with a default bonus of 5000)
    Employee(string name, double salary, double bonus=5000)
    {
       Name= name;
       BasicSalary= salary;
       Bonus= bonus;
    }

    // Inline function to calculate the total salary by adding basic salary and bonus
    inline double CalculateTotalSalary()
    {
        return BasicSalary + Bonus; // Return total salary
    }
    // Function to display employee details
    void Displaydetails()
    {
        cout << "Name: " << Name << endl;                   // Output employee's name
        cout << "Basic Salary: " << BasicSalary << endl;     // Output basic salary
        cout << "Bonus: " << Bonus << endl;                 // Output bonus
        cout << "Total Salary: " << CalculateTotalSalary() << endl; // Output total salary
    }
};
int main()
{
    // Vector to store employee records dynamically
    vector<Employee> employees;

    int numEmployees; // Variable to store the number of employees
    cout << "Enter the number of employees: ";
    cin >> numEmployees; // Input the number of employees

    // Loop to input details of each employee
    for(int i=0; i<numEmployees; i++)
    {
        string name;
        double salary;
        double bonus;

        // Input employee details
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;               // Input name
        cout << "Basic Salary: ";
        cin >> salary;             // Input basic salary
        cout << "Bonus (Enter 0 for default bonus): ";
        cin >> bonus;              // Input bonus (0 means use default bonus)

        // Add employee to the vector, handling default bonus if necessary
        if(bonus == 0)
            employees.push_back(Employee(name,salary)); // Use default bonus
        else
            employees.push_back(Employee(name,salary,bonus)); // Use custom bonus
    }
    // Display all employee payroll details
    cout << "\nEmployee Payroll Details:" << endl;

    // Loop to display each employee's details
    for(int i=0; i<numEmployees; i++)
    {
        employees[i].Displaydetails(); // Call function to display details
    }
    return 0;
}
