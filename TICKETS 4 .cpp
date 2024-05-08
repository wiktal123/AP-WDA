#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int stops, tickets;
        cin >> stops >> tickets;
        int A[stops]={0};
        for(int j=0;j<tickets;j++){
            int in, out;
            cin >> in >> out;
            A[in]=A[in]+1;
            A[out]=A[out]-1;
        }
        int max=0,maxstop=0, p=0;
        for(int j=0;j<stops;j++){
            p+=A[j];
            if(p>max){
                max=p;
                maxstop=j;
            }
        }
        cout << maxstop << " " << max << endl;
    }
    return 0;
}