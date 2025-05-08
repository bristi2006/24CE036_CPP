#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displaySequence(const vector<int>& sequence) {
    for (auto it = sequence.begin(); it != sequence.end(); ++it) {

        cout << *it << " ";
    }
    cout << endl;
}

void reverseWithIterators(vector<int>& sequence) {
    auto begin = sequence.begin();
    auto end = sequence.end();
    --end;

    while (begin < end) {
        iter_swap(begin, end);
        ++begin;
        --end;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    vector<int> sequence(n);

    cout << "Enter " << n << " integers:\n";
    for (auto& num : sequence) {
        cin >> num;
    }

    cout << "\nOriginal Sequence:\n";
    displaySequence(sequence);

    vector<int> reversed1 = sequence;
    reverse(reversed1.begin(), reversed1.end());
    cout << "\nReversed using std::reverse():\n";
    displaySequence(reversed1);

    vector<int> reversed2 = sequence;
    reverseWithIterators(reversed2);
    cout << "\nReversed using manual iterator swap:\n";
    displaySequence(reversed2);
    cout<<"24CE036_Bristi"<<endl;
    return 0;
}

