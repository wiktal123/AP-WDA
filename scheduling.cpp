#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> A;

int main()
{
    int tasks;
    cin>>tasks;
    int len=tasks;
    while(tasks-->0)
    {
        long long k;
        cin>>k;
        A.push_back(k);
    }
    for(int i=0; i<len; i++)
    {
        long long sum=A[i];
        for(int j=0;j<len;j++)
        {
            if(j==i){continue;}
            else if(j>i)
            {
                if(A[j]>=A[i])
                {
                    sum+=A[j]-1;
                } else
                {
                    sum+=A[j];
                }
            } else
            {
                if(A[j]<=A[i])
                {
                    sum+=A[j];
                } else
                {
                    sum+=A[j]-A[i];
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}