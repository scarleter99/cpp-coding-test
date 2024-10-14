#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        pq.push(v[i].second);
        if (pq.size() > v[i].first){
            pq.pop();
        }
    }

    while(pq.size()){
        answer += pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}