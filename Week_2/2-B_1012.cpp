#include <bits/stdc++.h>
using namespace std;

int t, m, n, k;
int ret;
int adj[54][54];
bool visited[54][54];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
        {
            continue;
        }

        if (adj[ny][nx] == 1)
        {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> m >> n >> k;

        fill(&adj[0][0], &adj[0][0] + 54 * 54, 0);
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        ret = 0;
        
        for (int i = 0; i < k; i++)
        {
            int y, x;
            cin >> x >> y;
            adj[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (adj[i][j] == 1 && !visited[i][j])
                {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }

    return 0;
}