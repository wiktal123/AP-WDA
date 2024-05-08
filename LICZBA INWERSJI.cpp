#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long merge(int first, int middle, int last, long long tab[]){
    int left=first;
    int right= middle;
    int res=0;
    int tmp[(last-first+1)];
    long long inversion_count=0;
    
    while((left<middle) && (right<=last)){
        if(tab[left]<=tab[right]){
            tmp[res]=tab[left];
            ++res, ++left;
        }
        else{
            tmp[res]=tab[right];
            inversion_count+=(middle-left);
            ++res, ++right;
        }
    }
    while(left<middle){
        tmp[res]=tab[left];
        ++res;
        ++left;
    }
    while(right<=last){
        tmp[res]=tab[right];
        ++res;
        ++right;
    }
    for(int i=first,res=0;i<=last;i++,res++){
        tab[i]=tmp[res];
    }
    return inversion_count;
}

long long merge_sort(int first, int last, long long tab[]){
    long long inversion_count=0;
    if(last>first){
        int middle=(first+last)/2;
        inversion_count=merge_sort(first,middle,tab);
        inversion_count+= merge_sort(middle+1,last,tab);
        inversion_count+= merge(first,middle+1,last,tab);
    }
    return inversion_count;
}

long long count_inversions(long long tab[],int n){
    return merge_sort(0, n-1, tab);
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        unsigned int n;
        cin>>n;
        long long tab[n]={0};
        long long x;
        for(unsigned int j=0;j<n;++j){
            cin>>x;
            tab[j]=x;
        }
        long long k=count_inversions(tab,  n);
        cout<<k<<endl;
    }
    return 0;
}