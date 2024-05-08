#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int p;
    cin>> p;
    int A[p]={0};
    int dp[6][p]={0};
    for(int i=0;i<p;i++){
        cin>>A[i];
    }
    dp[0][0]=A[0];
    for(int i=1;i<p;i++){
        dp[0][i]=A[i]+dp[0][i-1];
    }
    for(int i=0;i<6;i++){
        dp[i][0]=A[0];
    }
    for(int i=1;i<6;i++){
        for(int j=1;j<p;j++){
            if(j>=i+1){
                int temp=max(dp[i][j-i-1]+A[j],dp[i-1][j]);
                for(int k=1;k<=i;k++){
                    temp=max(temp,dp[i][j-k]+A[j]);
                }
                dp[i][j]=temp;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[5][p-1];
    return 0;
}
