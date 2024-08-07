#include <bits/stdc++.h>
using namespace std;

int n, m, safeTemp, maxSafe, safe;
int adj[12][12], adjTemp[12][12];
vector<pair<int, int>> safeZone;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    adjTemp[y][x] = 2;

    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m){
            continue;
        }

        if (adjTemp[ny][nx] == 0){
            safeTemp--;
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> adj[i][j];

            if (adj[i][j] == 0){
                safeZone.push_back({i, j});
                safe++;
            }
        }
    }

    for (int i = 0; i < safeZone.size(); i++){
        for (int j = i + 1; j < safeZone.size(); j++){
            for (int k = j + 1; k < safeZone.size(); k++){
                safeTemp = safe - 3;

                for (int l = 0; l < n; l++){
                    copy(adj[l], adj[l] + m, adjTemp[l]);
                }

                adjTemp[safeZone[i].first][safeZone[i].second] = 1;
                adjTemp[safeZone[j].first][safeZone[j].second] = 1;
                adjTemp[safeZone[k].first][safeZone[k].second] = 1;

                for (int y = 0; y < n; y++){
                    for (int x = 0; x < m; x++){
                        if (adjTemp[y][x] == 2){
                            dfs(y, x);
                        }
                    }
                }

                maxSafe = max(maxSafe, safeTemp);
            }
        }
    }

    cout << maxSafe;
    
    return 0;
}