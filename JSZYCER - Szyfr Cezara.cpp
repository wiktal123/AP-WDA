#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char szyfruj(char a,int k){
    char szyfr;
    if((int)a + k>90){
        szyfr= (char)(65+((int)a + k -91));
    }
    else{
        szyfr= (char)((int)a + k);
    }
    return szyfr;
}

int main() {
    string before,after;
    int k=3;
    string output;
    string tekst="a",prew_tekst="b";
    while(true){
        getline(cin,tekst);
        if(tekst==prew_tekst){
            break;
        }
        prew_tekst=tekst;
        output="";
        for(int i=0;i<tekst.length();i++){
            if((int)tekst[i]>90||(int)tekst[i]<65){
                output+=tekst[i];
            }
            else{
                output+=szyfruj(tekst[i], k);
            }
        }
        cout<<output<<endl;
    }
    return 0;
}