#include <bits/stdc++.h>
using namespace std;

int r, c, t, ry;
int adj[1004][1004], temp[1004][1004];
int ret;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

void move(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || adj[ny][nx] == -1){
            continue;
        }

        temp[ny][nx] += adj[y][x] / 5;
        temp[y][x] -= adj[y][x] / 5;
    }
}

void clean(){
    int ny = ry - 2;
    int nx = 0;

    while(ny > 0){
        adj[ny][nx] = adj[ny - 1][nx];
        ny--;
    }

    while(nx < c - 1){
        adj[ny][nx] = adj[ny][nx + 1];
        nx++;
    }

    while(ny < ry - 1){
        adj[ny][nx] = adj[ny + 1][nx];
        ny++;
    }

    while(nx > 0){
        adj[ny][nx] = adj[ny][nx - 1];
        if (adj[ny][nx] == -1){
            adj[ny][nx] = 0;
        }
        nx--;
    }

    ny = ry + 1;
    nx = 0;

    while(ny < r - 1){
        adj[ny][nx] = adj[ny + 1][nx];
        ny++;
    }

    while(nx < c - 1){
        adj[ny][nx] = adj[ny][nx + 1];
        nx++;
    }

    while(ny > ry){
        adj[ny][nx] = adj[ny - 1][nx];
        ny--;
    }

    while(nx > 0){
        adj[ny][nx] = adj[ny][nx - 1];
        if (adj[ny][nx] == -1){
            adj[ny][nx] = 0;
        }
        nx--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> adj[i][j];
            if (adj[i][j] == -1){
                ry = i;
            }
        }
    }

    while(t--){
        fill(&temp[0][0], &temp[0][0] + 1004 * 1004, 0);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if (adj[i][j] == -1){
                    continue;
                }

                move(i, j);
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if (adj[i][j] == -1){
                    continue;
                }

                adj[i][j] += temp[i][j];
            }
        }

        clean();
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if (adj[i][j] == -1){
                continue;
            }
            ret += adj[i][j];
        }
    }
    
    cout << ret;

    return 0;
}