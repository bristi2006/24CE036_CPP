#include <iostream>
#include <stack>
using namespace std;
class Point {
public:
int x, y;
Point(int x = 0, int y = 0) : x(x), y(y) {}
Point operator-() const {

        return Point(-x, -y);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
   bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }
  void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};
class ManualStack {
    Point stack[100];
    int top;
public:
    ManualStack() : top(-1) {}
   void push(Point p) {
        if (top < 99) {
            stack[++top] = p;
        } else {
            cout << "Manual stack overflow!\n";
        }
    }
 Point pop() {
        if (top >= 0) {
            return stack[top--];
        } else {
            cout << "Manual stack underflow!\n";
            return Point();
        }
    }
  bool empty() const {
        return top == -1;
    }
};
int main() {
    Point current;
    stack<Point> stlStack;
    ManualStack manualStack;
 int choice;
    cout << "Initial Point: (0,0)\n";
do {
        cout << "\nChoose an operation:\n";
        cout << "1. Add a new Point\n";
        cout << "2. Negate the Point\n";
        cout << "3. Check Equality with another Point\n";
        cout << "4. Undo last operation (STL Stack)\n";
        cout << "5. Undo last operation (Manual Stack)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cout << "Enter x and y for new Point: ";
            cin >> a >> b;
            Point newPoint(a, b);
 stlStack.push(current);
            manualStack.push(current);
            current = current + newPoint;
            cout << "After Addition: ";
            current.display();
            cout << endl;
        }
        else if (choice == 2) {
            stlStack.push(current);
            manualStack.push(current);
                   current = -current;
            cout << "After Negation: ";
            current.display();
            cout << endl;
        }
        else if (choice == 3) {
            int a, b;
            cout << "Enter x and y for comparison Point: ";
            cin >> a >> b;
            Point other(a, b);
  if (current == other) {
                cout << "Points are Equal!\n";
            } else {
                cout << "Points are Not Equal.\n";
            }
        }
        else if (choice == 4) {
            if (!stlStack.empty()) {
                current = stlStack.top();
                stlStack.pop();
                cout << "After Undo (STL Stack): ";
                current.display();
                cout << endl;

            } else {
                cout << "No operations to undo (STL Stack).\n";
            }
        }
        else if (choice == 5) {
            if (!manualStack.empty()) {
                current = manualStack.pop();
                cout << "After Undo (Manual Stack): ";
                current.display();
                cout << endl;
            } else {
                cout << "No operations to undo (Manual Stack).\n";
            }
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid Choice! Try again.\n";
        }
    } while (choice != 6);
    cout<<"24CE036_Bristi"<<endl;
return 0;
}

