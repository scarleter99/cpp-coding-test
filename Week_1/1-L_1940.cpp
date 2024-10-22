#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ings;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    ings = vector<int>(n);

    for(int i = 0; i < n; i++)
    {
        cin >> ings[i];

        for (int j = 0; j < i; j++)
        {
            if (ings[j] == -1)
            {
                continue;
            }
            
            if (ings[i] + ings[j] == m)
            {
                ret++;
                ings[i] = -1;
                ings[j] = -1;
                break;
            }
        }
    }

    cout << ret;

    return 0;
}