#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int adj[34][34];
int ret = 987654321;

bool check(){
    for (int x = 1; x <= n; x++){
        int temp = x;
        for (int y = 1; y <= h; y++){
            if (adj[y][temp]){
                temp++;
            }
            else if(adj[y][temp-1]){
                temp--;
            }
        }

        if (temp != x){
            return false;
        }
    }

    return true;
}

void algo(int num, int cnt){
    if (cnt > 3 || cnt >= ret){
        return;
    }

    if (check()){
        ret = min(ret, cnt);
        return;
    }

    for(int i = num; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(adj[i][j] || adj[i][j - 1] || adj[i][j + 1]) {
                continue;
            }
            adj[i][j] = 1;
            algo(i, cnt + 1);
            adj[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++){
        int y, x;
        cin >> y >> x;
        adj[y][x] = 1;
    }

    algo(1, 0);

    if (ret > 3){
        cout << -1;
    }
    else{
        cout << ret;
    }

    return 0;
}