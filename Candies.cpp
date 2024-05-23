#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) {
    vector<int> cnds(n, 1);  
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            cnds[i] = cnds[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1])
            cnds[i] = max(cnds[i], cnds[i + 1] + 1);
    }

    long res = accumulate(cnds.begin(), cnds.end(), 0L);
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long result = candies(n, arr);
    cout << result << "\n";

    return 0;
}
