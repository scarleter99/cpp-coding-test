#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;
ll ret;

ll algo(ll b){
    if (b == 1){
        return a % c;
    }

    ll ret = algo(b / 2);
    ret = ret * ret % c;
    if (b % 2){
        ret = (ret * a) % c;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b >> c;
    
    ret = algo(b);

    cout << ret;

    return 0;
}