#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

int n, flag;
int ret = 987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < 5; i++){
        int temp = n;
        temp -= 3 * i;

        if (temp < 0 || temp % 5 != 0){
            continue;
        }

        ret = min(ret, i + (temp / 5));
    }

    if(ret == 987654321){
        cout << -1;
    }
    else{
        cout << ret;
    }

    return 0;
}