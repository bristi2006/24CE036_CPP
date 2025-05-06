#include <iostream>
using namespace std;
class DynamicArray {
private:

    int* arr;
    int size;
public:
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }
    ~DynamicArray() {
        delete[] arr;
    }
    void insertAtEnd(int value) {
        int* newArr = new int[size + 1];
  for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        newArr[size] = value;
        delete[] arr;
         arr = newArr;
        size++;
    }
    void deleteAtPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";

            return;
        }
        int* newArr = new int[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i == pos) continue;
            newArr[j++] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size--;
    }
    void printArray() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray da;
    int choice, value, pos;
do {
        cout << "\n1. Insert at End\n2. Delete at Position\n3. Print Array\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                da.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter position to delete (starting from 0): ";
                cin >> pos;
                da.deleteAtPosition(pos);
                break;
            case 3:
                da.printArray();
                break;
            case 4:
                cout << "Exiting...\n";

                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    cout<<"24ce036_Bristi"<<endl;
   return 0;
}
