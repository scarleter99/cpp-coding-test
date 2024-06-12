#include <bits/stdc++.h>
using namespace std;

int n, maxHeight, safe;
int adj[104][104];
bool visited[104][104];
int answer;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void algo(int h, int y, int x) {
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

        answer = max(answer, safe);
    }
    
    cout << answer;

    return 0;
}