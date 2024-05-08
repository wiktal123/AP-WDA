#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#define NIL 0
#define INF INT_MAX

using namespace std;

bool bfs(vector<list<int>> &matches, vector<int> &cMatch, vector<int> &bMatch, vector<int> &distance);
bool dfs(int k, vector<list<int>> &matches, vector<int> &cMatch, vector<int> &bMatch, vector<int> &distance);

int maxMatches(int c, int b, vector<list<int>> &matches)
{
    vector<int> cMatch(c+1, NIL);
    vector<int> bMatch(b+1, NIL);
    vector<int> distance(c+1);
    int res=0;

    while(bfs(matches, cMatch, bMatch, distance))
    {
        for(int i=1;i<=c;i++)
        {
            if(cMatch[i]== NIL && dfs(i, matches, cMatch, bMatch, distance))res++;
        }
    }
    return res;
}

bool bfs(vector<list<int>> &matches, vector<int> &cMatch, vector<int> &bMatch, vector<int> &distance)
{
    queue<int> q;

    for(size_t i=1; i<cMatch.size(); i++)
    {
        if(cMatch[i]==NIL)
        {
        distance[i]=0;
        q.push(i);
        }else
        {
            distance[i]=INF;
        }
    }

    distance[NIL]=INF;

    while(!q.empty())
    {
        int i= q.front();
        q.pop();
        if(distance[i]< distance[NIL])
        {
            for(auto j: matches[i])
            {
                if(distance[bMatch[j]]==INF)
                {
                    distance[bMatch[j]]= distance[i]+1;
                    q.push(bMatch[j]);
                }
            }
        }
    }
    return (distance[NIL] != INF);
}

bool dfs(int k, vector<list<int>> &matches, vector<int> &cMatch, vector<int> &bMatch, vector<int> &distance)
{
    if(k !=NIL)
    {
        for(auto j: matches[k])
        {
            if(distance[bMatch[j]]==distance[k]+1)
            {
                if(dfs(bMatch[j], matches, cMatch, bMatch, distance))
                {
                    cMatch[k]= j;
                    bMatch[j]= k;
                    return true;
                }
            }
        }
        distance[k]= INF;
        return false;
    }
    return true;
}

int main()
{
    int c,b,edges;
    cin>>c>>b>>edges;
    vector<list<int>> matches;
    while(edges-->0)
    {
        int cow, bull;
        cin>>cow>>bull;
        matches[c].push_back(b);
    }

    cout<<maxMatches(c,b,matches)<<'\n';

    return 0;
}