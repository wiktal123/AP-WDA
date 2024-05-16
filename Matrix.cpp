#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

//global variables
int mn= INT_MAX;
bool visited[100001];
// main graph should be here also !!!!!!!!!!


bool disconnect(int node, vector<pair<int,int>> graph[], vector<bool> arrayMachines) //graph traversing
{

    /*
    Here must be implemented graph traversing for finding minimal cost of deleting road between two machines
        -forwarding current minimal cost with road details
        -returning as soon as machine is found
        -deleting minimal cost edge (road) from the graph
    */ 
    
    if(arrayMachines[node]) return true;
    visited[node]=true;
    for(auto neighbour: graph[node])
    {
        if(!visited[neighbour.first])
        {

        }
    }
    return false;
}

// void dfs(int x, vector<pair<int, int>> streets[]){
//     vis[x]=true;
//     for(auto neighbour : streets[x]){
//         if(!vis[neighbour.first]){
//             current+=neighbour.second;
//             //cout<<x<<' '<<neighbour.first<<endl;
//             dfs(neighbour.first, streets);
//             current-=neighbour.second;
//         }
//     }
//     if(current>mx){
//         mx=current;
//         //cout<<mx<<' '<<x<<endl;
//     }
// }

// int calculate_distance(int start, int target, int size) {
//     vector<int> dist(size * size, INT_MAX);
//     queue<int> q;
//     dist[start] = 0;
//     q.push(start);

//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();

//         for (int v : graph[u]) {
//             if (dist[u] + 1 < dist[v]) {
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//                 if (v == target) return dist[v];
//             }
//         }
//     }

//     return dist[target] == INT_MAX ? -1 : dist[target];
// }

int minTime(vector<vector<int>> roads, vector<int> machines) // main algorythm
{
    /*
    To implement:
        -sorting roads vector by time cost
        -adding edges (roads) to the graph in ascending order
    */

    //crucial variables
    int res=0;
    int size= roads.size()+1;
    vector<pair<int,int>> graph[size];
    vector<bool> arrayMachines(size,false);

    for(auto machine : machines) // creating machines array
    {
        arrayMachines[machine]=true;
    }

    for(auto road: roads) // creating graph, road by road
    {
        graph[road[0]].push_back({road[1],road[2]});
        graph[road[1]].push_back({road[0],road[2]});
        if(arrayMachines[road[0]])
        {
            memset(visited,false,sizeof(visited)); // resetting global variables
            mn=INT_MAX;

            if(disconnect(road[0],graph, arrayMachines)) res+=mn; // checking for possible connection and deleting it
        } 
        else if(arrayMachines[road[1]])
        {
            memset(visited,false,sizeof(visited)); // resetting global variables
            mn=INT_MAX;

            if(disconnect(road[1],graph, arrayMachines)) res+=mn; // checking for possible connection and deleting it
        }
                            
    }
    return res;
}

int main()
{
    int nodes, machines, input;
    cin>>nodes>>machines;
    input=nodes-1;


    while(input--)
    {
        int a, b, t;
        cin>>a>>b>>t;
    }
    return 0;
}