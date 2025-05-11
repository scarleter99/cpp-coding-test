#include <bits/stdc++.h>
using namespace std;

int n, m;
char adj[54][54];
int visited[54][54];
vector<pair<int, int>> lands;
int ret;

int dy[] = {-1, 0, 1, 0}; 
int dx[] = {0, 1, 0, -1}; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;

        for (int j = 0; j < m; j++){
            adj[i][j] = str[j];

            if (adj[i][j] == 'L'){
                lands.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < lands.size(); i++){
        int y = lands[i].first;
        int x = lands[i].second;

        queue<pair<int, int>> q;
        q.push({y, x});

        //memset(visited, 0, sizeof(visited)); 
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        visited[y][x] = 1;

        while(!q.empty()){
            tie(y, x) = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]){
                    continue;
                }

                if (adj[ny][nx] == 'L'){
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;

                    ret = max(ret, visited[ny][nx]);
                }
            }
        }
    }

    cout << ret - 1;

    return 0;
}