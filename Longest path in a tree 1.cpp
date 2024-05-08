#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int is_end(int k, int B[], vector<int> A[]) {
    for (int i = 0; i < (int)A[k].size(); i++) {
        if (B[A[k][i]] == 0) {
            return 1;
        }
    }
    return 0;
}

int longest_path(int k, int B[], vector<int> A[]) {
    B[k] = 1;
    int max_len = 0;
    if (is_end(k, B, A) == 0) {
        return max_len + 1;
    }
    for (int i = 0; i < (int)A[k].size(); i++) {
        if (B[A[k][i]] == 0) {
            int x = longest_path(A[k][i], B, A);  
            if (max_len < x) {
                max_len = x;
            }
        }
    }
    return max_len+1;
}

int main() {
    int N, E;
    cin >> N;
    E = N - 1;
    vector<int> A[N + 1];
    for (int i = 0; i < E; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        A[n1].push_back(n2);
        A[n2].push_back(n1);
    }
    int max_len = 0;
    for (int i = 1; i <= N; i++) {
        int B[N + 1] = {0};
        int x = longest_path(i, B, A)-1; 
        if (max_len < x) {
            max_len = x;
        }
    }
    cout << max_len;
    return 0;
}
