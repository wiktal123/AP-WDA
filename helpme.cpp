////#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
unordered_map<int, vector<int>> graph;

void addEdge(pair<int,int> edge)
{
    int u= edge.first,v=edge.second;
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void delEdge(pair<int, int> edge)
{
    int u = edge.first, v = edge.second;
    for(int i =0; i<graph[u].size();i++)
    {
        if(graph[u][i]==v)
        {
            graph[u].erase(graph[u].begin()+i);
        }
    }
    for(int i =0; i<graph[v].size();i++)
    {
        if(graph[v][i]==u)
        {
             graph[v].erase(graph[v].begin()+i);
        }   
    }
}

bool is_cycle(pair<int,int> edge)
{
    int k=edge.first;
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    q.push({k,-1});
    visited.insert(k);
    while(!q.empty())
    {
        int cur=q.front().first;
        int par=q.front().second;
        q.pop();
        for(int neighbour: graph[cur])
        {
            if(!visited.count(neighbour))
            {
                visited.insert(neighbour);
                q.push({neighbour,cur});
            } else if(neighbour != par) return true;
        }
    }
    return false;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    priority_queue<pair<int,int>> gSorted;
    int sum=0;
    for(int i =0;i< (int)g_weight.size(); i++)
    {
        gSorted.push({-g_weight[i],i});
    }
    
    while(!gSorted.empty())
    {
        int currentWeight = -gSorted.top().first;
        int currentIndex = gSorted.top().second;
        gSorted.pop();
        addEdge({g_from[currentIndex],g_to[currentIndex]});
        if(is_cycle({g_from[currentIndex]-1,g_to[currentIndex]-1}))
        {
            delEdge({g_from[currentIndex],g_to[currentIndex]});
        }
        else
        {
            sum+=currentWeight;
        }
    }
    return sum;
}