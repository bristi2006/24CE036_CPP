#include <iostream>
#include <queue>
using namespace std;
class Fahrenheit;
class Celsius {
float temp;
public:
    Celsius(float t = 0) : temp(t) {}
 float getTemp() const {
        return temp;
    }
operator Fahrenheit();
bool operator==(const Celsius& other) const {
        return temp == other.temp;
    }
void display() const {
        cout << temp << "°C";
    }
};
class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t = 32) : temp(t) {}
 float getTemp() const {
        return temp;
    }
 operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }
  bool operator==(const Fahrenheit& other) const {

        return temp == other.temp;
    }
 void display() const {
        cout << temp << "°F";
    }
};
Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}
const int MAX = 100;
Fahrenheit manualFahrenheitArray[MAX];
Celsius manualCelsiusArray[MAX];
int fIndex = 0, cIndex = 0;
int main() {
    queue<Fahrenheit> fahrenheitQueue;
    queue<Celsius> celsiusQueue;
 int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter Celsius and convert to Fahrenheit\n";
        cout << "2. Enter Fahrenheit and convert to Celsius\n";
        cout << "3. Compare two Celsius temperatures\n";
        cout << "4. Compare two Fahrenheit temperatures\n";
        cout << "5. Process and display conversions (STL Queue)\n";
        cout << "6. Process and display conversions (Manual Array)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            float cTemp;
            cout << "Enter Celsius temperature: ";
            cin >> cTemp;
            Celsius c(cTemp);
            Fahrenheit f = c;
     fahrenheitQueue.push(f);
            if (fIndex < MAX) {
                manualFahrenheitArray[fIndex++] = f;
            }
            cout << "Converted: ";
            f.display();
            cout << endl;
        }
        else if (choice == 2) {
            float fTemp;
            cout << "Enter Fahrenheit temperature: ";
            cin >> fTemp;
            Fahrenheit f(fTemp);
            Celsius c = f;
     celsiusQueue.push(c);
            if (cIndex < MAX) {
                manualCelsiusArray[cIndex++] = c;
            }
            cout << "Converted: ";
            c.display();
            cout << endl;
        }
        else if (choice == 3) {
            float t1, t2;
            cout << "Enter two Celsius temperatures: ";
            cin >> t1 >> t2;
            Celsius c1(t1), c2(t2);
            if (c1 == c2) {
                cout << "Both Celsius temperatures are equal.\n";
            } else {
                cout << "Celsius temperatures are not equal.\n";
            }
        }
        else if (choice == 4) {
            float t1, t2;
            cout << "Enter two Fahrenheit temperatures: ";
            cin >> t1 >> t2;
            Fahrenheit f1(t1), f2(t2);
            if (f1 == f2) {
                cout << "Both Fahrenheit temperatures are equal.\n";
            } else {
                cout << "Fahrenheit temperatures are not equal.\n";
            }
        }
        else if (choice == 5) {
            cout << "\nProcessing Fahrenheit conversions (STL Queue):\n";
            while (!fahrenheitQueue.empty()) {
                fahrenheitQueue.front().display();
                cout << endl;
                fahrenheitQueue.pop();
            }
      cout << "\nProcessing Celsius conversions (STL Queue):\n";
            while (!celsiusQueue.empty()) {
                celsiusQueue.front().display();
                cout << endl;
                celsiusQueue.pop();
            }
        }
        else if (choice == 6) {
            cout << "\nProcessing Fahrenheit conversions (Manual Array):\n";
            for (int i = 0; i < fIndex; i++) {
                manualFahrenheitArray[i].display();
                cout << endl;
            }
cout << "\nProcessing Celsius conversions (Manual Array):\n";
            for (int i = 0; i < cIndex; i++) {
                manualCelsiusArray[i].display();
                cout << endl;
            }
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
 } while (choice != 0);
 cout<<"24ce036_Bristi"<<endl;
 return 0;
}
