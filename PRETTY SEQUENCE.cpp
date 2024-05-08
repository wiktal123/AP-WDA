#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    int tab[n+1][k+1];
    for (int i = 0; i <= k; i++) {
        tab[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int sum = tab[i - 1][j];
            sum = sum%q;
            if (j > 0) {
                sum += tab[i - 1][j - 1];
                sum = sum%q;
            }
            if (j < k) {
                sum += tab[i - 1][j + 1];
                sum = sum%q;
            }
            tab[i][j] = sum;
        }
    }
    for (int i = 0; i < n; i++) {
        int res = 0;
        int d;
        cin >> d;
        for (int j = 0; j <= k; j++) {
            res += tab[d - 1][j];
        }
         cout << res % q << ' ';
    }
    return 0;
}