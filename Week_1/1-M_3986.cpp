#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n--)
    {
        cin >> str;
        stack<char> alphaStk;

        for (char alpha : str)
        {
            if (alphaStk.size() && alphaStk.top() == alpha)
            {
                alphaStk.pop();
            }
            else
            {
                alphaStk.push(alpha);
            }
        }

        if (alphaStk.size() == 0)
        {
            ret++;
        }
    }

    cout << ret;

    return 0;
}