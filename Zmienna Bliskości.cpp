#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int lenA, lenB;
    cin >> lenA >> lenB;
    string A, B;
    cin >> A >> B;
    
    if(lenA==0 || lenB==0){
        cout<<0<<endl;
        return 0;
    }

    int dp[lenB+1]={0};
    for(int i=1;i<=lenA;i++){
        int prev=0;
        for(int j=1;j<=lenB;j++){
            int temp=dp[j];
            if(A[i-1]==B[j-1]){
                dp[j]=prev+1;
            }
            else{
                dp[j]=max(dp[j],dp[j-1]);
            }
            prev=temp;
        }
    }
    int res = dp[lenB];
    double zb = 2.0 * res / (lenA + lenB);

    cout.precision(2);
    cout << zb << endl;

    return 0;
}
