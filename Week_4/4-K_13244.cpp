#include <bits/stdc++.h>
using namespace std;

int t, n, m, flag, cnt;
vector<int> adj[1004];
int visited[1004];

void dfs(int pNode, int node){
    visited[node] = 1;
    cnt++;

    for (int nNode : adj[node]){
        if (nNode == pNode){
            continue;
        }
        if (visited[nNode]){
            flag = 1;
            return;
        }

        dfs(node, nNode);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        flag = 0;
        cnt = 0;
        fill(visited, visited + 1004, 0);

        for (int i = 0; i < 1004; i++){
            adj[i].clear();
        }

        cin >> n >> m;
        
        for (int i = 0; i < m; i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
        }

        for (int i = 0; i < m; i++){
            if (!visited[i]){
                dfs(0, 1);
            }
        }

        if (cnt != n){
            flag = 1;
        }

        if (flag){
            cout << "graph" << "\n";
        }
        else{
            cout << "tree" << "\n";
        }
    }

    return 0;
}