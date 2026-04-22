#include <iostream>
#include <vector>

using namespace std;

void adjacencyMatrix() {
    int n, m;
    cout << "Enter nodes and edges for Matrix: ";
    cin >> n >> m;

    // Adjacency Matrix: space complexity O(N^2)
    // Initialized to 0
    int adj[n + 1][n + 1] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove for directed graphs
    }
}

void adjacencyList() {
    int n, m;
    cout << "Enter nodes and edges for List: ";
    cin >> n >> m;

    // Adjacency List: space complexity O(2 * E)
    // Vector of vectors (array of vectors also works: vector<int> adj[n+1])
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove for directed graphs
    }
}

void weightedGraphList() {
    int n, m;
    cout << "Enter nodes and edges for Weighted List: ";
    cin >> n >> m;

    // Weighted Graph: Store {neighbor, weight}
    // Using a vector of vectors of pairs
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove for directed graphs
    }
}

int main() {
  return 0;
}
