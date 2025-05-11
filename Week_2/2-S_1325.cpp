#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, maxCnt;
vector<int> adj[10004];
int visited[10004];
vector<int> ret;

void algo(int com){
    visited[com] = 1;
    cnt++;

    for (int i : adj[com]){
        if (!visited[i]){
            algo(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        cnt = 0;
        fill(visited, visited + n + 1, 0);

        algo(i);

        if (cnt > maxCnt){
            ret.clear();
            ret.push_back(i);
            maxCnt = cnt;
        }
        else if (cnt == maxCnt){
            ret.push_back(i);
        }
    }

    for (int i : ret){
        cout << i << " ";
    }

    return 0;
}