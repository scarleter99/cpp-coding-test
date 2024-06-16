#include <bits/stdc++.h>
using namespace std;

int n, cnt, seq6, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int i;
    for (i = 666; cnt < n; i++)
    {
        seq6 = 0;
        temp = i;

        while(temp > 0)
        {
            if (temp % 10 == 6)
            {
                seq6++;
                if (seq6 >= 3)
                {
                    cnt++;
                    break;
                }
            }
            else
            {
                seq6 = 0;
            }

            temp /= 10;
        }
    }

    cout << i - 1;

    return 0;
}