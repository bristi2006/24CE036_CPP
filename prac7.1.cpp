#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
struct WordEntry {
    char* word;
    int count;
};
char* toLowerCase(const char* str) {
    size_t len = strlen(str);
    char* lowerStr = new char[len + 1];
    for (size_t i = 0; i < len; ++i) {
        lowerStr[i] = tolower(str[i]);
    }
    lowerStr[len] = '\0';
    return lowerStr;
}
bool isAlphaNum(char c) {
    return isalnum(static_cast<unsigned char>(c));
}
char* extractWord(const char* src, int start, int end) {
    int len = end - start;
    char* word = new char[len + 1];
    strncpy(word, src + start, len);
    word[len] = '\0';
    return word;
}
int main() {
    const int INITIAL_CAPACITY = 10;
    WordEntry* wordList = new WordEntry[INITIAL_CAPACITY];
    int capacity = INITIAL_CAPACITY;
    int size = 0;
 string inputLine;
    cout << "Enter a paragraph: ";
    getline(cin, inputLine);
const char* text = inputLine.c_str();
    int len = strlen(text);
    int i = 0;
 while (i < len) {
        while (i < len && !isAlphaNum(text[i])) i++;
        int start = i;
        while (i < len && isAlphaNum(text[i])) i++;
        int end = i;
  if (end > start) {
            char* rawWord = extractWord(text, start, end);
            char* word = toLowerCase(rawWord);
            delete[] rawWord;
  bool found = false;
            for (int j = 0; j < size; ++j) {

                if (strcmp(wordList[j].word, word) == 0) {
                    wordList[j].count++;
                    found = true;
                    break;
                }
            }
               if (!found) {
                if (size == capacity) {
                    capacity *= 2;
                    WordEntry* newList = new WordEntry[capacity];
                    for (int k = 0; k < size; ++k) {
                        newList[k] = wordList[k];
                    }
                    delete[] wordList;
                    wordList = newList;
                }
                wordList[size].word = word;
                wordList[size].count = 1;
                size++;
            }
            else {
                delete[] word;
            }
        }
}
cout << "\nWord Frequencies:\n";
for (int i = 0; i < size; ++i) {
cout << wordList[i].word << ": " << wordList[i].count << "\n";
delete[] wordList[i].word;
}
delete[] wordList;
cout<<"24CE036_Bristi"<<endl;
return 0;
}
