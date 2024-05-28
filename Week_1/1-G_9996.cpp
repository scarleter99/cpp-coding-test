#include <bits/stdc++.h>
using namespace std;

int N;
string pat, file, pre, suf;
string answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N;
    cin >> pat;

    int pos = pat.find('*');
    pre = pat.substr(0, pos);
    suf = pat.substr(pos + 1);

    for (int i = 0; i < N; i++)
    {
        cin >> file;

        answer = "DA";

        if (file.size() < pre.size() + suf.size())
        {
            answer = "NE";
            return 0;
        }

        if (pre != file.substr(0, pre.size()) || suf != file.substr(file.size() - suf.size()))
        {
            answer = "NE";
        }

        cout << answer << "\n";
    }

    return 0;
}