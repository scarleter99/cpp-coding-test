#include <bits/stdc++.h>
using namespace std;

int a, b, c;
vector<vector<int>> carTimes(3, vector<int>(2));
vector<int> carCnts(101);
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++)
    {
        cin >> carTimes[i][0] >> carTimes[i][1];
    }

    for (vector<int> carTime : carTimes)
    {
        for (int i = carTime[0]; i < carTime[1]; i++)
        {
            carCnts[i]++;
        }
    }

    for (int cnt : carCnts)
    {
        if (cnt == 1)
        {
            sum += cnt * a;
        }
        else if(cnt == 2)
        {
            sum += cnt * b;
        }
        else if (cnt == 3)
        {
            sum += cnt * c;
        }
    }

    cout << sum;

    return 0;
}