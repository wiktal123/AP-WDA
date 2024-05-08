#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
# include <string>
using namespace std;

int rvrs(string a){
    int res=0, len=(int)a.length()-1;
    while(len>=0){
        res+=((int)a[len]-48)*pow(10,len);
        len--;
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t-->0){
        string a,b;
        cin>>a>>b;
        int reva=rvrs(a);
        int revb=rvrs(b);
        int sum=reva+revb;
        string strsum= to_string(sum);
        int res= rvrs(strsum);
        cout<<res<<endl;
    }
    return 0;
}