#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[104];
set<int> on;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    if (n >= k){
        cout << 0;
        return 0;
    }

    for (int i = 0; i < k; i++){
        cin >> a[i];
    }

    for (int i = 0; i < k; i++){
        int temp = a[i];
        if (on.size() < n){
            on.insert(temp);
            continue;
        }

        if (on.count(temp)){
            continue;
        }

        set<int> onTemp(on);
        for (int j = i + 1; j < k; j++){
            if (onTemp.size() <= 1){
                break;
            }
            if (onTemp.count(a[j])){
                onTemp.erase(a[j]);
            }
        }

        on.erase(*onTemp.begin());
        on.insert(temp);
        ret++;
    }
    
    cout << ret;

    return 0;
}