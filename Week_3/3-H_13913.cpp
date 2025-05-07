#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[200004], history[200004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    queue<int> q;

    q.push(n);
    visited[n] = 1;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for (int next : {temp + 1, temp - 1, temp * 2}){
            if(next >= 200004 || next < 0 || visited[next]){ 
                continue;
            }

            visited[next] = visited[temp] + 1;
            history[next] = temp;
            q.push(next);
        }
    }

    cout << visited[k] - 1 << "\n";

    vector<int> v;
    for(int i = k; i != n; i = history[i]){
        v.push_back(i);
    }

    v.push_back(n);

    reverse(v.begin(), v.end());

    for (int i : v){
        cout << i << " ";
    }

    return 0;
}