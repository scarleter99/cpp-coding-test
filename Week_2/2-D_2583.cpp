#include <bits/stdc++.h>
using namespace std;

int m, n, k, areaSize, areaNum;
int adj[104][104];
bool visited[104][104];
vector<int> areaSizes;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = true;
    areaSize++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx])
        {
            continue;
        }

        if (adj[ny][nx] == 0)
        {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                adj[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 0 && visited[i][j] == false)
            {
                //cout << j << " " <<i << "\n";
                areaSize = 0;
                dfs(i, j);
                areaNum++;
                areaSizes.push_back(areaSize);
            }
        }
    }

    sort(areaSizes.begin(), areaSizes.end());

    cout << areaNum << "\n";
    for (int i : areaSizes)
    {
        cout << i << " ";
    }


    return 0;
}