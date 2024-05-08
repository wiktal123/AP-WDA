#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool is_prime(int a){
    if(a==0 || a==1){
        return false;
    }
    if(a==2){
        return true;
    }
    if(a%2==0){
        return false;
    }
    for(int i=3;i*i<=a;i+=2){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        if(is_prime(n)){
            cout << "TAK"<< endl;
        }
        else{
            cout << "NIE"<< endl;
        }
    }
    return 0;
}