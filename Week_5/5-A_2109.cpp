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
        int p, d;
        cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end());
    for (pair<int, int> i : v){
        pq.push(i.second);
        while (pq.size() > i.first){
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