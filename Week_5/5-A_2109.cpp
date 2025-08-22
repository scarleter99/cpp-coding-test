#include <bits/stdc++.h>
using namespace std;

int ret = 0;
int n;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int d, p;
        cin >> d >> p;
        v.push_back({p, d});
    }

    sort(v.begin(), v.end());
    for (pair<int, int> p : v){
        pq.push(p.second);
        while (pq.size() > p.first){
            pq.pop();
        }
    }

    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }

    cout << ret;

    return 0;
}