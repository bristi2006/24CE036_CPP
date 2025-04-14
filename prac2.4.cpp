#include<iostream>
using namespace std;

class Item {
    int id;
    string n;
    int qty;
    double p;
public:
    void setData() {
        cout << "Enter ID, name, qty, price: ";
        cin >> id >> n >> qty >> p;
    }
    void updateQty(int q) {
        qty += q;
    }
    void display() {
        cout << "ID: " << id << "\nName: " << n << "\nQty: "  << qty << "\nPrice: " << p << endl;
    }
    int getId() {
        return id;
    }
};

Item i[100];
int cnt = 0;

void addItem() {
    i[cnt].setData();
    cnt++;
}

void updateItem() {
    int id, q;
    cout << "Enter ID: ";
    cin >> id;
    for (int j = 0; j < cnt; j++) {
        if (i[j].getId() == id) {
            cout << "Enter quantity to add: ";
            cin >> q;
            i[j].updateQty(q);
            return;
        }
    }
}

void showAllItems() {
    for (int j = 0; j < cnt; j++) i[j].display();
}

int main() {
    int ch;
    do {
        cout << "\n1. Add Item\n2. Update Qty\n3. Show All\n4.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: showAllItems(); break;
            case 4: cout << "Exiting..." << endl; break;
        }
    } while (ch != 4);
    cout<<"\n\n"<<"24CE036_Bristi"<<endl;
    return 0;

}
