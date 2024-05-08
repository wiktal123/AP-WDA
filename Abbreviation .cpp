#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int is_good(char a, char b){
    if((int)a<=90&&a==b){
        return 1;
    }
    if((int)a>=97&&((char)((int)a-32)==b)){
        return 1;
    }
    return 0;
}

int can_be(string a, string b){
    int lenA= a.length(), lenB= b.length();
    int upperA[26]={0}, lowerA[26]={0}, B[26]={0};
    for(int i=0;i<lenA;i++){
        if(65<=(int)a[i]&&(int)a[i]<=90){
            upperA[(int)a[i]-65]+=1;
        }
        else{
            lowerA[(int)a[i]-97]+=1;
        }
    }
    for(int i=0;i<lenB;i++){
        B[(int)b[i]-65]+=1;        
    }
    int res=1;
    for(int i=0;i<26;i++){
        if(upperA[i]>B[i]){
            res=0;
            return res;
        }
        if(lowerA[i]+upperA[i]<B[i]){
            res=0;
            return res;
        }
    }
    return res;
}

string abbreviation(string a, string b) {
    int lenA= a.length(), lenB= b.length();
    if(can_be(a,b)==0){
        return "NO";
    }
    else{
        a='0'+a;
        b='0'+b;
        int dp[lenB+1][lenA+1];
        dp[0][0]=1;
        for(int i=0;i<lenB+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<lenA+1;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<lenB+1;i++){
            for(int j=1;j<lenA+1;j++){
                int is_true=1;
                if(is_good(a[j],b[i])==1&&is_true==1&&dp[i-1][j-1]==1){
                    dp[i][j]=1;
                }
                else{
                    if(dp[i][j-1]==1&&(int)a[j]>=97&&is_true==1){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                        is_true=0;
                    }
                }
            }
        }
        if(dp[lenB][lenA]==1){
            return "YES";
        }
        else{
            return "NO";
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

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
