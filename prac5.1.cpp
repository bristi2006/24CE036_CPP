#include <iostream>
#include <vector>
using namespace std;
class Calculator {
public:
    int add(int a, int b) {
        cout << "Adding int + int: ";
        return a + b;

    }
double add(double a, double b) {
        cout << "Adding double + double: ";
        return a + b;
    }
 double add(int a, double b) {
        cout << "Adding int + double: ";
        return a + b;
    }
};
void displayResults(const vector<double>& results) {
    cout << "\nResults (Using Vector):\n";
    for (size_t i = 0; i < results.size(); ++i) {
        cout << "Result " << i + 1 << ": " << results[i] << endl;
    }
}
void displayResultsArray(double results[], int size) {
    cout << "\nResults (Using Array):\n";
    for (int i = 0; i < size; ++i) {
        cout << "Result " << i + 1 << ": " << results[i] << endl;
    }
}
int main() {

    int choice;
    cout << "Select Storage Approach:\n1. STL Vector\n2. Non-STL Array\nEnter choice: ";
    cin >> choice;
  Calculator calc;
    int n;
    cout << "Enter number of operations to perform: ";
    cin >> n;
   if (choice == 1) {
        vector<double> results;
for (int i = 0; i < n; ++i) {
            int type;
            cout << "\nChoose operation type:\n1. add(int, int)\n2. add(double,double)\n3. add(int, double)\nEnter choice: ";
            cin >> type;
  if (type == 1) {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                results.push_back(calc.add(a, b));
            }
            else if (type == 2) {
                double a, b;
                cout << "Enter two doubles: ";

  cin >> a >> b;
                results.push_back(calc.add(a, b));
            }
            else if (type == 3) {
                int a;
                double b;
                cout << "Enter an int and a double: ";
                cin >> a >> b;
                results.push_back(calc.add(a, b));
            }
            else {
                cout << "Invalid operation type!\n";
            }
        }
 displayResults(results);
 } else if (choice == 2) {
        double results[100];
        int count = 0;
   for (int i = 0; i < n; ++i) {
            int type;
            cout << "\nChoose operation type:\n1. add(int, int)\n2. add(double,double)\n3. add(int, double)\nEnter choice: ";
            cin >> type;


            if (type == 1) {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                results[count++] = calc.add(a, b);
            }
            else if (type == 2) {
                double a, b;
                cout << "Enter two doubles: ";
                cin >> a >> b;
                results[count++] = calc.add(a, b);
            }
            else if (type == 3) {
                int a;
                double b;
                cout << "Enter an int and a double: ";
                cin >> a >> b;
                results[count++] = calc.add(a, b);
            }
            else {
                cout << "Invalid operation type!\n";
            }

}
displayResultsArray(results, count);
} else {
cout << "Invalid choice!\n";
}
cout<<"24CE036_Bristi"<<endl;
return 0;
}
