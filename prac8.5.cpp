#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void addFolder(map<string, vector<string>>& directory) {
    string folderName;
    cout << "Enter folder name: ";
    cin >> folderName;

 if (directory.find(folderName) != directory.end()) {
        cout << "Folder already exists.\n";
    } else {
        directory[folderName] = {};
        cout << "Folder '" << folderName << "' added successfully.\n";
    }
}
void addFilesToFolder(map<string, vector<string>>& directory) {
    string folderName;
    cout << "Enter folder name to add files: ";
    cin >> folderName;
if (directory.find(folderName) == directory.end()) {
        cout << "Folder not found. Please add the folder first.\n";
        return;
    }
int numFiles;
    cout << "Enter the number of files to add: ";
    cin >> numFiles;

    for (int i = 0; i < numFiles; ++i) {
        string fileName;
        cout << "Enter file name: ";
        cin >> fileName;
        directory[folderName].push_back(fileName);
    }
    cout << numFiles << " file(s) added to folder '" << folderName << "'.\n";
}
void displayDirectory(const map<string, vector<string>>& directory) {
    cout << "\nDisplaying all folders and their files:\n";
    for (auto it = directory.begin(); it != directory.end(); ++it) {
        cout << "Folder: " << it->first << "\nFiles: ";
        for (const string& file : it->second) {
            cout << file << " ";
        }
        cout << endl;
    }
}
int main() {
    map<string, vector<string>> directory;
    int choice;
 do {
        cout << "\nDirectory Management System\n";
        cout << "1. Add Folder\n";
        cout << "2. Add Files to Folder\n";
        cout << "3. Display All Folders and Files\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFolder(directory);
                break;
            case 2:
                addFilesToFolder(directory);
                break;
            case 3:
                displayDirectory(directory);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }

} while (choice != 4);
         cout<<"24CE036_Bristi"<<endl;
return 0;
}
