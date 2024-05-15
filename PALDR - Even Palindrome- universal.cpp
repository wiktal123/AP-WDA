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
    if(line.length()==2 && !isPalindrome(line)) return false;
    int len = line.length();
    if (len % 2 != 0) return false; 

    for (int start = 0; start < len-2; start += 2) {
        bool is_g=false;
        for(int end= start+2; end<len; end+=2)
        {
            if (isPalindrome(line.substr(start, end)))
            {
                is_g=true;
                start=end+1;
                break;
            }
        }
        if(!is_g) return false;
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
