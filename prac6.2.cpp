#include <iostream>
using namespace std;
class Point {
private:
int x, y;
public:
Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}
Point& move(int dx, int dy) {

        x += dx;
        y += dy;
        return *this;
 }
    void display() const {
        cout << "Point Coordinates: (" << x << ", " << y << ")\n";
    }
};
void updatePoint(Point* p) {
    int dx, dy;
    cout << "Enter dx (change in x): ";
    cin >> dx;
    cout << "Enter dy (change in y): ";
    cin >> dy;
    p->move(dx, dy);
}
int main() {
    int x, y;
    cout << "Enter initial x coordinate: ";
    cin >> x;
    cout << "Enter initial y coordinate: ";
    cin >> y;
    Point* p = new Point(x, y);

 char choice;
    do {
        p->display();
 updatePoint(p);
        cout << "Do you want to move again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
           cout << "Final ";
          p->display();
          delete p;
          cout<<"24CE036_Bristi"<<endl;
return 0;
}
