#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> parent(100001,-1), comSize(100001,1);

int find_root(int x)
{
    if(parent[x]==-1)
    {
        return x;
    }
    else return find_root(parent[x]);
}

void merge_coms(int i, int j)
{
    int root_i=find_root(i);
    int root_j=find_root(j);
    if(root_i!=root_j) 
    {
        parent[root_j]=root_i;
        comSize[root_i]+=comSize[root_j];
    }
}

int main() {
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        char order;
        cin>>order;
        if(order=='Q')
        {
            int k;
            cin>>k;
            int size;
            size=comSize[find_root(k)];
            cout<<size<<'\n';
        } else
        {
            int i,j;
            cin>>i>>j;
            merge_coms(i,j);
        }
    }
    return 0;
}
