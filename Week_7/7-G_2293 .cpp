#include <cstdio>
#include <vector> 
#include <iostream>
using namespace std;

int dp[10001];  
int n, k;
int coins[101];

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int coin = coins[i];
        for(int now = coin; now <= k; now++){
            dp[now] += dp[now - coin];
        }
    }

    cout << dp[k];
}