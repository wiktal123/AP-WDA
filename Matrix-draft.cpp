#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//global variables
vector<int> mn= {INT_MAX,-1,-1}; //pottential mistake!!!!!
vector<bool> visited;
vector<vector<bool>> is_road[100001][100001]={false};
vector<vector<pair<int,int>>> ;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}

bool disconnect(int node, vector<bool> arrayOfMachines, vector<int> curMin) //graph traversing
{

    /*
    Here must be implemented graph traversing for finding minimal cost of deleting road between two machines
        -forwarding current minimal cost with road details
        -returning as soon as machine is found
        -deleting minimal cost edge (road) from the graph
    */ 
    
    if(arrayOfMachines[node]) 
    {
        mn=curMin;
        return true;
    }
    visited[node]=true;
    for(auto neighbour: graph[node])
    {
        if(!visited[neighbour.first] && is_road[node][neighbour.first])
        {
            if(neighbour.second<curMin[0]) 
            {
                curMin={neighbour.second, neighbour.first, node};
            }
            disconnect(neighbour.first, arrayOfMachines,curMin);
        }
    }
    return false;
}


int minTime(vector<vector<int>> roads, vector<int> machines) // main algorythm
{
    //basic variables
    int res=0;
    int size= roads.size()+1;
    vector<bool> arrayOfMachines(size,false);
    sort(roads.begin(),roads.end(),sortcol); // ascending order in vector roads, sorted by time cost

    for(auto machine : machines) // creating machines array
    {
        arrayOfMachines[machine]=true;
    }

    for(auto road: roads) // creating graph, road by road
    {
        graph[road[0]].push_back({road[1],road[2]});
        graph[road[1]].push_back({road[0],road[2]});
        is_road[road[0]][road[1]]=true;
        is_road[road[1]][road[0]]=true;
        if(arrayOfMachines[road[0]])
        {
            memset(visited,false,sizeof(visited)); // resetting global variables
            mn={INT_MAX,-1,-1};

            if(disconnect(road[0], arrayOfMachines, {INT_MAX,-1,-1})) 
            {
                res+=mn[0]; // checking for possible connection and deleting it
                is_road[mn[1]][mn[2]]=false;
                is_road[mn[2]][mn[1]]=false;
            }
        } 
        else if(arrayOfMachines[road[1]])
        {
            memset(visited,false,sizeof(visited)); // resetting global variables
            mn={INT_MAX,-1,-1};

            if(disconnect(road[1], arrayOfMachines, {INT_MAX,-1,-1})) 
            {
                res+=mn[0]; // checking for possible connection and deleting it
                is_road[mn[1]][mn[2]]=false;
                is_road[mn[2]][mn[1]]=false;
            }
        }
                            
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> roads(n - 1);

    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        string machines_item_temp;
        getline(cin, machines_item_temp);

        int machines_item = stoi(ltrim(rtrim(machines_item_temp)));

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

    fout << result << "\n";

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


int main()
{
    int nodes, machines, input;
    cin>>nodes>>machines;
    input=nodes-1;


    while(input--)
    {
        int a, b, t;
        cin>>a>>b>>t;
    }
    return 0;
}