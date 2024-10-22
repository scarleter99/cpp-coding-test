#include <bits/stdc++.h>
using namespace std;

int n, l, r, sum, cnt, flag = 1;
int adj[54][54], visited[54][54];
int ret;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int>>& alli)
{
    visited[y][x] = 1;
    sum += adj[y][x];
    cnt++;
    alli.push_back({y, x});

    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]){
            continue;
        }
        
        int sub = abs(adj[ny][nx] - adj[y][x]);
        if (sub >= l && sub <= r){
            dfs(ny, nx, alli);
            flag = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    do {
        flag = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j])
                {
                    sum = 0;
                    cnt = 0;
                    vector<pair<int, int>> alli;

                    dfs(i, j, alli);

                    int temp = sum / cnt;
                    for (pair<int, int> p : alli)
                    {
                        adj[p.first][p.second] = temp;
                    }
                }
            }
        }

        if (flag == 1){
            ret++;
        }

    } while(flag);

    cout << ret;

    return 0;
}