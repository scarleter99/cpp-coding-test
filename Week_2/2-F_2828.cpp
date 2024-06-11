#include <bits/stdc++.h>
using namespace std;

int n, m, j, l = 1, r;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> j;

    for (int i = 0; i < j; i++)
    {
        r = l + m - 1;

        int temp;
        cin >> temp;

        if (temp < 1 || temp > n)
        {
            continue;
        }

        if (temp < l)
        {
            answer += l - temp;
            l -= l - temp;
        }
        else if(temp >= r)
        {
            answer += temp - r;
            l += temp - r;
        }
    }

    cout << answer;

    return 0;
}