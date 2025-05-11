#include <bits/stdc++.h>
using namespace std;

string str, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, str);
    for (char c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            ret += (c + 13 <= 'Z' ? c + 13 : c - 13);
            continue;
        }
        else if (c >= 'a' && c <= 'z')
        {
            ret += (c + 13 <= 'z' ? c + 13 : c - 13);
            continue;
        }

        ret += c;
    }

    cout << ret;

    return 0;
}