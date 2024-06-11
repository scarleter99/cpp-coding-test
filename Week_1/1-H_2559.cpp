#include <bits/stdc++.h>
using namespace std;

int n, k, temp;
int maxSum = -10000001;
vector<int> tempSums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    tempSums = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        tempSums[i] = tempSums[i - 1] + temp;
    }

    for (int i = k; i <= n; i++)
    {
        maxSum = max(maxSum, tempSums[i] - tempSums[i - k]);
    }

    cout << maxSum;


    return 0;
}