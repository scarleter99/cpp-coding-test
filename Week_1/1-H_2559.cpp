#include <bits/stdc++.h>
using namespace std;

int N, K, temp;
int maxSum = -10000001;
vector<int> tempSums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N >> K;
    tempSums = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> temp;
        tempSums[i] = tempSums[i - 1] + temp;
    }

    for (int i = K; i <= N; i++)
    {
        maxSum = max(maxSum, tempSums[i] - tempSums[i - K]);
    }

    cout << maxSum;


    return 0;
}