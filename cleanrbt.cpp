#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

struct Point
{
    int x;
    int y;
};
bool visited[20][20];
int minMoves = 0, dirtCounter = 0;
char tiles[20][20];
vector<Point> graph[20][20];
pair <int, int> tableOfDirt[11];
int distances[10][10]= {-1};
int startDistances[10]= {-1};

void bfs(int start, int target)
{
    Point s, t;
    s.x= tableOfDirt[start].first, s.y= tableOfDirt[start].second;
    t.x= tableOfDirt[target].first, t.y= tableOfDirt[target].second;
    memset(visited, false, sizeof(visited));
    int distance=0;
    queue<pair<Point,int>> q;
    visited[s.x][s.y] = true;
    q.push({s,distance});
    while (!q.empty())
    {
        Point current = q.front().first;
        int curDistance = q.front().second;
        q.pop();
        if (current.x==t.x && current.y == t.y)
        {
            if(start==10)
            { 
                startDistances[target]=curDistance;
            }else
            {
                distances[start][target]= curDistance;
                distances[target][start]= curDistance;
            }
        }
        
        for (auto neighbour : graph[current.x][current.y])
        {
            if (!visited[neighbour.x][neighbour.y])
            {
                if(tiles[neighbour.x][neighbour.y]=='x')
                {
                    continue;
                }
                else
                {
                    visited[neighbour.x][neighbour.y] = true;
                    q.push({neighbour,curDistance+1});
                }
            }
        }
    }
}

int main()
{
    int width, height;
    while (true)
    {
        memset(tiles, 'x', sizeof(tiles)), memset(tableOfDirt, -1, sizeof(tableOfDirt));
        memset(distances, -1, sizeof(distances)),memset(startDistances, -1, sizeof(startDistances));; // reset tables
        vector<int> nums;
        minMoves = 401, dirtCounter=0; //reset variables
        cin >> width >> height; //get input
        if (width == 0 && height == 0){ break; } //check for end
        for (int x = 0; x < height; x++) //get all dat
        {
            for (int y = 0; y < width; y++)
            {
                char symbol;
                cin >> symbol;
                tiles[x][y] = symbol;
                if (symbol == 'o')
                {
                    tableOfDirt[10].first = x;
                    tableOfDirt[10].second = y;
                }
                else if (symbol == '*')
                {
                    tableOfDirt[dirtCounter].first = x, tableOfDirt[dirtCounter].second = y;
                    nums.push_back(dirtCounter);
                    dirtCounter++;
                }
            }
        }
        for (int x = 0; x < height; x++) // create graph
        {
            for (int y = 0; y < width; y++)
            {    
                char symbol = tiles[x][y];
                if (symbol != 'x')
                {
                    if (x - 1 >= 0 && tiles[x - 1][y] != 'x') // go left
                    {
                        Point addMe;
                        addMe.x = x - 1;
                        addMe.y = y;
                        graph[x][y].push_back(addMe);
                    }
                    if (x + 1 < height && tiles[x + 1][y] != 'x') // go right
                    {
                        Point addMe;
                        addMe.x = x + 1;
                        addMe.y = y;
                        graph[x][y].push_back(addMe);
                    }
                    if (y - 1 >= 0 && tiles[x][y - 1] != 'x') // go up
                    {
                        Point addMe;
                        addMe.x = x;
                        addMe.y = y - 1;
                        graph[x][y].push_back(addMe);
                    }
                    if (y + 1 < width && tiles[x][y + 1] != 'x') // go down
                    {
                        Point addMe;
                        addMe.x = x;
                        addMe.y = y + 1;
                        graph[x][y].push_back(addMe);
                    }
                }
            }
        }
        bool is_possible= true; 
        for(int i=0; i< dirtCounter; i++) //calculate distances from start
        {
            bfs(10,i);
            if(startDistances[i]==-1){is_possible=false;}
        }
        if(is_possible) //possible
        {
            int dstnc=startDistances[nums[0]];;
            for(int i=0; i<dirtCounter-1; i++) //fill distance matrix beetwen every pair of dirts
            {
                for(int j=i+1; j<dirtCounter; j++){
                    bfs(i,j);
                }
            }
            for(int i=0; i<dirtCounter-1; i++){
                dstnc+=distances[nums[i]][nums[i+1]];
            }
            if(dstnc<minMoves){ minMoves=dstnc; }
            while(next_permutation(nums.begin(),nums.end())) // get permutations and determine minimal path for the robot
            {
                dstnc=0;
                for(int i=0; i<dirtCounter-1; i++){
                    dstnc+= distances[nums[i]][nums[i+1]];
                }
                dstnc+= startDistances[nums[0]];
                if(dstnc<minMoves){ minMoves=dstnc; }
            }
            cout<<minMoves<<endl;
        }
        else{ cout<<-1<<endl; } //not possible
    }
}

