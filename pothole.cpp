#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int mx;

bool bfs(int start, int n, vector<pair<int,int>> graph[],int distances[])
{
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int distance=0;
    queue<pair<int,int>> q;
    visited[start] = true;
    q.push({start,distance});
    while (!q.empty())
    {
        int current = q.front().first;
        distances[current]=q.front().second;
        q.pop();
        
        for (auto neighbour : graph[current])
        {
            if (!visited[neighbour.first]&& !neighbour.second)
            {
                visited[neighbour.first]=true;
                q.push({neighbour.first,distances[current]+1});
            }
        }
    }
    if(visited[n]) return true;
    else return false;
}

void dfs(int x, int end, vector<pair<int,int>> graph[], int distances[])
{
    if(x==end)
    {
        mx++;
    }
    for(int i =0; i<graph[x].size();i++)
    {
        pair<int, int> neighbour= graph[x][i];
        if(distances[neighbour.first]==distances[x]+1 && !neighbour.second)
        {
            graph[x][i].second=1;
            dfs(neighbour.first, end, graph, distances);
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int n;
        cin>>n;
        int distances[n];
        memset(distances, 0, n * sizeof(int)); 
        vector<pair<int,int>> graph[n+1];
        for(int i = 1; i<= n; i++)
        {
            int len;
            cin>> len;
            while(len-->0)
            {
                int a; cin>>a;
                graph[i].push_back({a,0});
            }
            
        }
        int res=0;
        while(bfs(1,n,graph, distances))
        {
            mx=0;
            dfs(1, n, graph, distances);
            if(mx>res) res=mx;
            memset(distances, 0, n * sizeof(int));
        }
        cout<<res<<'\n';
    }
    return 0;
}