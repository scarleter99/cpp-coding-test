#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n){
        if (n == 0){
            break;
        }

        ll h = 0, _max = 0, _min = 0;
        stack<ll> st, st2;
        ll ret = 0;
        
        for (int i = 0; i < n; i++){
            cin >> h;
            _max = max(_max, h);
            _min = min(_min, h);
            
            ll w = 1;
            while (st.size() && h < st.top()){
                w++;
                st.pop();
            }

            while (st.size() && h >= st.top()){
                w++;
                ret = max(ret, st.top() * w);

                st2.push(st.top());
                st.pop();
            }

            while(st2.size()){
                st.push(st2.top());
                st2.pop();
            }

            st.push(h);
        }

        ret = max(ret, n * _min);
        ret = max(ret, _max);
        cout << ret << "\n";
    }

    return 0;
}