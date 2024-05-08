#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=10000000;

vector<int> SPF(MAX+1);

vector<long long> APS(MAX+1);

void sito()
{
    for(int i=2;i<=MAX;i++)
    {
        SPF[i]=i;
    }
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (SPF[i] == i) 
        {
            for (int j = i * i; j <= MAX; j += i) 
            {
                if (SPF[j] == j) SPF[j] = i;
            }
        }
    }
 }

void babluSequence()
{
    APS[0]=0;
    APS[1]=0;
    for(int i=2; i<=MAX; i++)
    {
        APS[i]=APS[i-1]+SPF[i];
    }
}

int main() {
    sito();
    babluSequence();
    int T;
    cin>>T;
    while(T--)
    {
        int k;
        cin>>k;
        cout<<APS[k]<<'\n';
    }
    return 0;
}