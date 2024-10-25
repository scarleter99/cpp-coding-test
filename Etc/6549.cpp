#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        stack<int> s;
        ll ret = 0;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && v[s.top()] > v[i]) {
                ll h = v[s.top()];
                s.pop();

                ll w = i;
                if (s.size()){
                    w -= s.top() + 1;
                }

                ret = max(ret, h * w);
            }
            s.push(i);
        }

        while (!s.empty()) {
            ll h = v[s.top()];
            s.pop();

            ll w = n;
            if (s.size()){
                w -= s.top() + 1;
            }

            ret = max(ret, h * w);
        }

        cout << ret << "\n";
    }

    return 0;
}