#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> graph;

int calculate_node(int r, int c, int size)
{
    return r* size + c;
}

void init_graph(vector<string> grid, int size)
{
    graph.resize(size * size);
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    for(int i =0; i < size; i++)
    {
        for(int j=0; j < size; j++)
        {
            if(grid[i][j]=='X') continue;
            int node = calculate_node(i,j,size);
            for(int d=0; d<4; d++)
            {
                int r=i+dr[d], c=j+dc[d];
                while(r >= 0 && c >= 0 && r < size && c < size && grid[r][c] == '.')
                {
                    int neighbour = calculate_node(r,c,size);
                    graph[node].push_back(neighbour);
                    r += dr[d];
                    c += dc[d];
                }
            }
        }
    }
}

int calculate_distance(int start, int target, int size) {
    vector<int> dist(size * size, INT_MAX);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (v == target) return dist[v];
            }
        }
    }

    return dist[target] == INT_MAX ? -1 : dist[target];
}

int main()
{
    int size;
    cin>>size;
    cin.ignore();  
    vector<string> grid(size);
    for(int i =0 ;i<size; i++)
    {
        getline(cin,grid[i]);
    }
    init_graph(grid,size);
    int startRow, startColumn, endRow, endColumn;
    cin>>startRow>>startColumn>>endRow>>endColumn;
    int startNode= calculate_node(startRow, startColumn, size);
    int endNode = calculate_node(endRow, endColumn, size);
    cout<<calculate_distance(startNode,endNode, size);
    return 0;
}