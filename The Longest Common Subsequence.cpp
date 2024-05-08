#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main(){
    int lenA, lenB;
    cin>>lenA>>lenB;
    int A[lenA],B[lenB];
    for(int i=0;i<lenA;i++){
        cin>>A[i];
    }
    for(int i=0;i<lenB;i++){
        cin>>B[i];
    }
    int dp[lenA+1][lenB+1];
    for(int i=0;i<=lenA;i++){
        for(int j=0;j<=lenB;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=lenA;i++){
        for(int j=1;j<=lenB;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }    
    int k= dp[lenA][lenB];
    int res[k];
    int i=lenA,j=lenB;
    while(j>0 && i>0){
            if(dp[i][j]==dp[i][j-1]){
                j--;
    
            }
            
            if(dp[i][j]==dp[i-1][j]){
                i--;
    
            }
            
            if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1]){
                res[k-1]=A[i-1];
                i--;
                j--;
                k--;
                
            }
    
    }
    for(int i=0;i<dp[lenA][lenB];i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
