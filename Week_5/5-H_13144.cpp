#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, lo, hi;
ll a[100004], cnt[100004];
ll answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    while(hi < n){
        if (!cnt[a[hi]]){
            cnt[a[hi]]++;
            hi++;
        }
        else{
            answer += hi - lo;
            cnt[a[lo]]--;
            lo++;
        }
    }
    
    answer += ((hi - lo) * (hi - lo + 1) / 2);

    cout << answer;

    return 0;
}