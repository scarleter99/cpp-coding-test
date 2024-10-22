#include <bits/stdc++.h>
using namespace std;

string str, strRev;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    ret = 0;
    
    strRev = str;
    reverse(strRev.begin(), strRev.end());

    if (str == strRev)
    {
        ret = 1;
    }

    cout << ret;

    return 0;
}