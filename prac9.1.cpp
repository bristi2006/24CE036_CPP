#include <iostream>
#include <limits>
using namespace std;

bool getValidInput(double &value, const string &prompt) {
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            cout << "Invalid input. Please enter a numeric value.\n";
        } else {
            return true;
        }
    }
}

int main() {
    double loanAmount = 0, income = 0;

    getValidInput(loanAmount, "Enter loan amount: ");

    do {
        getValidInput(income, "Enter annual income: ");
        if (income == 0) {
            cout << "Annual income cannot be zero. Please re-enter.\n";
        }
    } while (income == 0);
    double ratio = loanAmount / income;

    cout.precision(2);
    cout << fixed;
    cout << "Loan-to-Income Ratio: " << ratio << endl;

    cout << "24CE036_BRISTI";
    return 0;
}
