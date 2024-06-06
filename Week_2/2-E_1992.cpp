#include <bits/stdc++.h>
using namespace std;

int n;
char adj[68][68];
string answer;

int algo(int y, int x, int size)
{
    char temp = adj[y][x];

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (temp != adj[i][j])
            {
                answer += "(";
                int nSize = size / 2;
                algo(y, x, nSize);
                algo(y, x + nSize, nSize);
                algo(y + nSize, x, nSize);
                algo(y + nSize, x + nSize, nSize);
                answer += ")";
                return 0;
            }
        }
    }
    
    answer += temp;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = line[j];
        }
    }

    algo(0, 0, n);

    cout << answer;

    return 0;
}