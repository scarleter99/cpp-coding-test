#include <bits/stdc++.h>
using namespace std;

string name;
vector<int> alphaCnts(200);
char mid;
int flag;
string ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> name;

    for (char alpha : name)
    {
        alphaCnts[alpha]++;
    }

    for (int i = 'Z'; i >= 'A'; i--)
    {
        if (alphaCnts[i])
        {
            if (alphaCnts[i] % 2 == 1)
            {
                alphaCnts[i]--;
                flag++;
                mid = i;

                if (flag > 1)
                {
                    break;
                }
            }

            for(int j = alphaCnts[i]; j > 0; j -= 2)
            {
                ret = (char)i + ret;
                ret += i;
            }
        }
    }

    if (flag > 1)
    {
        ret = "I'm Sorry Hansoo";
    }

    if (flag == 1)
    {
        ret.insert(ret.begin() + (ret.size() / 2), mid);
    }

    cout << ret;

    return 0;
}