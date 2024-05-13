#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool is_match(char a, char b) {
    return (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')');
}

bool is_open(char a) {
    return a == '{' || a == '(' || a == '[';
}

string isBalanced(string s) {
    int l = s.length();
    if (l % 2 != 0) return "NO";  
    vector<char> stack;  

    for (char c : s) {
        if (is_open(c)) {
            stack.push_back(c);
        } else {
            if (stack.empty() || !is_match(stack.back(), c)) {
                return "NO";
            }
            stack.pop_back();
        }
    }

    return stack.empty() ? "YES" : "NO";  
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
