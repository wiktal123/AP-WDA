#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> tab(n, vector<int>(m));
        vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                tab[i][j] = s[j] - '0'; 
                if (tab[i][j] == 1) {
                    distances[i][j] = 0;
                    q.push({i, j}); 
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) { 
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (distances[nr][nc] > distances[r][c] + 1) {
                        distances[nr][nc] = distances[r][c] + 1;
                        q.push({nr, nc}); 
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << distances[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
