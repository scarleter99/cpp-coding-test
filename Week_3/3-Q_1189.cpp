#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char adj[10][10];
int visited[10][10];
int ret;

int dy[] ={-1, 0, 1, 0};
int dx[] ={0, 1, 0, -1};

void algo(int y, int x, int cnt){
    if (y == 0 && x == c-1){
        if (cnt == k){
            ret++;
        }
        return;
    }

    if (cnt == k){
        return;
    }

    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || adj[ny][nx] == 'T'
            || visited[ny][nx]){
            continue;
        }

        visited[ny][nx] = 1;
        algo(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++){
        string line;
        cin >> line;
        for (int j = 0; j < c; j++){
            adj[i][j] = line[j];
        }
    }

    visited[r-1][0] = 1;
    algo(r-1, 0, 1);

    cout << ret;

    return 0;
}