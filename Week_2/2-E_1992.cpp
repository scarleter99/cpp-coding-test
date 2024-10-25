#include <bits/stdc++.h>
using namespace std;

int n;
char adj[68][68];
string ret;

void dfs(int y, int x, int size)
{
    char temp = adj[y][x];

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (temp != adj[i][j])
            {
                ret += "(";
                int nSize = size / 2;
                dfs(y, x, nSize);
                dfs(y, x + nSize, nSize);
                dfs(y + nSize, x, nSize);
                dfs(y + nSize, x + nSize, nSize);
                ret += ")";
                return;
            }
        }
    }
    
    ret += temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    dfs(0, 0, n);

    cout << ret;

    return 0;
}