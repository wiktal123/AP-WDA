#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int string_to_int(string a){
    int value=0;
    int k=(int)a.length(),i=0;
    int mult=pow(10,k-1);
    while(i<k){
        value+=(((int)a[i])-48)*mult;
        i++;
        mult/=10;
    }
    return value;
}

int main() {
    int t;
    cin>> t;
    while(t-->0){
        string equation;
        cin >> equation;
        string left_string, right_string;
        int i=0;
        while(equation[i]!='='){
            left_string+=equation[i];
            i++;
        }
        i++;
        while(i<(int)equation.length()){
            right_string+=equation[i];
            i++;
        }
        i=0;
        int current_sign=1;
        int lx=0,lv=0;
        string current_string;
        while(i<left_string.length()){
            if(left_string[i]=='-'||left_string[i]=='+'){
                if(left_string[i]=='-'){
                    current_sign=-1;
                }
                else{
                    current_sign=1;
                }
                i++;
            }
            else{
                int j=i;
                while(j<left_string.length()&&(int)left_string[j]>=48){
                    current_string+=left_string[j];
                    j++;
                }
                if(current_string[current_string.length()-1]=='x'){
                    if(current_string.length()==1){
                        lx+=current_sign;
                    }
                    else{
                        lx+= string_to_int(current_string.substr(0,(int)current_string.length()-1))*current_sign;
                    }
                }
                else{
                    lv+=current_sign* string_to_int(current_string);
                }
                i+=(j-i);
                current_string="";
            }
        }
        i=0;
        current_sign=1;
        int rx=0,rv=0;
        current_string="";
        while(i<right_string.length()){
            if(right_string[i]=='-'||right_string[i]=='+'){
                if(right_string[i]=='-'){
                    current_sign=-1;
                }
                else{
                    current_sign=1;
                }
                i++;
            }
            else{
                int j=i;
                while(j<right_string.length()&&(int)right_string[j]>=48){
                    current_string+=right_string[j];
                    j++;
                }
                if(current_string[current_string.length()-1]=='x'){
                    if(current_string.length()==1){
                        rx+=current_sign;
                    }
                    else{
                        rx+= string_to_int(current_string.substr(0,(int)current_string.length()-1))*current_sign;
                    }
                }
                else{
                    rv+=current_sign* string_to_int(current_string);
                }
                i+=(j-i);
                current_string="";
            }
        }
        double left=lx-rx,right=rv-lv;
        if((left==0&&right!=0)||(left==0&&right==0)){
            cout<<"NO"<<endl;
        }
        else{
            double value=right/left;
            cout<<value<<endl;
        }
    }
    return 0;
}