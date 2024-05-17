#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, isMachine;

    UnionFind(int n, const vector<int>& machines) : parent(n), rank(n, 0), isMachine(n, 0) {
        iota(parent.begin(), parent.end(), 0);
        for (int machine : machines) {
            isMachine[machine] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                isMachine[rootX] |= isMachine[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                isMachine[rootY] |= isMachine[rootX];
            } else {
                parent[rootY] = rootX;
                isMachine[rootX] |= isMachine[rootY];
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }

    bool isMachineConnected(int x, int y) {
        return isMachine[find(x)] && isMachine[find(y)];
    }
};

int minTime(vector<vector<int>>& roads, vector<int>& machines) {
    int n = roads.size() + 1;
    UnionFind uf(n, machines);

    sort(roads.begin(), roads.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    int totalTime = 0;

    for (const auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        if (uf.isMachineConnected(u, v)) {
            totalTime += time;
        } else {
            uf.unite(u, v);
        }
    }

    return totalTime;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        roads[i] = {u, v, t};
    }

    vector<int> machines(k);
    for (int i = 0; i < k; ++i) {
        cin >> machines[i];
    }

    cout << minTime(roads, machines) << endl;
    return 0;
}
