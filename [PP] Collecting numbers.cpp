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
    int size;
    cin>>size;
    int map[size][size];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin>>map[i][j];
        }
    }
    for(int i=1; i<size; i++){
        map[0][i]=map[0][i]+map[0][i-1];
        map[i][0]=map[i][0]+map[i-1][0];
    }
    for(int i=1; i<size; i++){
        for(int j=1; j<size; j++){
            map[i][j]=max(map[i-1][j],map[i][j-1])+map[i][j];
        }
    }
    int res=map[size-1][size-1];
    cout<<res;
    return 0;
}