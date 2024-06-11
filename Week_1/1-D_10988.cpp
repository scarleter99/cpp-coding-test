#include <bits/stdc++.h>
using namespace std;

string str, strRev;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    answer = 0;
    
    strRev = str;
    reverse(strRev.begin(), strRev.end());

    if (str == strRev)
    {
        answer = 1;
    }

    cout << answer;

    return 0;
}