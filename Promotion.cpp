#include <set>
#include <ios>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

multiset< int > S;
multiset< int > :: iterator mn, mx;

int main() {
    long long sum = 0;
    int n, i, j, p,m;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>m;
        for(j=0; j<m; j++) {
            cin>>p;
            S.insert(p);
        }
        mn = S.begin();
        mx = S.end(); mx--;
        sum += (*mx - *mn);
        S.erase(mn);
        S.erase(mx);
    }
    cout<<sum;
    return 0;
}