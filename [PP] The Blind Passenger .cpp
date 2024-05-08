#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int place, row;
        string side;
        cin>>place;
        if(place==1){
            cout<<"poor conductor"<<endl;
            continue;
        }
        else{
            row = ((place-2)/5)+1;
            cout<<row<<" ";

            if(place%10<=3){
                side="left";
            }
            else{
                side="right";
            }
            if(row%2==0) {
                if (side == "left") {
                    if (place % 10 == 1) {
                        cout << "W"<<" ";
                    } else {
                        cout << "A"<<" ";
                    }
                } else {
                    if (place % 10 == 9) {
                        cout << "A"<<" ";
                    }
                    if (place % 10 == 8) {
                        cout << "M"<<" ";
                    } 
                    if(place%10==7){
                        cout << "W"<<" ";
                    }
                }
            }
            else{
                if(side=="left"){
                    if(place%10==2){
                        cout<<"W"<<" ";
                    }
                    else{
                        cout<<"A"<<" ";
                    }
                }
                else{
                    if(place%10==4){
                        cout<<"A"<<" ";
                    }
                    if(place%10==5){
                        cout<<"M"<<" ";
                    }
                    if(place%10==6){
                        cout<<"W"<<" ";
                    }
                }
            }
            if(side=="left"){
                cout<<"L"<<endl;
            }
            else{
                cout<<"R"<<endl;
            }
        }

    }

    return 0;
}