#include <iostream>
using namespace std;
class BaseWrong {
public:
    BaseWrong() {
        cout << "BaseWrong Constructor\n";
    }
    ~BaseWrong() {
        cout << "BaseWrong Destructor\n";
    }
};
class BaseCorrect {
public:
    BaseCorrect() {
        cout << "BaseCorrect Constructor\n";
    }
    virtual ~BaseCorrect() {
        cout << "BaseCorrect Destructor\n";
    }
};
class Derived : public BaseWrong, public BaseCorrect {
private:
    int* data;
public:
    Derived() {
        int val;
        cout << "Enter a value to allocate in Derived: ";

        cin >> val;
        data = new int(val);
        cout << "Derived Constructor - Allocated " << *data << endl;
    }
 ~Derived() {
        cout << "Derived Destructor - Deleting allocated memory\n";
        delete data;
  }
};
int main() {
    cout << "Demonstrating WITHOUT Virtual Destructor:\n";
    BaseWrong* pWrong = new Derived();
   cout << "Now deleting pWrong (BaseWrong* pointing to Derived)...\n";
    delete pWrong;

  cout << "\n---------------------------------------\n";
    cout << "Demonstrating WITH Virtual Destructor:\n";
    BaseCorrect* pCorrect = new Derived();

cout << "Now deleting pCorrect (BaseCorrect* pointing to Derived)...\n";
    delete pCorrect;
 return 0;
}
