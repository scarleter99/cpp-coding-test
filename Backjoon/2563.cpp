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
                if (!adj[j][k]){
                    adj[j][k] = 1;
                    ret++;
                }
            }
        }
    }

    cout << ret;

    return 0;
}