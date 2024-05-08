#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool check(int x,int stalls, int cows, int A[]){
    int last=A[0],cows_placed=1;
    for(int i=1;i<stalls;i++){
        if( A[i]-last>=x){
            last=A[i];
            cows_placed+=1;
            if(cows_placed==cows){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int stalls, cows;
        cin >>stalls>>cows;
        int A[stalls];
        for(int j=0;j<stalls;j++){
            cin>> A[j];
        }
        sort(A,A+stalls);
        long long beg=0, end=1000000000,res=0;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(check(mid,stalls,cows,A)){
                res=mid;
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}