#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*int is_perm(string a, string b){
    int A[26]={0},B[26]={0};
    int lenA=(int)a.length();
    int lenB=(int)b.length();
    if(lenA!=lenB){
        return 0;
    }
    else{
        for(int i=0;i<lenA;i++){
            A[(int)a[i]-65]+=1;
            B[(int)b[i]-65]+=1;
        }
        int i=0;
        while(i<26){
            if(A[i]!=B[i]){
                return 0;
            }
            i++;
        }
        return 1;
    }
}
*/

int main() {
    
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        string tab[n];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            tab[i]=s;
        }
        int max=0;
        for(int i=0;i<n-1;i++){
            int current=1;
            for(int j=i+1;j<n;j++){
                if(tab[i]==tab[j]){
                    current+=1;
                }   
            }
            if(current>max){
                max=current;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}