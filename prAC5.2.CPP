#include <iostream>
#include <vector>
using namespace std;
class Complex {
private:
double real, imag;
public:
Complex(double r = 0, double i = 0) : real(r), imag(i) {}
Complex operator+(const Complex& other) {
return Complex(real + other.real, imag + other.imag);
    }
 Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }
friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
  friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};
void stlApproach() {
    vector<Complex> complexNumbers;
    int n;
  cout << "Enter number of complex numbers: ";
    cin >> n;
  for (int i = 0; i < n; ++i) {
        Complex c;

        cout << "Complex number " << i + 1 << ": " << endl;
        cin >> c;
        complexNumbers.push_back(c);
    }
  cout << "Sum of all complex numbers: ";
    Complex sum;
    for (const auto& c : complexNumbers) {
        sum = sum + c;
    }
    cout << sum << endl;
}
void nonStlApproach() {
    int n;
cout << "Enter number of complex numbers: ";
    cin >> n;
Complex* complexNumbers = new Complex[n];
 for (int i = 0; i < n; ++i) {
        cout << "Complex number " << i + 1 << ": " << endl;
        cin >> complexNumbers[i];
    }
 cout << "Sum of all complex numbers: ";
    Complex sum;
    for (int i = 0; i < n; ++i) {


        sum = sum + complexNumbers[i];
    }
    cout << sum << endl;
  delete[] complexNumbers;
}
int main() {
    cout << "Choose approach: 1 for STL, 2 for Non-STL: ";
    int choice;
    cin >> choice;
 if (choice == 1) {
        stlApproach();
    } else if (choice == 2) {
        nonStlApproach();
    } else {
        cout << "Invalid choice!" << endl;
    }
    cout<<"24CE036_Bristi"<<endl;
 return 0;
}

