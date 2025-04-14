/* Programmer: Bristi Gopani
   Aim: To create a loan management system */

#include<iostream>
#include<string>
#include<cmath> // For pow() function
using namespace std;

// Class to represent a loan
class Loan
 {
    int loanId;                // Unique Loan ID
    string applicantName;      // Applicant's Name
    float loanAmount;          // Total Loan Amount
    float annualInterestRate;  // Annual Interest Rate (in %)
    int tenureMonths;          // Loan tenure in months

public:
    // Default constructor to initialize loan with test data
    Loan()
     {
        loanId = 0;
        applicantName = "Test Applicant";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    // Parameterized constructor to initialize loan with specific values
    Loan(int id, string name, float amount, float rate, int tenure)
     {
        loanId = id;
        applicantName = name;
        loanAmount = amount;

        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    // Function to calculate EMI using the standard formula
    float calculateEMI()
    {
        float monthlyRate = annualInterestRate / (12 * 100); // Monthly interest rate
        return (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
               (pow(1 + monthlyRate, tenureMonths) - 1);
    }

    // Function to display loan details
    void displayLoanDetails()
    {
        cout << "Loan ID: " << loanId << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Tenure (in months): " << tenureMonths << endl;
        cout << "Calculated EMI: " << calculateEMI() << endl;
    }

    // Function to get loan ID
   inline  int getLoanId()
    {
        return loanId;
    }
};

int main()
 {
    int n;
    cout << "Enter the number of loan records to be created: ";
    cin >> n;

    Loan loans[n]; // Array to store multiple loan records

    // Loop to initialize loan details
    for (int i = 0; i < n; i++)
        {
        int id, tenure;
        string name;
        float amount, rate;

        cout << "\nEnter details for Loan " << (i + 1) << ":" << endl;
        cout << "Enter Loan ID (or 0 for default): ";
        cin >> id;

        if (id == 0)
        {
            loans[i] = Loan(); // Use default constructor
            cout << "Default loan record added." << endl;
        }
        else
        {
            cout << "Enter Applicant Name: ";


            cin>>name;
            cout << "Enter Loan Amount: ";
            cin >> amount;
            cout << "Enter Annual Interest Rate (in %): ";
            cin >> rate;
            cout << "Enter Loan Tenure (in months): ";
            cin >> tenure;

            loans[i] = Loan(id, name, amount, rate, tenure); // Use parameterized constructor
        }
    }

    int choice, loan_id;

    // Menu-driven interface for user interaction
    do {
        cout << "\nEnter (1) to View Loan Details" << endl;
        cout << "Enter (2) to Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Display loan details for a specific loan
            cout << "Enter Loan ID: ";
            cin >> loan_id;

            for (int i = 0; i < n; i++)
            {
                if (loans[i].getLoanId() == loan_id)
                {
                    loans[i].displayLoanDetails();
                    break;
                }
                if (i == n - 1)
                {
                    cout << "Invalid Loan ID." << endl;
                }
            }
            break;

        case 2:
            cout << "Exiting the system." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 2); // Continue until user chooses to exit

    cout << "\n24CE036_Bristi\n";
    return 0;
}
