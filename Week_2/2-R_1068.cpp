#include <bits/stdc++.h>
using namespace std;

int n, cnt, node;
vector<int> adj[54];
int adj2[54], isParent[54];

void algo(int node)
{
    if (adj[node].size() <= 0)
    {
        cnt--;
        return;
    }

    for (int i : adj[node])
    {
        algo(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cnt = n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 0)
        {
            continue;
        }

        adj[temp].push_back(i);
        adj2[i] = temp;
        if (isParent[temp] == 0)
        {
            isParent[temp] = 1;
            cnt--;
        }
    }

    cin >> node;

    if (adj[adj2[node]].size() == 1)
    {
        cnt++;
    }

    algo(node);

    cout << cnt;

    return 0;
}