#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
int countWordsInLine(const string& line) {
    int count = 0;
    bool inWord = false;
    for (char ch : line) {
        if (isalnum(ch)) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        }
        else {
            inWord = false;
        }
    }
    return count;
}
void analyzeWithSTL(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "[Error] Could not open file: " << filename << "\n";
        return;
    }

    vector<string> lines;
    int totalChars = 0;
    int totalWords = 0;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
        totalChars += line.length() + 1;
        totalWords += countWordsInLine(line);
    }
   file.close();
   cout << "\n[STL Analysis Results]\n";
    cout << "Total Lines: " << lines.size() << "\n";
    cout << "Total Words: " << totalWords << "\n";
    cout << "Total Characters (incl. newline): " << totalChars << "\n";
}
void analyzeWithoutSTL(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "[Error] Could not open file: " << filename << "\n";
        return;
    }
const int INIT_CAPACITY = 10;
    char** lines = new char*[INIT_CAPACITY];
    int capacity = INIT_CAPACITY;
    int lineCount = 0;
    int totalChars = 0;
    int totalWords = 0;
string line;
    while (getline(file, line)) {
        if (lineCount == capacity) {
            capacity *= 2;
            char** newLines = new char*[capacity];
            for (int i = 0; i < lineCount; ++i) {
                newLines[i] = lines[i];
            }
            delete[] lines;
            lines = newLines;
        }
   char* cLine = new char[line.length() + 1];
        strcpy(cLine, line.c_str());
        lines[lineCount++] = cLine;
     totalChars += line.length() + 1;
        totalWords += countWordsInLine(line);
    }
   file.close();

    cout << "\n[Non-STL Analysis Results]\n";
    cout << "Total Lines: " << lineCount << "\n";
    cout << "Total Words: " << totalWords << "\n";
    cout << "Total Characters (incl. newline): " << totalChars << "\n";
   for (int i = 0; i < lineCount; ++i) {
        delete[] lines[i];
    }
    delete[] lines;
}
int main() {
    string filename;
    cout << "Enter the filename to process: ";
    getline(cin, filename);
  int choice;
    cout << "\nSelect processing method:\n1. STL\n2. Non-STL (manualmemory)\nEnter choice (1/2): ";
    cin >> choice;
 if (choice == 1) {
        analyzeWithSTL(filename);
    }
    else if (choice == 2) {
        analyzeWithoutSTL(filename);
    }
     else {
cerr << "[Error] Invalid choice.\n";
}
cout<<"24CE036_Bristi"<<endl;
return 0;
}
