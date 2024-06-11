#include <bits/stdc++.h>
using namespace std;

vector<int> heights(10);
vector<int> heightSums(10);
vector<int> lierIdxs(2);

int algo() {
    int diff = heightSums[9] - 100;
    sort(heights.begin(), heights.end());

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (heights[i] + heights[j] == diff)
            {
                lierIdxs[0] = i;
                lierIdxs[1] = j;
                return 0;
            }
        }
    }

    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < 10; i++)
    {
        cin >> heights[i];
        heightSums[i] = heights[i] + heightSums[i - 1];
    }

    algo();

    for (int i = 1; i < 10; i++)
    {
        if (find(lierIdxs.begin(), lierIdxs.end(), i) != lierIdxs.end())
        {
            continue;
        }

        cout << heights[i] << "\n";
    }

    return 0;
}