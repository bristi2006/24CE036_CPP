#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
T findMax(const vector<T>& vec) {
if (vec.empty()) {
        throw runtime_error("Vector is empty.");
    }
    T maxVal = vec[0];
    for (const T& element : vec) {
        if (element > maxVal) {
            maxVal = element;
        }
    }
    return maxVal;
}
template <typename T>
void reverseVector(vector<T>& vec) {
    reverse(vec.begin(), vec.end());
}
template <typename T>
void displayVector(const vector<T>& vec) {
    for (const T& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}
int main() {
    int size;
    cout << "Enter number of integers: ";
    cin >> size;
    vector<int> intVec;
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        intVec.push_back(num);
    }
    cout << "\nInteger Vector:\n";
    displayVector(intVec);
    cout << "Maximum: " << findMax(intVec) << endl;
    reverseVector(intVec);
    cout << "Reversed:\n";
    displayVector(intVec);

 cout << "\nEnter number of doubles: ";
    cin >> size;
    vector<double> doubleVec;
    cout << "Enter " << size << " double values:\n";
    for (int i = 0; i < size; ++i) {
        double num;

        cin >> num;
        doubleVec.push_back(num);
    }
  cout << "\nDouble Vector:\n";
    displayVector(doubleVec);
    cout << "Maximum: " << findMax(doubleVec) << endl;
    reverseVector(doubleVec);
    cout << "Reversed:\n";
    displayVector(doubleVec);

   cout << "\nEnter number of characters: ";
    cin >> size;
    vector<char> charVec;
    cout << "Enter " << size << " characters:\n";
    for (int i = 0; i < size; ++i) {
        char ch;
        cin >> ch;
        charVec.push_back(ch);
    }
   cout << "\nCharacter Vector:\n";
    displayVector(charVec);
    cout << "Maximum (largest character): " << findMax(charVec) << endl;
    reverseVector(charVec);

cout << "Reversed:\n";
displayVector(charVec);
return 0;
}
