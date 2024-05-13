#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool is_palindrome(string a)
{
    int l= a.size()-1;
    for(int i =0; i <l; i++)
    {
        if(a[i]!=a[l-i]) return false;
    }
    return true;
}

bool is_valid(string line)
{
    int len= line.length()-1;
    if((len+1)%2!=0 ) return false;
    if(is_palindrome(line)) return true;
    while(int i =0 < len-1)
    {
        bool is_G=false;
        string cur;
        for(int j =i; j<len; ++j)
        {
            cur+=line[j];
            cout<<j<<" cur "<< cur<<'\n';
            //if((j-i)%2!=0 || (j-i)==0) continue;
            if(is_palindrome(cur))
            {
                i=j+1;
                is_G=true;
                //cout<<"jp100"<<cur;
                if(j==len-1) return true;
                break;
            }
        }
        if(!is_G) return false;
        if(is_G) cout<<line<<'\n';
    }
    return false;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        string line;
        cin>>line;
        cout<<line<<'\n';
        if(is_valid(line)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n'; 
    }
    return 0;
}