class Solution {
public:
    void dfs(int v, vector<int> adj[], 
             vector<int>& visited, 
             vector<int>& result) {
        
        visited[v] = 1;

        result.push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, adj, visited, result);
            }
        }
    }
};
