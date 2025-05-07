#include <bits/stdc++.h>
using namespace std;

int n;
int adj[24][24];
int ret = 987654321;

int subT(vector<int> v){
    int a = 0, b = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (find(v.begin(), v.end(), i) != v.end() && find(v.begin(), v.end(), j) != v.end()){
                a += adj[i][j];
            }
            else if (find(v.begin(), v.end(), i) == v.end() && find(v.begin(), v.end(), j) == v.end()){
                b += adj[i][j];
            }
        }
    }

    return abs(a - b);
}

void combi(int s, int cnt, vector<int> v){
    if (cnt == n / 2){
        ret = min(ret, subT(v));
        return;
    }

    for(int i = s + 1; i <= n; i++){
        v.push_back(i);
        combi(i, cnt + 1, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> adj[i][j];
        }
    }

    vector<int> v;
    combi(0, 0, v);

    cout << ret;

    return 0;
}