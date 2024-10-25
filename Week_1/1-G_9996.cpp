#include <bits/stdc++.h>
using namespace std;

int n;
string pat, file, pre, suf;
string ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> pat;

    int pos = pat.find('*');
    pre = pat.substr(0, pos);
    suf = pat.substr(pos + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> file;

        ret = "DA";

        if (file.size() < pre.size() + suf.size())
        {
            ret = "NE";
        }
        else if (pre != file.substr(0, pre.size()) || suf != file.substr(file.size() - suf.size()))
        {
            ret = "NE";
        }

        cout << ret << "\n";
    }

    return 0;
}