#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n;
int adj[16][16], dp[16][1 << 16];
int ret;

int algo(int node, int mask){
    if(mask == (1 << n) - 1){
        return adj[node][0] ? adj[node][0] : INF;
    }

    if (dp[node][mask] != -1){
        return dp[node][mask];
    }

    int _min = INF;
    for (int i = 0; i < n; i++){
        if ((1 << i) & mask){
            continue;
        }
        if (adj[node][i] == 0){
            continue;
        }

        _min = min(_min, algo(i , mask | (1 << i)) + adj[node][i]);
    }

    dp[node][mask] = _min;

    return _min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + 16 * (1 << 16), -1);

    ret = algo(0, 1);
    cout << ret;

    return 0;
}