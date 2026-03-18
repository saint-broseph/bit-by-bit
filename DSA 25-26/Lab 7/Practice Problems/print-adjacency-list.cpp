/*
  Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.
    Input:
    V = 5, E = 7
    edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]
    Output: 
    [[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
*/

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(const auto& edge: edges)
        {
            int u = edge.first;
            int v = edge.second;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};
