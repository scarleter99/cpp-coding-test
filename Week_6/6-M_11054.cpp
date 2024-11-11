#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        if(it == lis.end()){
            lis.push_back(v[i]);
        }
        else{
            *it = v[i];
        }
    }

    cout << lis.size();

    return 0;
}