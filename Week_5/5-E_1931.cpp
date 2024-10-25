#include <bits/stdc++.h>
using namespace std;

int n, from, to, now;
vector<pair<int, int>> v;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from});
    }

    sort(v.begin(), v.end());

    for (auto p : v){
        tie(to, from) = p;
        if (now > from){
            continue;
        }

        now = to;
        answer++;
    }

    cout << answer;
}