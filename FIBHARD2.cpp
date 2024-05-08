#include <iostream>
#include <array>
#include <string>
#define ull unsigned long long

using namespace std;

array<ull, 4> matrix_mul( array<ull, 4>& A,  array<ull, 4>& Q) {
    array<ull, 4> P;
    P[0] = (A[0] * Q[0])%998244353 + (A[1] * Q[2])%998244353;
    P[1] = (A[0] * Q[1])%998244353 + (A[1] * Q[3])%998244353;
    P[2] = (A[2] * Q[0])%998244353 + (A[3] * Q[2])%998244353;
    P[3] = (A[2] * Q[1])%998244353 + (A[3] * Q[3])%998244353;
    return P;
}

array<ull, 4> matrix_power( array<ull, 4>& A, string n) {
    array<ull, 4> res = {1, 0, 0, 1};
    int len=n.length()-1;
        while (len>=0) {
        if (n[len]=='1') {
            res = matrix_mul(res,A);
        }
        A = matrix_mul(A, A);
        len--;
    }
    return res;
}


int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        array<ull, 4> A = {1, 1, 1, 0};
        string no;
        cin >> no;
        array<ull, 4> res = matrix_power(A, no);
        cout << res[1]%998244353<< endl;
    }
    return 0;
}
