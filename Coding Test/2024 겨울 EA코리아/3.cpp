#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = LLONG_MAX; // Use the maximum value for long long
int MOD = 1e9 + 7;

int solution(string num, int k) {
    int n = num.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++){
            for(int l = 1; l <= min(9, i); l++) {
                int temp = i - l;
                ll val = stoll(num.substr(temp, l));

                if (j == 0) {
                    if (temp != 0) continue;
                    dp[i][j] = val; // Initialize dp[i][0] directly
                } else {
                    if (dp[temp][j - 1] == INF) continue;
                    if (dp[temp][j - 1] + val < dp[i][j]){
                        dp[i][j] = dp[temp][j - 1] + val;
                    }
                }
            }
        }
    }

    ll ret = INF;
    for (int i = 0; i <= k; i++){
        if (dp[n][i] < ret){
            ret = dp[n][i];
        }
    }

    return static_cast<int>(ret % MOD);
}

int main() {
    string num1 = "1234567";
    int k1 = 2;
    cout << solution(num1, k1) << endl << endl; // Output: 235

    string num2 = "555555";
    int k2 = 2;
    cout << solution(num2, k2) << endl << endl; // Output: 165

    string num3 = "91911919";
    int k3 = 3;
    cout << solution(num3, k3) << endl << endl; // Output: 165

    return 0;
}
