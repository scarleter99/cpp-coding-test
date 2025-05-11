#include <bits/stdc++.h>
using namespace std;

int n, m;
char adj[54][54];
int visited[54][54], dp[54][54];
int ret;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

int algo(int y, int x){
    if (y < 0 || x < 0 || y >= n || x >= m || adj[y][x] == 'H'){
        return 0;
    }

    if (visited[y][x]){
        cout << -1 << "\n";
        exit(0);
    }

    int &temp = dp[y][x];
    if (temp){
        return temp;
    }

    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i] * (adj[y][x] - '0');
        int nx = x + dx[i] * (adj[y][x] - '0');

        temp = max(temp,algo(ny,nx) + 1);
    }
    visited[y][x] = 0;

    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            adj[i][j] = str[j];
        }
    }

    ret = algo(0, 0);

    cout << ret;

    return 0;
}