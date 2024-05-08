#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string dodaj(string a, string b){
    int C[200]={0};
    int la=(int)a.length(),lb=(int)b.length();
    if(la>lb){
        int k=la-lb;
        string pom=b;
        b="";
        while(k-->0){
            b+='0';
        }
        b+=pom;
    }
    if(lb>la){
        int k=lb-la;
        string pom=a;
        a="";
        while(k-->0){
            a+='0';
        }
        a+=pom;
        la=lb;
    }
    int len=la-1, lc=199, carry=0;
    while(len>=0){
        if(((int)a[len]-48)+((int)b[len]-48)+carry>9){
            C[lc]=((int)a[len]-48)+((int)b[len]-48)+carry-10;
            carry=1;
        }
        else{
            C[lc]=((int)a[len]-48)+((int)b[len]-48)+carry;
            carry=0;
        }
        len-=1;
        lc-=1;
    }
    string res;
    C[lc]=carry;
    for(int i=199-la;i<200;i++){
        res+=(char)(C[i]+48);
    }
    return res;
}

string odejmij(string a, string b){
    int C[200]={0};
    int la=(int)a.length(),lb=(int)b.length();
    if((la==lb)&&(((int)a[0]-48)<((int)b[0]-48))){
        swap(a,b);
    }
    if(la>lb){
        int k=la-lb;
        string pom=b;
        b="";
        while(k-->0){
            b+='0';
        }
        b+=pom;
    }
    if(lb>la){
        int k=lb-la;
        string pom=a;
        a="";
        while(k-->0){
            a+='0';
        }
        a+=pom;
        la=lb;
        swap(a,b);
    }
    int len=la-1, lc=199, carry=0;
    while(len>=0){
        if(((int)a[len]-48)-((int)b[len]-48)-carry<0){
            C[lc]=10+(((int)a[len]-48)-((int)b[len]-48)-carry);
            carry=1;
        }
        else{
            C[lc]=((int)a[len]-48)-((int)b[len]-48)-carry;
            carry=0;
        }
        len-=1;
        lc-=1;
    }
    string res;
    int it=0;
    for(int i=199-la+1;i<200;i++){
        if(C[i]>0){
            it=1;
        }
        if(it==1){
            res+=(char)(C[i]+48);
        }
    }
    return res;
}

int main() {
    long long t;
    cin>>t;
    while(t-->0){
        string b,c,d;
        cin>>b>>c>>d;
        string x1=dodaj(c, c),x2=dodaj(d, b);
        string a=odejmij(x1,x2);
        cout<<a<<endl;
    }
    return 0;
}
