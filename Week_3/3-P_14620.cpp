#include<bits/stdc++.h>
using namespace std;

int n;
int adj[14][14], visited[14][14];
int answer = 987654321;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int plusCost(int y, int x){
    int cost = adj[y][x];
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        cost += adj[ny][nx];
        visited[ny][nx] = 1;
    }

    return cost;
}

int minusCost(int y, int x){
    int cost = -adj[y][x];
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        cost += adj[ny][nx];
        visited[ny][nx] = 0;
    }

    return cost;
}

void algo(int y, int x, int cnt, int cost) {
    cout << "algo: " << y << " " << x  << " " << cnt << " " << cost << "\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    if (cnt == 3){
        answer = min(answer, cost);
        return;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j]){
                continue;
            }

            int flag = 0;
            for (int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]){
                    flag = 1;
                    continue;
                }
            }
            cout << "algo: " << i << " " << j  << " " << flag << "\n";
            if (flag){
                continue;
            }
            cost += plusCost(i, j);
            algo(i, j, cnt + 1, cost);
            cost += minusCost(i, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    for (int i = 1; i < n - 1; i++){
        for (int j = 1; j < n - 1; j++){
            algo(i, j, 1, plusCost(i, j));
            minusCost(i, j);
        }
    }

    cout << answer;

    return 0;
}