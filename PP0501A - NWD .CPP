#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int euclides(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return(euclides(b, a%b));
    }
}

int main() {
    int t;
    cin>>t;
    while(t-->0){
        int a,b;
        cin>>a;
        cin>>b;
        if(a==b){
            cout<<a<<endl;
        }
        else{
            if(a>b){
                cout<<euclides(a,b)<<endl;
            }
            else{
                cout<<euclides(b,a)<<endl;
            }
        }
    }
    
    return 0;
}