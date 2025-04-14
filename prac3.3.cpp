/* Programmer: Bristi Gopani
   Aim: To create a Bank Account Management System */
#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolder;
    double balance;
    static int totalAccounts;

public:
    Account(int accNum, string name, double bal)
    {
        accountNumber = accNum;
        accountHolder = name;
        balance = bal;
        totalAccounts++;
    }
    void display() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    void transferMoney(Account &receiver, double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful!\n";
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    static int getTotalAccounts()
    {
        return totalAccounts;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }
};

// Initialize static variable
int Account::totalAccounts = 0;

// Function to find the index of an account by account number
int findAccount(const vector<Account> &accounts, int accNum)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getAccountNumber() == accNum)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<Account> accounts;
    int choice;

    do {
        cout << "\nBank Account Management System\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int accNum;
                string name;
                double balance;

                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore(); // Ignore previous newline
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> balance;

                accounts.push_back(Account(accNum, name, balance)); // Dynamic account creation
                cout << "Account created successfully!\n";
                break;
            }

            case 2:
            {
                cout << "\nAll Accounts:\n";
                for (int i = 0; i < accounts.size(); i++)
                {
                    accounts[i].display();
                    cout << "---------------------------\n";
                }
                break;
            }

            case 3:
            {
                int senderAccNum, receiverAccNum;
                double amount;

                cout << "Enter sender's account number: ";
                cin >> senderAccNum;
                cout << "Enter receiver's account number: ";
                cin >> receiverAccNum;
                cout << "Enter amount to transfer: ";
                cin >> amount;

                int senderIndex = findAccount(accounts, senderAccNum);
                int receiverIndex = findAccount(accounts, receiverAccNum);

                if (senderIndex == -1 || receiverIndex == -1)
                {
                    cout << "Invalid account number(s)! Transfer failed.\n";
                }
                else
                {
                    accounts[senderIndex].transferMoney(accounts[receiverIndex], amount);
                }
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);
cout << "\n24CE036_Bristi\n";
    return 0;
}
