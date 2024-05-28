#include <bits/stdc++.h>
using namespace std;

string str, answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    getline(cin, str);
    for (char c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            answer += (c + 13 <= 'Z' ? c + 13 : c - 13);
            continue;
        }
        else if (c >= 'a' && c <= 'z')
        {
            answer += (c + 13 <= 'z' ? c + 13 : c - 13);
            continue;
        }

        answer += c;
    }

    cout << answer;

    return 0;
}