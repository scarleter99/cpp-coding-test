#include <bits/stdc++.h>
using namespace std;

int N;
string str;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N;

    while(N--)
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
            answer++;
        }
    }

    cout << answer;

    return 0;
}