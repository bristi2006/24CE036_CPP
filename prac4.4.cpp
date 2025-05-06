#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Transaction
 {
   string type;
   double amount;
};
class BankAccount
 {
   protected:
   int accountNumber;
   double balance;
   public:
   BankAccount(int accNo, double bal) : accountNumber(accNo), balance(bal) {
   cout << "BankAccount created. Account Number: " << accountNumber << endl;
}
virtual ~BankAccount() {
cout << "BankAccount destroyed. Account Number: " << accountNumber << endl;
}
virtual void deposit(double amount) {
balance += amount;
cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
}
virtual void withdraw(double amount) {
if (amount <= balance)
    {
     balance -= amount;
     cout << "Withdrawn: " << amount << ", Remaining Balance: " << balance << endl;
    }
else
    {
     cout << "Insufficient balance!" << endl;
    }
}
virtual void display() const {
cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
}
double getBalance() const {
return balance;
}
};

class SavingsAccount : public BankAccount
 {
    private:
    double interestRate;
    public:
    SavingsAccount(int accNo, double bal, double rate) : BankAccount(accNo, bal), interestRate(rate) {
        cout << "SavingsAccount created with interest rate: " << interestRate << "%" << endl;
  }
~SavingsAccount() {
cout << "SavingsAccount destroyed. Account Number: " << accountNumber << endl;
}
void applyInterest()
{
    double interest = balance * (interestRate / 100);
    balance += interest;
    cout << "Interest Applied: " << interest << ", New Balance: " << balance << endl;
}
void display() const override
{
     BankAccount::display();
     cout << "Interest Rate: " << interestRate << "%" << endl;
}
};
class CurrentAccount : public BankAccount
{
    private:
    double overdraftLimit;
    public:

CurrentAccount(int accNo, double bal, double limit): BankAccount(accNo, bal), overdraftLimit(limit)
   {
       cout << "CurrentAccount created with overdraft limit: " << overdraftLimit << endl;
   }
~CurrentAccount()
   {
       cout << "CurrentAccount destroyed. Account Number: " << accountNumber << endl;
   }
void withdraw(double amount) override
{
if (amount <= balance + overdraftLimit)
    {
      balance -= amount;
      cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
    }
else
     {
     cout << "Withdrawal exceeds overdraft limit!" << endl;
     }
}
void display() const override {
BankAccount::display();
cout << "Overdraft Limit: " << overdraftLimit << endl;
}
};
class ManualStack
{
private:
struct Node
 {
  Transaction data;
  Node* next;
};
Node* top;

public:
ManualStack() : top(nullptr) {}
~ManualStack() {
while (top) {
Node* temp = top;
top = top->next;
delete temp;
}
}
void push(const Transaction& txn)
 {
Node* node = new Node{txn, top};
top = node;
 }
bool pop(Transaction& txn)
 {
   if (!top) return false;
   txn = top->data;
  Node* temp = top;
  top = top->next;
  delete temp;
  return true;
}
bool isEmpty() const
{
  return top == nullptr;
}
};
void menu() {

cout << "\nChoose Operation:\n";
cout << "1. Deposit\n";
cout << "2. Withdraw\n";
cout << "3. Apply Interest (Savings Only)\n";
cout << "4. Undo Last Transaction\n";
cout << "5. Display Account Info\n";
cout << "6. Exit\n";
cout << "Enter choice: ";
}
int main() {
int choice, accType;
cout << "Select Account Type:\n1. Savings Account\n2. Current Account\nEnter choice: ";
cin >> accType;
BankAccount* account = nullptr;
stack<Transaction> txnStackSTL;
ManualStack txnStackManual;
int accNo;
double initialBalance, interestRate = 0, overdraftLimit = 0;
cout << "Enter Account Number: ";
cin >> accNo;
cout << "Enter Initial Balance: ";
cin >> initialBalance;
if (accType == 1) {
cout << "Enter Interest Rate (%): ";
cin >> interestRate;

account = new SavingsAccount(accNo, initialBalance, interestRate);
}
else if (accType == 2)
    {
       cout << "Enter Overdraft Limit: ";
       cin >> overdraftLimit;
       account = new CurrentAccount(accNo, initialBalance, overdraftLimit);
   }
else
    {
    cout << "Invalid choice!\n";
    return 1;
    }
bool running = true;
while (running) {
menu();
cin >> choice;
double amount;
switch (choice) {
case 1:
cout << "Enter deposit amount: ";
cin >> amount;
account->deposit(amount);
txnStackSTL.push({"deposit", amount});
txnStackManual.push({"deposit", amount});
break;
case 2:
cout << "Enter withdraw amount: ";
cin >> amount;
account->withdraw(amount);
txnStackSTL.push({"withdraw", amount});

txnStackManual.push({"withdraw", amount});
break;
case 3:
case 4:
if (SavingsAccount* sa = dynamic_cast<SavingsAccount*>(account)) {
sa->applyInterest();
} else {
cout << "Interest application not available for Current Account.\n";
}
break;
int undoChoice;
cout << "Undo using:\n1. STL stack\n2. Manual stack\nEnter choice: ";
cin >> undoChoice;
if (undoChoice == 1)
    {
        if (!txnStackSTL.empty()) {
           Transaction last = txnStackSTL.top();
            txnStackSTL.pop();
               if (last.type == "deposit") {
           account->withdraw(last.amount);
           cout << "Reversed deposit of " << last.amount << endl;
    }
else if (last.type == "withdraw")
  {
        account->deposit(last.amount);
        cout << "Reversed withdrawal of " << last.amount << endl;
  }
}
 else
   {
    cout << "No transactions to undo.\n";
   }

 }
else if (undoChoice == 2)
    {
        Transaction last;
                if (txnStackManual.pop(last)) {
                        if (last.type == "deposit")
                        {
                            account->withdraw(last.amount);
                            cout << "Reversed deposit of " << last.amount << endl;
                        }
  else if (last.type == "withdraw")
    {
            account->deposit(last.amount);
            cout << "Reversed withdrawal of " << last.amount << endl;
    }

 } else
     {
       cout << "No transactions to undo.\n";
     }
   } else
     {
        cout << "Invalid choice.\n";
     }
        break;
 case 5:
        account->display();
        break;
 case 6:
        running = false;
        break;

    default:
        cout << "Invalid option.\n";
        }
    }
delete account;
cout<<"24CE036_Bristi"<<endl;
return 0;
}
