#include <iostream>
#include <string>
using namespace std;
int superDigitHelper(long long num) {
    if (num < 10) {
        return num;
    }
  long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
  return superDigitHelper(sum);
}
int superDigit(string n, int k) {
    long long initialSum = 0;
    for (char c : n) {
        initialSum += c - '0';
    }
    initialSum *= k;
    return superDigitHelper(initialSum);
}

int main() {
    string n;
    int k;
   cout << "Enter n and k separated by space: ";
    cin >> n >> k;
int result = superDigit(n, k);
    cout << result << endl;
   return 0;
}
