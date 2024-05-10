#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=1000000;

vector<int> LPS(MAX+1);

void lps(int l, string p)
{
    for(int i =0 ; i<l; i++)
    {
        LPS[i]=0;
    }
    int i=1, j=0;
    while(i<l)
    {
        if(p[i]==p[j])
        {
            j++;
            LPS[i]=j;
            i++;
        }
        else if(j>0)
        {
            j=LPS[j-1];
        }
        else
        {
            LPS[i]=0;
            i++;
        }
    }
    return;
}

void kmp(int lp, string p, string t)
{
    int lt= t.length();
    if(lp>lt) return;
    if(lp==lt)
    {
        if(p==t)
        {
            cout<<0<<'\n';
            return;
        }
        else return;
    }
    if(lp==0)
    {
        cout<<0<<'\n';
        return;
    }
    lps(lp,p);
    int i =0, j=0;
    while(i<lt && j<lp)
    {
        if(p[j]==t[i]) 
        {
            i++;
            j++;
        }
        if(j==lp)
        {
            cout<<i-j<<'\n';
            j= LPS[j-1];
        }
        else if(j>0) j=LPS[j-1];
        else i++;
    }
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int l;
        cin>>l;
        string p,t;
        cin>>p>>t;
        kmp(l,p,t);
    }
    return 0;
}