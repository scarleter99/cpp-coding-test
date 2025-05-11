#include <bits/stdc++.h>
using namespace std;

int n, m, y, x;
string line;
int adj[104][104];
int visited[104][104];
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            adj[i][j] = line[j] - '0';
        }
    }

    q.push({0, 0});
    visited[0][0]++;
    while(!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();
        
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
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }

    cout << visited[n - 1][m - 1];

    return 0;
}