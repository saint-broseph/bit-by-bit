class Solution {
public:
    void bfs(int start, std::vector<int> adj[], 
             std::vector<int>& visited, 
             std::vector<int>& result) {
        
        std::queue<int> q;

        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            result.push_back(v);

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = 1; 
                    q.push(u);
                }
            }
        }
    }
};
