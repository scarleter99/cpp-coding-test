#include<bits/stdc++.h>
using namespace std;

int r, c;
int adj[24][24], visited[24][24];
int alpha[200];
int ret;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    alpha[adj[y][x]] = 1;
    cnt++;
    
    int flag = 0;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || alpha[adj[ny][nx]]){
            continue;
        }

        flag = 1;
        dfs(ny, nx, cnt);
    }

    if (!flag){
        ret = max(ret, cnt);
    }
    
    alpha[adj[y][x]] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++){
        string line;
        cin >> line;
        for (int j = 0; j < c; j++){
            adj[i][j] = line[j];
        }
    }

    dfs(0, 0, 0);

    cout << ret;

    return 0;
}