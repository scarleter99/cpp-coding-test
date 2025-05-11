#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n;
ll dp[100][100];

ll algo(ll n, ll h){
    if (n == 0 && h == 0){
        return 1;
    }

    ll &ret = dp[n][h];

    if (ret != 0){
        return ret;
    }

    ret = 0;
    if (n){
        ret += algo(n - 1, h + 1);
    }
    if (h){
        ret += algo(n, h - 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n){
        if (n == 0){
            break;
        }
        cout << algo(n, 0) << "\n";
    }

    return 0;
}