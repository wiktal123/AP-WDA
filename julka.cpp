#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// NP 11   2- 
// P 12
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

string divByTwo(string a)
{
    string res;
    int reminder=0;
    bool leadingZero=true;
    for(char digit : a)
    {
        int curdigit= digit-'0';
        int temp= (curdigit+reminder*10)/2;
        reminder = (curdigit+reminder*10)%2;
        if(!leadingZero|| temp>0)
        {
            res.push_back(temp+'0');
            leadingZero=false;
        }
    }
    if(res.empty()) res.push_back('0');
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string apples, diff;
    string klaudia, natalia;
    while(cin>>apples>>diff)
    {
        klaudia=divByTwo(add(apples,diff));
        natalia=divByTwo(substract(apples,diff));
    }
    cout<<klaudia<<'\n'<<natalia<<'\n';
    return 0;
}