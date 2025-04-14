/*Programmer:Bristi Gopani
*/
#include<iostream>
#include<vector>
using namespace std;

class Bank {
    int a_no;
    string n;
    double b;
public:
    void setData(int no, string name, double bal) {
        a_no = no;
        n = name;
        b = bal;
    }
    void dep(double amt) {
        b += amt;
    }
    void wth(double amt) {
        if (amt > b) cout << "Insufficient balance" << endl;
        else b -= amt;
    }
    void display() {
        cout << "Account No: " << a_no << "\nName: " << n <<
         "\nBalance: " << b << endl;
    }
    int getNo() {
        return a_no;
    }
};

vector<Bank> acc;

void addAcc() {
    int no;
    string name;
    double bal;
    cout << "Enter account no, name, balance: ";
    cin >> no >> name >> bal;
    acc.push_back(Bank());
    acc.back().setData(no, name, bal);
}

void depAcc() {
    int no;
    double amt;
    cout << "Enter account no: ";
    cin >> no;
    for (auto &a : acc) {
        if (a.getNo() == no) {
            cout << "Enter deposit amount: ";
            cin >> amt;
            a.dep(amt);
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void wthAcc() {
    int no;
    double amt;
    cout << "Enter account no: ";
    cin >> no;
    for (auto &a : acc) {
        if (a.getNo() == no) {
            cout << "Enter withdrawal amount: ";
            cin >> amt;
            a.wth(amt);
            return;
        }
    }
    cout << "Account not found!" << endl;
}

void showAllAcc() {
    for (auto &a : acc) a.display();
}

int main() {
    int ch;
    do {
        cout << "\n1. Add Account\n2. Deposit\n3. Withdraw \n4. Show All\n5. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: addAcc(); break;
            case 2: depAcc(); break;
            case 3: wthAcc(); break;
            case 4: showAllAcc(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (ch != 5);

    cout<<"\n\n"<<"24CE036_Bristi"<<endl;
    return 0;
}
