#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string toLower(const string& word) {
string lowerWord = word;
transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    return lowerWord;
}
int main() {
    string text;
    cout << "Enter a sentence:\n";
    getline(cin, text);

    map<string, int> wordFrequency;
 istringstream iss(text);
    string word;
    while (iss >> word) {

        if (ispunct(word.back())) word.pop_back();

        word = toLower(word);
        ++wordFrequency[word];
    }
    cout << "\nWord Frequency:\n";
    for (auto it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    cout<<"24CE036_Bristi"<<endl;
return 0;
}
