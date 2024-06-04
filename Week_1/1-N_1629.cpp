#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;
ll answer;

ll algo(ll b)
{
    if (b == 1)
    {
        return a % c;
    }

    ll ret = (algo(b / 2) * algo(b / 2)) % c;

    if (b % 2)
    {
        ret = (ret * a) % c;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    cin >> a >> b >> c;
    
    answer = algo(b);

    cout << answer;

    return 0;
}