#include <bits/stdc++.h>
using namespace std;

int h, w, last;
int joi[104][104];
int ret[104][104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        string line;
        cin >> line;

        last = -1;
        for (int j = 0; j < w; j++)
        {
            if (line[j] == 'c')
            {
                last = 0;
            }
            else if (last >= 0)
            {
                last++;
            }

            cout << last << " ";
        }

        cout << "\n";
    }

    return 0;
}