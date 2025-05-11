#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
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

    for (auto p : v){
        int a, b;
        tie(a, b) = p;
        if (answer < a){
            answer = a + b;
        }
        else{
            answer += b;
        }
    }

    cout << answer;

    return 0;
}