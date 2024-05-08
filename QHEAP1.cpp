#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int A[100000]={1000000001};
int n=0;

void insert(int i, int A[], int n){
    A[n]=i;
    if(n!=1){
        if(A[n]<A[1]){
            swap(A[n],A[1]);
        }
    }
}

void dilit(int i, int A[], int n){
    if(i==A[1]){
        swap(A[n],A[1]);
        int min=1;
        for(int i=1;i<n;i++){
            if(A[i]<A[min]){
                min=i;
            }
        }
        swap(A[1],A[min]);
    }
    else{
        int k=1;
        while(k<=n){
            if(A[k]==i){
                swap(A[k],A[n]);
                break;
            }
            ++k;
        }
    }
}

int printMinimum(int A[]){
    int min=A[1];
    return min;
}

int main() {
    int t;
    cin>>t;
    int instruction;
    while(t>0){
        cin>>instruction;
        if(instruction==1){
            int in;
            cin>>in;
            n+=1;
            insert(in, A, n);
        }
        if(instruction==2){
            int out;
            cin>>out;
            dilit(out, A, n);
            n-=1;
        }
        if(instruction==3){
            int min= printMinimum(A);
            cout<<min<<endl;
        }
        --t;
    }
 
    return 0;
}
