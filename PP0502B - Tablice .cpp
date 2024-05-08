#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int A[n];
        for(int j=0;j<n;j++) {
            cin >> A[j];
        }
        for(int k=n-1;k>=0;k--){
            cout<<A[k]<<" ";
        }
        cout<<endl;

    }
    return 0;
}