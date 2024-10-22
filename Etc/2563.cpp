#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int adj[104][104];
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x >> y;

        for (int j = x; j < x + 10; j++){
            for (int k = y; k < y + 10; k++){
                adj[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (adj[i][j]){
                ret++;
            }
        }
    }

    cout << ret;

    return 0;
}