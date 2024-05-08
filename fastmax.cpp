#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> heap;
vector<pair<int, int>> range;
int l=1;
int mx=0;

void add_ranges(int l)
{
    for (int i= 0; i<l; i++){
        pair<int, int> temp;
        if(i>=l/2)
        {
            temp.first=i-l/2, temp.second=i-l/2;
            range.push_back(temp);
        }
        else
        {
            temp.first=0,temp.second=0;
            range.push_back(temp);
        }
    }
    for (int i= l/2; i<l; i++){
        int help=i;
        while(help>1)
        {
            help/=2;
            pair<int, int> temp;
            temp.first=range[help*2].first, temp.second=range[help*2+1].second;
            range[help]=temp;
        }
    }
}

void create_heap(int N)
{
    while(l<N){l*=2;}
    l*=2;
    for(int i = 0; i<l; i++)
    {
        heap.push_back(0);
    }
    add_ranges(l);
}

void modify_heap(int a, int b)
{   
    int k=l/2+a;
    heap[k]=b;
    while(k>1)
    {
        k/=2;
        heap[k]=max(heap[k*2],heap[k*2+1]);
    }
}

void read_max(int level, int a, int b)
{
    int l=range[level].first,r=range[level].second;
    if(l>=a&&r<=b)
    {
        mx=max(mx,heap[level]);
        return;
    }
    else if(a>=range[level*2+1].first && b<=range[level*2+1].second){read_max(level*2+1,a,b);}
    else if(a>=range[level*2].first &&b<=range[level*2].second){read_max(level*2,a,b);}
    else
    {
        read_max(level*2,a,range[level*2].second);
        read_max(level*2+1,range[level*2+1].first,b);
    }

}
int main() {
    int N,R;
    cin>>N>>R;
    create_heap(N);
    while(R-->0)
    {
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1)
        {
            modify_heap(a,b);
        }
        else
        {
            mx=0;
            read_max(1,a,b);
            cout<<mx<<endl;
        }
    }
    return 0;
}
