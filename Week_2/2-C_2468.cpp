#include <bits/stdc++.h>
using namespace std;

int n, maxH, safe;
int adj[104][104];
int visited[104][104];
int ret;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int h, int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i ++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
        {
            continue;
        }

        if (adj[ny][nx] > h)
        {
            dfs(h, ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[j][i];
            maxH = max(maxH, adj[j][i]);
        }
    }

    for (int h = 0; h < maxH; h++)
    {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        safe = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] <= h || visited[i][j])
                {
                    continue;
                }
                dfs(h, i, j);
                safe++;
            }
        }

        ret = max(ret, safe);
    }
    
    cout << ret;

    return 0;
}