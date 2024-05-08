#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool vis[50001]={false};
int mx=0;
int current=0;

void dfs(int x, vector<pair<int, int>> streets[]){
    vis[x]=true;
    for(auto neighbour : streets[x]){
        if(!vis[neighbour.first]){
            current+=neighbour.second;
            //cout<<x<<' '<<neighbour.first<<endl;
            dfs(neighbour.first, streets);
            current-=neighbour.second;
        }
    }
    if(current>mx){
        mx=current;
        //cout<<mx<<' '<<x<<endl;
    }
}

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int places;
        cin>>places;
        int k=places;
        k--;
        vector<pair<int,int>> streets[places+1];
        while(k-->0){
            int a,b,n;
            cin>>a>>b>>n;
            streets[a].push_back(make_pair(b,n));
            streets[b].push_back(make_pair(a,n));
        }
        int finalLength=0;
        for(int i = 1; i < places+1; ++i){ // i = idOfPlace - 1
            for(int i=0; i<50001;i++){
                vis[i]=false;
            }
            mx = 0;
            current=0;
            dfs(i , streets);
            if(finalLength < mx){
                finalLength= mx;
            }
        }
        cout<<finalLength<<endl;
    }
    return 0;
}