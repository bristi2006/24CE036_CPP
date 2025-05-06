#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};
class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }
void display() const override {
        cout << "Rectangle (Length: " << length << ", Width: " << width << ")";
    }
};
class Circle : public Shape {

    double radius;
public:
    Circle(double r) : radius(r) {}
double Area() const override {
        return M_PI * radius * radius;
    }
 void display() const override {
        cout << "Circle (Radius: " << radius << ")";
    }
};
const int MAX_SHAPES = 100;
Shape* manualShapes[MAX_SHAPES];
int shapeCount = 0;

int main() {
    vector<Shape*> shapes;
    int choice;
 do {
        cout << "\nMenu:\n";
        cout << "1. Add Rectangle\n";
        cout << "2. Add Circle\n";
        cout << "3. Display Areas (STL Vector)\n";
        cout << "4. Display Areas (Manual Array)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
if (choice == 1) {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            Shape* rect = new Rectangle(l, w);
    shapes.push_back(rect);
            if (shapeCount < MAX_SHAPES) {
                manualShapes[shapeCount++] = rect;
            }
        }
        else if (choice == 2) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            Shape* circ = new Circle(r);
  shapes.push_back(circ);
            if (shapeCount < MAX_SHAPES) {
                manualShapes[shapeCount++] = circ;
            }
        }
        else if (choice == 3) {
            cout << "\nAreas of Shapes (STL Vector):\n";
            for (auto s : shapes) {
                s->display();
                cout << " -> Area: " << s->Area() << endl;
            }
        }
        else if (choice == 4) {
            cout << "\nAreas of Shapes (Manual Array):\n";
            for (int i = 0; i < shapeCount; ++i) {
                manualShapes[i]->display();
                cout << " -> Area: " << manualShapes[i]->Area() << endl;
            }
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
 } while (choice != 0);
 for (auto s : shapes) {
        delete s;
        cout<<"24CE036_Bristi"<<endl;
}
return 0;
}
