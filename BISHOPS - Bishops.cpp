#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b)
{
    string res;
    int carry=0;

    int maxLength = max(a.length(), b.length());
    a = string(maxLength - a.length(), '0') + a;
    b = string(maxLength - b.length(), '0') + b;

    for(int i= maxLength - 1; i>=0; --i)
    {
        int temp=(a[i]-'0')+(b[i]-'0')+carry;
        res= to_string(temp%10)+res;
        carry=temp/10;
    }
    if(carry>0) res= to_string(carry)+res;
    return res;
}

string substract(string a, string b)
{
    string res;
    int borrow=0;

    int maxLength = max(a.length(), b.length());
    a = string(maxLength - a.length(), '0') + a;
    b = string(maxLength - b.length(), '0') + b;

    for(int i= maxLength-1; i>=0;--i)
    {
        int temp = (a[i]-'0') - (b[i]-'0') - borrow;
        if(temp<0)
        {
            temp+=10;
            borrow=1;
        } else
        {
            borrow=0;
        }
        res = to_string(temp)+res;
    }
    res.erase(0, min(res.find_first_not_of('0'), res.size() - 1));
    return res;
}

int main() {
    string N;
    while(cin>>N)
    {
        if(N=="1") cout<<"1 \n";
        else cout<<add(N,substract(N,"2"))<<'\n';
    }
    return 0;
}