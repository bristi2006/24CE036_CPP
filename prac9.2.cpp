#include <iostream>
#include <string>
using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string* transactions;
    int transactionCount;

    void logTransaction(const string& log) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount++] = log;
        } else {
            cout << "Transaction log full. Unable to log further operations.\n";
        }
    }

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
        transactions = new string[MAX_TRANSACTIONS];
        transactionCount = 0;
    }

    ~BankAccount() {
        delete[] transactions;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("ERROR: Invalid deposit attempt.");
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        logTransaction("Deposited: ₹" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("ERROR: Invalid withdrawal attempt.");
            cout << "Withdrawal amount must be positive.\n";
            return;
        }

        if (amount > balance) {
            logTransaction("ERROR: Withdrawal of ₹" + to_string(amount) + " failed due to insufficient funds.");
            cout << "Insufficient balance.\n";
            return;
        }

        balance -= amount;
        logTransaction("Withdrew: ₹" + to_string(amount));
    }

    void displayBalance() const {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void showTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; i++) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }
};

int main() {
    BankAccount account("Bristi", 10000.0);
    account.deposit(2000);
    account.withdraw(500);
    account.withdraw(15000); // Invalid
    account.deposit(-100);   // Invalid

    account.displayBalance();
    account.showTransactionHistory();

    cout << "\n24CE036_BRISTI\n";
    return 0;
}
