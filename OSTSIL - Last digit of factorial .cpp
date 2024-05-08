#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int factorial(int x) {
    long int fctrl = 1;
    if (x == 0 || x == 1) {
        return 1;
    }
    else{
        for(int i=2;i<=x;i++){
            fctrl*=i;
        }
        return fctrl;
    }
}

int last_digit_2pow(int a){
    if(a%4==0){
        return 6;
    }
    if(a%4==2) {
        return 4;
    }

    if(a%4==3){
        return 8;
    }
    return 2;
}

int fctrl_rec(int a){
    int divide_five;
    divide_five=a/5;
    if(a<5){
       return factorial(a)%10;
   }
   int division_rest;
   division_rest=a%5;
   int division_rest_factorial= factorial(division_rest)%10;
   int divide_five_factorial= factorial(divide_five)%10;
   return (last_digit_2pow(divide_five)* (fctrl_rec(divide_five)%10)*factorial(division_rest))%10;
   //(90/5=18)!? (2**18)%10=8 0!=1-->(18/5=3)!? (2**3)%10=8 3!=6-->6
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x;
        cin>>x;
        cout<< fctrl_rec(x)<<endl;
    }
    return 0;
}