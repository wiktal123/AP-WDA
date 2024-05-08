#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
using namespace std;

array<string, 2> split(string x) {
    array<string, 2> A;
    string a, b;
    int is_true = 1;

    for (int i = 0; i < (int)x.length(); i++) {
        if (is_true == 1) {
            if (x[i] == ':') {
                is_true = 0;
                continue;
            }
            a.push_back(x[i]);  
        } 
        else {
            b.push_back(x[i]);  
        }
    }
    
    A[0] = a;
    A[1] = b;
    return A;
}

int del(string key, string hashTable[]) {
    for (int i = 0; i < 101; i++) {
        if (hashTable[i] == key) {
            hashTable[i] = "";
            return 1;
        }
    }
    return 0;
}

int add(string key, string hashTable[]){
    int h=0, hash, newHash;
    for(int i=0;i<(int)key.length();i++){
        h+=((int)key[i])*(i+1);
    }
    h*=19;
    hash=h%101;
    if(hashTable[hash]==key){
        return 0;
    }
    else{
        for(int j=1;j<20;j++){
            newHash=(hash+j*(j+23))%101;
            if(hashTable[newHash]==key){
                return 0;
            }
        }    
    }
    if(hashTable[hash]==""){
            hashTable[hash]=key;
            return 1;
    }
    else{
        for(int j=1;j<20;j++){
            newHash=(hash+j*(j+23))%101;
            if(hashTable[newHash]==""){
                hashTable[newHash]=key;
                return 1;
            }
        }  
    }
    return 0;
}

int main() {
    int t;
    cin >> t;

    string hashTable[101];

    while (t-- > 0) {
        for(int i=0; i<101; i++){
            hashTable[i] = "";
        }
        int n, finNum=0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string x, op, key;
            array<string, 2> A;
            cin >> x;
            A = split(x);
            op = A[0];
            key = A[1];
            if(op=="ADD"){
                finNum+=add(key,hashTable);
            }
            else{
                finNum-=del(key,hashTable);
            }
        }
        cout<<finNum<<endl;
        for(int i=0;i<101;i++){
            if(hashTable[i]!=""){
                cout<<i<<":"<<hashTable[i]<<endl;
            }
        }
    }

    return 0;
}
