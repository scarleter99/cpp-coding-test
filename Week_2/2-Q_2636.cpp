#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, lastCnt;
int adj[104][104], nAdj[104][104], visited[104][104];
int ret;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx > m || visited[ny][nx] == 1) {
            continue;
        }

        if (adj[ny][nx] == 0) {
            dfs(ny, nx);
        }
        else {
            if (nAdj[ny][nx] == 1) {
                nAdj[ny][nx] = 0;
                cnt--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 1) {
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
            copy(adj[i], adj[i] + m, nAdj[i]);
    }
    
    while(cnt > 0) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        lastCnt = cnt;
        ret++;

        dfs(0, 0);

        for (int i = 0; i < n; i++) {
            copy(nAdj[i], nAdj[i] + m, adj[i]);
        }
    } 

    cout << ret << "\n";
    cout << lastCnt;

    return 0;
}