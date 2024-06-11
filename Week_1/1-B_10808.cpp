#include <bits/stdc++.h>
using namespace std;

string str;
vector<int> counts(26);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (char alpha : str)
    {
        counts[alpha - 'a']++;
    }

    for (int cnt : counts)
    {
        cout << cnt << " ";
    }

    return 0;
}