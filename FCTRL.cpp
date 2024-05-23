#include <iostream>
using namespace std;

long long zeros_in_factorial(long long N) {
    long long count = 0;
    for (long long power_of_5 = 5; power_of_5 <= N; power_of_5 *= 5) {
        count += N / power_of_5;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;
        cout << zeros_in_factorial(N) << "\n";
    }

    return 0;
}
