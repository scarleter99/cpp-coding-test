#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, m, v, c;
vector<pair<ll, ll>> mv;
vector<ll> cv;
priority_queue<ll> pq;
ll ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> m >> v;
        mv.push_back({m, v});
    }

    for (int i = 0; i < k; i++){
        cin >> c;
        cv.push_back(c);
    }

    sort(mv.begin(), mv.end());
    sort(cv.begin(), cv.end());

    int j = 0;
    for (int i = 0; i < k; i++){
        for (; j < n; j++){
            if (mv[j].first <= cv[i]){
                pq.push(mv[j].second);
                continue;
            }
            break;
        }

        if(pq.size()) // while 아님
        {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret;
    return 0;
}