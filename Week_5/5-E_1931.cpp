#include <bits/stdc++.h>
using namespace std;

int n, lo, hi, now;
vector<pair<int, int>> v;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> lo >> hi;
        v.push_back({hi, lo});
    }

    sort(v.begin(), v.end());

    for (auto p : v){
        tie(hi, lo) = p;
        if (now > lo){
            continue;
        }

        now = hi;
        answer++;
    }

    cout << answer;
}