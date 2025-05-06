#include <iostream>
#include <map>
#include <string>
using namespace std;
class Person {
protected:
string name;
int age;
public:
    Person(string n = "", int a = 0) {
        name = n;
        age = a;
    }
void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Employee : public Person {
protected:
    int employeeID;
public:
    Employee(string n = "", int a = 0, int id = 0) : Person(n, a) {
        employeeID = id;
    }
  void displayEmployee() const {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
    }
};
class Manager : public Employee {
private:

string department;
public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "") : Employee(n, a, id) {
        department = dept;
    }
void displayManager() const {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
int getEmployeeID() const {
        return employeeID;
    }
};
int main() {
    int n;
    cout << "Enter number of managers: ";
    cin >> n;

    cout << "\n=== STL Approach (using std::map) ===" << endl;
    map<int, Manager> managerMap;

    for (int i = 0; i < n; ++i) {
        string name, department;
        int age, id;
       cout << "\nEnter details for Manager " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin >> department;
       Manager m(name, age, id, department);
        managerMap[id] = m;
    }
   cout << "\nDisplaying Manager details (using map):" << endl;
    for (const auto& entry : managerMap) {
        cout << "\nEmployee ID: " << entry.first << endl;
        entry.second.displayManager();
    }
cout << "\n=== Non-STL Approach (using array) ===" << endl;
    Manager* managerArray = new Manager[n];

    for (int i = 0; i < n; ++i) {
        string name, department;
        int age, id;

        cout << "\nEnter details for Manager " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin >> department;

        managerArray[i] = Manager(name, age, id, department);
    }
  cout << "\nDisplaying Manager details (using array):" << endl;
    for (int i = 0; i < n; ++i) {
        managerArray[i].displayManager();
        cout << endl;
    }
   delete[] managerArray;
   cout<<"---------24CE036_Bristi--------"<<endl;
    return 0;
}
