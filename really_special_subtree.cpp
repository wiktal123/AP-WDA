#include <bits/stdc++.h>
#include <queue>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */


bool is_cyclic(int kid, int par, int g_nodes, vector<int> graph[g_nodes],bool vis[g_nodes]){
    vis[kid]=true;
    for(int neighbour : graph[kid]){
        if(neighbour==par) continue;
        if(vis[neighbour]) return true;
        if(is_cyclic(neighbour, kid, g_nodes, graph, vis)) return true;
        
    }
    return false;
}


int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int e= (g_nodes*(g_nodes-1))/2;
    bool is_edge[e][e]={false};
    priority_queue<pair<int,int>> g_weightSorted;
    vector<pair<int,int>> graph[g_nodes];
    int sum=0;
    for(int i =0;i< g_weight.size(); i++)
    {
        g_weightSorted.push(make_pair(g_weight[i]*(-1),i));
    }
    
    while(!g_weightSorted.empty())
    {
        pair<int,int> current= g_weightSorted.top();
        g_weightSorted.pop();
        graph[g_from[current.second()]].push_back(g_to[current.second]);
        graph[g_to[current.second()]].push_back(g_from[current.second]);
        bool vis[g_nodes]={false};
        vis[g_from[current.second()]]=true;
        if(is_edge[g_to[current.second()]][g_from[current.second()]]) continue;
        if(is_cyclic(g_to[current.second()],g_from[current.second()],g_nodes, graph, vis))
        {
            graph[g_to[current.second()]].pop_back();
            graph[g_from[current.second()]].pop_back();
            continue;
        } else
        {
            is_edge[g_to[current.second()]][g_from[current.second()]]= true;
            is_edge[g_from[current.second()]][g_to[current.second()]]= true;
            sum+=current.first()*(-1);
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout<<res<<'\n';

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
