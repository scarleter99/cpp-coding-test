#include <bits/stdc++.h>
using namespace std;

int n, sum, lo, hi;
int che[4000004];
vector<int> v;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for (int i = 2; i <= sqrt(n); i++){
        if (che[i]){
            continue;
        }
        for (int j = i * i; j <= n; j += i){
            che[j] = 1;
        }
    }

    for (int i = 2; i <= n; i++){
        if (!che[i]){
            v.push_back(i);
        }
    }

    while(1){
        if (sum >= n){
            sum -= v[lo];
            lo++;
        }
        else if(hi == v.size()){
            break;
        }
        else {
            sum += v[hi];
            hi++;
        }

        if(sum == n){
            ret++;
        }
    }

    cout << ret;

    return 0;
}