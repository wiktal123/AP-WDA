#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <cstring>
using namespace std;

int dijkstra(int start, int target, vector<pair<int, int>> graph[]) {
    vector<int> dist(101, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == target) return d;

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.second;
            int weight = edge.first;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[target] == INT_MAX) {
        return -1; 
    }

    return dist[target];
}


bool is_in_map(string x, map<string,int> locationMap)
{
    if(locationMap.count(x)) return true;
    else return false;
}

void add_road(string road, int A, int B, vector<pair<int,int>> graph[])
{
    int len= stoi(road.substr(2,road.size()-3));
    if(road[0]=='<')
    {
        graph[B].push_back({len,A});
        // cout<<B<<' '<<A<<' '<<graph[B][A]<<'\n';
    }
    if(road[road.size()-1]=='>') 
    {
        graph[A].push_back({len,B});
        // cout<<A<<' '<<B<<' '<<graph[A][B]<<'\n';
    }
}

int main() {

    int testNo,cities,cars,roads;
    testNo=0;

    while(cin>>cities>>cars>>roads && cities)
    {
        testNo++;

        map<string,int> locationMap;
        vector<int> brokenCars;
        vector<pair<int,int>> graph[cities+1];
        string companyGarage;
        cin>>companyGarage;

        int i=0;
        locationMap[companyGarage]=i++;

        while(cars--)        
        {
            string brokeLoc;
            cin>>brokeLoc;
            if(!is_in_map(brokeLoc,locationMap)) locationMap[brokeLoc]=i++;
            brokenCars.push_back(locationMap[brokeLoc]);
        }
        
        while(roads--)
        {
            string A, road, B;
            cin>>A>>road>>B;
            if(!is_in_map(A,locationMap)) locationMap[A]=i++;
            if(!is_in_map(B,locationMap)) locationMap[B]=i++;
            add_road(road,locationMap[A],locationMap[B], graph);
        }

        int res=0;

        for(int c : brokenCars)
        {
            res+= dijkstra(0,c,graph) + dijkstra(c,0,graph);
        }

        cout<<testNo<<". "<<res<<'\n';
    }
    return 0;
}

