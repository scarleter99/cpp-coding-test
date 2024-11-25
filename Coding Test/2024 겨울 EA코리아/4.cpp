#include <bits/stdc++.h> 
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int N = edges.size() + 1; // Number of nodes
    vector<vector<int>> adj(N + 1); // Adjacency list
    vector<int> degree(N + 1, 0); // Degree of each node
    vector<int> answer;
    set<int> leaves; // Set of current leaf nodes (ordered)

    // Build the adjacency list and degree count
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Initialize the leaves set with nodes of degree 1
    for (int i = 1; i <= N; ++i) {
        if (degree[i] == 1 || degree[i] == 0) { // Include isolated nodes
            leaves.insert(i);
        }
    }

    // Process the tree
    while (!leaves.empty()) {
        int node = *leaves.begin(); // Get the smallest leaf node
        leaves.erase(leaves.begin());
        answer.push_back(node);
        degree[node] = 0; // Mark as removed

        // Update degrees of neighbors
        for (int neighbor : adj[node]) {
            if (degree[neighbor] > 0) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    leaves.insert(neighbor);
                }
            }
        }
    }

    return answer;
}

int main() {
    // Test case 1
    vector<vector<int>> edges1 = {{1, 4}, {4, 5}, {5, 2}, {2, 3}, {2, 6}};
    vector<int> result1 = solution(edges1);
    cout << "Output for Test Case 1: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i];
        if (i != result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // Test case 2
    vector<vector<int>> edges2 = {{2, 1}, {1, 3}};
    vector<int> result2 = solution(edges2);
    cout << "Output for Test Case 2: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i];
        if (i != result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
