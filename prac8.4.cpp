#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
int n;

    cout << "Enter number of students: ";
    cin >> n;
     vector<pair<string, int>> students;
 for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score of " << name << ": ";
        cin >> score;
        students.push_back(make_pair(name, score));
    }
    sort(students.begin(), students.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
     cout << "\nSorted Student List (by score):\n";
    cout << "-------------------------------\n";
    for (const auto& student : students) {
        cout << "Name: " << student.first << ", Score: " << student.second << endl;
    }
    cout<<"24CE036_Bristi"<<endl;
return 0;
}
