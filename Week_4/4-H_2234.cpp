#include <bits/stdc++.h>
using namespace std;

int n, m;
int adj[54][54], visited[54][54], roomSize[2504];
int now, big, roomMax;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x, int now){
    visited[y][x] = now;

    int cnt = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if ((adj[y][x] & (1 << i)) || visited[ny][nx] || ny < 0 || nx < 0 || ny >= m || ny >= n){
            continue;
        }

        cnt += dfs(ny, nx, now);
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j]){
                continue;
            }
            now++;
            roomSize[now] = dfs(i, j, now);
            roomMax = max(roomMax, roomSize[now]);
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i + 1 < m){
                int a = visited[i + 1][j];
                int b = visited[i][j];

                if (a != b){
                    big = max(big, roomSize[a] + roomSize[b]);
                }
            }

            if (j + 1 < n){
                int a = visited[i][j + 1];
                int b = visited[i][j];
                
                if (a != b){
                    big = max(big, roomSize[a] + roomSize[b]);
                }
            }
        }
    }

    cout << now << "\n" << roomMax << "\n" << big << "\n";

    return 0;
}