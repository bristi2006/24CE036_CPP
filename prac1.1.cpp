/* Programmer: Bristi gopani
   Date:10-2-25
   Aim:The bank needs an OOP-based system for secure account management, allowing deposits,
withdrawals, and balance checks*/
#include<iostream>
#include<string>
using namespace std;

// BankAccounts class to manage customer accounts
class BankAccounts
{
    // Private data members to store account details
    string Name;      // Account holder's name
    int AccNumber;    // Unique account number
    double Balance;   // Account balance

public:
    // Function to set details of the user
    void Setdetails(string name, int num, double balance)
    {
        Name = name;
        AccNumber = num;
        Balance = balance;
    }

    // Function to view account details
    void Viewdetails()
    {
        cout<<"Your details are as follows:"<<endl;
        cout << "Account Holder's Name is: " << Name << endl;
        cout << "Account Number is: " << AccNumber << endl;
        cout << "Account's current Balance is: " << Balance << endl;
    }

    // Function to deposit money into the account
    void DepositMoney(int Amount)
    {
       if (Amount > 0)
       {
           Balance += Amount; // Increase balance by deposit amount
           cout << Amount << " deposited successfully" << endl;
           cout << "New Balance is: " << Balance << endl;
       }
       else
       {
           cout << "Invalid deposit amount." << endl;
       }
    }
    // Function to withdraw money from the account
    void WithdrawMoney(int Amount)
    {
        if (Amount > 0 && Amount <= Balance)
        {
           Balance -= Amount; // Decrease balance by withdrawal amount
           cout << Amount << " withdrawn successfully" << endl;
           cout << "New Balance is: " << Balance << endl;
        }
        else if (Amount > Balance)
        {
            cout << "Not enough money to withdraw" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
};
int main()
{
    BankAccounts Account; // Create an instance of BankAccounts

    string name;    // Variable to store the account holder's name
    int number;     // Variable to store the account number
    double balance; // Variable to store the initial balance

    // Collect account details from the user
    cout << "Enter your Account Details" << endl;
    cout << "Enter Account Holder's Name: ";
    cin >> name;
    cout << "\nEnter Account Number: ";
    cin >> number;
    cout << "\nEnter Account's Balance: ";
    cin >> balance;

    // Set the account details using the Setdetails method
    Account.Setdetails(name, number, balance);

    double Amt; // Variable to store deposit/withdrawal amount
    int i;      // Variable to store user choice

    // Menu-driven interface for user interaction
    do
    {
      cout << "\nEnter (1) to view your details" << endl;
      cout << "Enter (2) to Deposit Money" << endl;
      cout << "Enter (3) to Withdraw Money" << endl;
      cout << "Enter (4) to exit" << endl;
      cout<<endl<<"Enter your choice:";
      cin >> i;

      // Perform operations based on user input
      switch(i)
      {
       case 1:
         Account.Viewdetails();
         break;

       case 2:
         cout << "Enter the amount to be deposited: ";
         cin >> Amt;
         Account.DepositMoney(Amt);
         break;

       case 3:
         cout << "Enter the amount to be withdrawn: ";
         cin >> Amt;
         Account.WithdrawMoney(Amt);
         break;

       case 4:
         cout << "Exiting the System" << endl;
         break;

       default:
         cout << "Invalid choice. Please try again." << endl;
      }
      cout<<"24CE036_Bristi"<<endl;

    } while(i != 4); // Continue until user chooses to exit
    return 0;
}
