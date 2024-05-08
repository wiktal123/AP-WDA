#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    int A[26]={0};
    for(int i=0; i< (int)s.size(); i++)
    {
        A[((int)s[i]-97)]++;
    }
    int q=0;
    int k=0;
    for(int i=0 ; i<26; i++)
    {
        if( A[i]==0 ) continue;
        if( A[i]>0 && k==0 ) k=A[i];
        if( abs( k-A[i]) >=2 && A[i]!=1) return "NO";
        if( abs( k-A[i] )==1 || A[i]==1) q++;
        if( q>1 ) return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
