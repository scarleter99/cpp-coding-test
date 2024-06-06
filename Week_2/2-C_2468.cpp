#include <bits/stdc++.h>
using namespace std;

int n, maxHeight, safe, maxSafe;
int adj[104][104];
bool visited[104][104];
int answer;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int algo(int h, int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i ++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
        {
            continue;
        }

        if (adj[ny][nx] > h && visited[ny][nx] == false)
        {
            algo(h, ny, nx);
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[j][i];
            maxHeight = max(maxHeight, adj[j][i]);
        }
    }

    for (int h = 0; h < maxHeight; h++)
    {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        safe = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] > h && visited[i][j] == false)
                {
                    algo(h, i, j);
                    safe++;
                }
            }
        }

        maxSafe = max(maxSafe, safe);
    }
    
    cout << maxSafe;

    return 0;
}