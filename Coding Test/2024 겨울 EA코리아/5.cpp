#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n, m;
vector<vector<int>> tree;
vector<int> isLeaked;
vector<int> totalNormal;
vector<int> dp[501];

void dfs(int u) {
    totalNormal[u] = isLeaked[u] ? 0 : 1;
    dp[u].assign(m + 2, INF);

    // Option to terminate at u
    dp[u][1] = totalNormal[u];

    // Option to not terminate at u
    dp[u][0] = 0; // No signals used yet

    for (int v : tree[u]) {
        dfs(v);

        vector<int> new_dp(m + 2, INF);
        for (int k1 = 0; k1 <= m + 1; ++k1) {
            if (dp[u][k1] == INF) continue;
            for (int k2 = 0; k2 <= m + 1 - k1; ++k2) {
                if (dp[v][k2] == INF) continue;
                int k_total = k1 + k2;
                if (k_total <= m + 1) {
                    new_dp[k_total] = min(new_dp[k_total], dp[u][k1] + dp[v][k2]);
                }
            }
        }
        dp[u] = new_dp;
    }

    if (isLeaked[u]) {
        dp[u][0] = INF; // Cannot have dp[u][0], as u needs to be covered
    }
}

vector<int> solution(vector<vector<int>> edges, vector<int> leaked) {
    n = edges.size() + 1;
    m = leaked.size();
    tree.assign(n + 1, vector<int>());
    isLeaked.assign(n + 1, 0);
    totalNormal.assign(n + 1, 0);

    // Build the tree
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        tree[u].push_back(v);
    }

    // Mark leaked processes
    for (int x : leaked) isLeaked[x] = 1;

    // Perform DFS to compute dp arrays
    dfs(1);

    vector<int> result(m);
    int minNormal = INF;
    for (int k = 1; k <= m; ++k) {
        minNormal = min(minNormal, dp[1][k]);
        result[k - 1] = minNormal;
    }
    return result;
}

int main() {
    vector<vector<int>> edges1 = {{1,2},{1,6},{2,3},{6,7},{3,4},{3,9},{4,5},{5,8}};
    vector<int> leaked1 = {5,7,9};
    vector<int> result1 = solution(edges1, leaked1);
    for(int num : result1) cout << num << " ";
    cout << endl; // Expected Output: 6 3 1

    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{4,5}};
    vector<int> leaked2 = {3,4,5};
    vector<int> result2 = solution(edges2, leaked2);
    for(int num : result2) cout << num << " ";
    cout << endl; // Expected Output: 0 0 0

    vector<vector<int>> edges3 = {{1,2},{1,3},{2,4},{4,5},{2,6},{6,7},{3,8},{3,9},{3,10},{8,11},{11,14},{9,12},{12,15},{10,13},{13,16}};
    vector<int> leaked3 = {5,7,14,15,16};
    vector<int> result3 = solution(edges3, leaked3);
    for(int num : result3) cout << num << " ";
    cout << endl; // Expected Output: 11 10 7 3 0

    return 0;
}
