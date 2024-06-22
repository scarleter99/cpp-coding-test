#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, maxCnt, answerCnt;
vector<int> adj[10004];
int visited[10004];
vector<int> answer;

void algo(int com)
{
    visited[com] = 1;
    cnt++;

    for (int i : adj[com])
    {
        if (!visited[i])
        {
            algo(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        fill(visited, visited + n + 1, 0);

        algo(i);

        if (cnt > maxCnt)
        {
            answer.push_back(i);
            answerCnt = 1;
            maxCnt = cnt;
        }

        else if (cnt == maxCnt)
        {
            answer.push_back(i);
            answerCnt++;
        }
    }
    while (answerCnt)
    {
        cout << answer[answer.size() - answerCnt] << " ";
        answerCnt--;
    }

    return 0;
}