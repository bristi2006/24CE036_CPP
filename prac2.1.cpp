/* Programmer: Bristi Gopani
   Date:10-2-25
   Aim:to create a rectangle management system*/

#include <iostream>
using namespace std;

// Rectangle class to manage length, width, area, and perimeter
class Rectangle
{
    double length, width; // Private data members for length and width

  public:

    // Function to set dimensions of the rectangle
    void setDimensions(double l, double w)
    {
        length = l;
        width = w;
    }

    // Inline function to calculate the area of the rectangle
    inline double getArea()
    {
        return length * width;
    }

    // Inline function to calculate the perimeter of the rectangle
    inline double getPerimeter()
    {
        return 2 * (length + width);
    }

    // Function to display rectangle details
    void display()
    {
        cout << "Rectangle: Length = " << length << ", Width = " << width


             << ", Area = " << getArea() << ", Perimeter = " << getPerimeter() << endl;
    }
};

int main() {
    Rectangle rectangles[20]; // Array to store up to 20 rectangles
    int i, n, choice; // Variables for loops, input size, and menu choice

    // Menu-driven system for rectangle management
    do {
        cout << "\nRectangle Management System" << endl;
        cout << "1. Add rectangles" << endl;
        cout << "2. Update a rectangle" << endl;
        cout << "3. Display all rectangles" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Option 1: Add rectangles
        if (choice == 1)
        {
            cout << "\nEnter the number of rectangles:";
            cin >> n;
            double l, w; // Variables to store user input for length and width
            for (i = 0; i < n; i++)
            {
                cout << "Enter length: ";
                cin >> l;
                cout << "Enter width: ";
                cin >> w;
                rectangles[i].setDimensions(l, w); // Set dimensions for each rectangle
                cout << "Rectangle added successfully!" << endl;
            }
        }
        // Option 2: Update a specific rectangle
        else if (choice == 2)
        {
            int index; // Variable to store index of rectangle to update
            double l, w; // Variables for new length and width
            cout << "Enter rectangle index to update (0 to " << n - 1 << "): ";
            cin >> index;
            for (i = 0; i < n; i++)
            {
                if (index == i) // Check if index matches
                {
                    cout << "Enter new length: ";
                    cin >> l;

                    cout << "Enter new width: ";
                    cin >> w;
                    rectangles[i].setDimensions(l, w); // Update dimensions
                    cout << "Rectangle updated successfully!" << endl;
                }
            }
        }
        // Option 3: Display all rectangles
        else if (choice == 3)
        {
            for (i = 0; i < n; i++)
            {
                cout << "Rectangle " << i + 1 << ": ";
                rectangles[i].display(); // Display each rectangle's details
            }
        }
    } while (choice != 4); // Continue until the user chooses to exit

    cout << "Exiting program..." << endl;
    cout << "\n24CE036_Bristi\n";

    return 0;
}
