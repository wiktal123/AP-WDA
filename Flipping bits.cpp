#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

string dec_to_bin(long a){
    string k;
    while(a>0){
        if(a%2==0){
            k+='0';
        }
        else{
            k+='1';
        }
        a=a/2;
    }
    reverse(k.begin(),k.end());
    return k;
}

long bin_to_dec(string a){
    long res=0, k=1;
    int l=(int)a.length()-1;
    while(l>=0){
        res+=((int)a[l]-48)*abs(k);
        k*=2;
        l-=1;
    }
    return res;
}


long flippingBits(long n) {
    string a=dec_to_bin(n);
    int len=(int)a.length();
    string str;
    for(int i=0;i<32-len;i++){
        str+='0';
    }
    str+=a;
    string res;
    for(int i=0;i<32;i++){
        if(str[i]=='0'){
            res+='1';
        }
        if(str[i]=='1'){
            res+='0';
        }
    }
    cout<<res<<endl;
    long out;
    out=bin_to_dec(res);
    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        long result = flippingBits(n);

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
