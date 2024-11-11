#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'nodeDistance' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts UNWEIGHTED_INTEGER_GRAPH s as parameter.
 */

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i].
 *
 */

int visited[10000];
int visited2[10000];
vector<int> adj[10000];
set<int> cycle;
vector<int> ret;

void dfs(int node, int before, stack<int> his){
    visited[node]++;
    
    if (visited[node] > 1){
        cycle.insert(node);
        
        while(his.size() && his.top() != node){
            cycle.insert(his.top());
            his.pop();
        }
        
        return;
    }
    
    his.push(node);
    
    for(int i : adj[node]){
        if (i == before){
            continue;
        }
        dfs(i, node, his);
    }
}

int dfs2(int node, int cnt){
    visited2[node]++;
    cnt++;

    if (cycle.count(node)){
        return;
    }
    
    int ret2 = 987654321;
    for(int i : adj[node]){
        if(visited2){
            continue;
        }
        ret2 = min(ret2, dfs2(i, node));
    }

    return ret2;
}

vector<int> nodeDistance(int s_nodes, vector<int> s_from, vector<int> s_to) {
    for (long long i = 0; i < s_from.size(); i++){
        adj[s_from[i]].push_back(s_to[i]);
        adj[s_to[i]].push_back(s_from[i]);
    }
    
    stack<int> his;
    dfs(0, -1, his);
    
    cout<< cycle.size();

    for(int i = 0; i < s_nodes; i++){
        if (cycle.count(i)){
            ret.push_back(0);
            continue;
        }

        ret.push_back(dfs2(i, -1));    
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s_nodes_edges_temp;
    getline(cin, s_nodes_edges_temp);

    vector<string> s_nodes_edges = split(rtrim(s_nodes_edges_temp));

    int s_nodes = stoi(s_nodes_edges[0]);
    int s_edges = stoi(s_nodes_edges[1]);

    vector<int> s_from(s_edges);
    vector<int> s_to(s_edges);

    for (int i = 0; i < s_edges; i++) {
        string s_from_to_temp;
        getline(cin, s_from_to_temp);

        vector<string> s_from_to = split(rtrim(s_from_to_temp));

        int s_from_temp = stoi(s_from_to[0]);
        int s_to_temp = stoi(s_from_to[1]);

        s_from[i] = s_from_temp;
        s_to[i] = s_to_temp;
    }

    vector<int> result = nodeDistance(s_nodes, s_from, s_to);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
