#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'unboundedKnapsack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int unboundedKnapsack(int n, int k, int A[]){
    int dp[n+1][k+1]={0};
    for(int j=0;j<=k;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
                if(A[i-1]<=j){
                    dp[i][j]=max(dp[i][j-A[i-1]]+A[i-1],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
        }
    }
    return dp[n][k];
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int res=unboundedKnapsack( n, k, A);
        cout<<res<<endl;
    }
    return 0;
}
  
