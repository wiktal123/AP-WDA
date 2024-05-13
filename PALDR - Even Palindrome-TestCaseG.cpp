#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

bool isValid(string line) {
    if (!line.empty() && line.back() == '\r') {
        line.pop_back();
    }

    int len = line.length();
    if (len % 2 != 0) return false; 

    for (int start = 0; start < len; start += 2) {
        if (!isPalindrome(line.substr(start, 2))) return false;
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 
    while (T--) {
        string line;
        getline(cin, line); 
        if (isValid(line))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
