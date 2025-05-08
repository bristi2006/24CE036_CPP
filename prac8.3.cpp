#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> inputList(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> inputList[i];
    }
    set<int> uniqueSet(inputList.begin(), inputList.end());
    cout << "\nUnique elements (sorted):\n";
    for (auto it = uniqueSet.begin(); it != uniqueSet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int> uniqueVector(uniqueSet.begin(), uniqueSet.end());
    cout << "\nUnique elements in vector form:\n";
    for (int num : uniqueVector) {
        cout << num << " ";
    }
    cout << endl;
    cout<<"24CE036_Bristi"<<endl;
 return 0;
}
