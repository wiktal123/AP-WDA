#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int N) {
    vector<int> color(N, 0); 
    queue<int> q;

    for (int i = 0; i < N; ++i) {
        if (color[i] != 0) continue;
        q.push(i);
        color[i] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (color[v] == 0) {
                    color[v] = -color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false; 
                }
            }
        }
    }
    return true; 
}

int main() {
    int scenarios;
    cin >> scenarios;

    for (int i = 1; i <= scenarios; ++i) {
        int bugs, interactions;
        cin >> bugs >> interactions;

        vector<vector<int>> graph(bugs); 

        for (int j = 0; j < interactions; ++j) {
            int bug1, bug2;
            cin >> bug1 >> bug2;
            graph[bug1 - 1].push_back(bug2 - 1);
            graph[bug2 - 1].push_back(bug1 - 1);
        }

        cout << "Scenario #" << i << ":\n";
        isBipartite(graph, bugs) ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n";
    }

    return 0;
}