#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfs(int node, int parent, const vector<vector<int>>& adj_list, set<int>& visited) {
    visited.insert(node);

    for (int neighbor : adj_list[node]) {
        if (visited.find(neighbor) == visited.end()) {
            if (!dfs(neighbor, node, adj_list, visited)) {
                return false;
            }
        } else if (neighbor != parent) {
            return false;
        }
    }

    return true;
}

bool is_tree(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj_list(n + 1);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    set<int> visited;

    if (!dfs(1, -1, adj_list, visited) || visited.size() != static_cast<size_t>(n)) {
        return false; 
    } else {
        return true;  
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<pair<int, int>> edges(E);

    for (int i = 0; i < E; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    bool result = is_tree(N, edges);

    cout << (result ? "YES" : "NO") << endl;

    return 0;
}
