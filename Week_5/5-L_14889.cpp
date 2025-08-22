#include <bits/stdc++.h>
using namespace std;

int n;
int adj[24][24], team[24];
int ret = 987654321;

int subT(){
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(team[i] && team[j]){
                a += adj[i][j] + adj[j][i];
            }

            if(team[i] == 0 && team[j] == 0){
                b += adj[i][j] + adj[j][i];
            }
        }
    }

    return abs(a - b);
}

void combi(int s, int cnt){
    if(cnt == n / 2){
        ret = min(ret, subT());
        return;
    }

    for(int i = s + 1; i <= n; i++){
        team[i] = 1;
        combi(i, cnt + 1);
        team[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adj[i][j];
        }
    }

    combi(0, 0);

    cout << ret;

    return 0;
}