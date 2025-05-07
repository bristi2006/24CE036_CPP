#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
const char* FILE_NAME = "inventory.txt";
struct Item {
    char name[50];
    int quantity;
    double price;
};
void addItem() {
    Item item;
    cout << "Enter item name: ";
    cin.ignore();
    cin.getline(item.name, 50);
    cout << "Enter quantity: ";
    cin >> item.quantity;
    cout << "Enter price: ";
    cin >> item.price;
 ofstream fout(FILE_NAME, ios::app);
    if (!fout) {
        cerr << "Error opening file for writing.\n";
        return;
    }
 fout << item.name << " " << item.quantity << " " << item.price << "\n";
    fout.close();
    cout << "Item added successfully.\n";
}
void viewInventory() {
    ifstream fin(FILE_NAME);
    if (!fin) {
        cerr << "Error opening file for reading.\n";
        return;
    }
 Item item;
    cout << "\nInventory List:\n";
    cout << left << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) <<
"Price\n";
    cout << "-------------------------------------------\n";
 while (fin >> item.name >> item.quantity >> item.price) {
        cout << left << setw(20) << item.name
             << setw(10) << item.quantity
             << setw(10) << fixed << setprecision(2) << item.price << "\n";
    }
 fin.close();
}
void searchInFile() {
    char searchName[50];
    cout << "Enter item name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);
 ifstream fin(FILE_NAME);
    if (!fin) {
        cerr << "Error opening file for reading.\n";
        return;
    }
 Item item;
    bool found = false;
    while (fin >> item.name >> item.quantity >> item.price) {
        if (strcmp(item.name, searchName) == 0) {
            cout << "\nItem Found:\n";
            cout << "Name: " << item.name << "\n";
            cout << "Quantity: " << item.quantity << "\n";
            cout << "Price: $" << item.price << "\n";
            found = true;
            break;
        }
    }
if (!found)
        cout << "Item not found.\n";
 fin.close();
}
void loadIntoMemoryAndSearch() {
    ifstream fin(FILE_NAME);
    if (!fin) {
        cerr << "Error opening file for reading.\n";
        return;
    }
const int INIT_CAPACITY = 10;
    Item* items = new Item[INIT_CAPACITY];
    int capacity = INIT_CAPACITY;
    int count = 0;
Item temp;
    while (fin >> temp.name >> temp.quantity >> temp.price) {
        if (count == capacity) {
            capacity *= 2;
            Item* newItems = new Item[capacity];
            for (int i = 0; i < count; ++i) {
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
        }
        items[count++] = temp;
    fin.close();
char searchName[50];
    cout << "Enter item name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);
 bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strcmp(items[i].name, searchName) == 0) {
            cout << "\nItem Found:\n";
            cout << "Name: " << items[i].name << "\n";
            cout << "Quantity: " << items[i].quantity << "\n";
            cout << "Price: $" << items[i].price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Item not found.\n";

    delete[] items;
}

int main()
 {
    int choice;
    do
        {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Search (File-Based)\n";
        cout << "4. Search (Memory-Based)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: searchInFile(); break;
            case 4: loadIntoMemoryAndSearch(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 5);
    cout<<"24CE036_Bristi"<<endl;
 return 0;
 }
