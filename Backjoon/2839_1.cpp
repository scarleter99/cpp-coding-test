#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

int n, flag;
int ret, _min = 987654321;
int visited[5004];

void algo(int n, int cnt){
    if (visited[n]){
        return;
    }

    visited[n] = 1;

    if (n < 0){
        return;
    }
    else if (n == 0){
        flag = 1;
        _min = min(_min, cnt);
        return;
    }

    algo(n-5, cnt+1);
    algo(n-3, cnt+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    algo(n, 0);
    if (flag){
        ret = _min;
    }
    else{
        ret = -1;
    }
    
    cout << ret;

    return 0;
}