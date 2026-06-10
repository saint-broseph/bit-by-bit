/*
  Given an undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai and bi. 
  We say two vertices u and v belong to a same component if there is a path from u to v or v to u. Find the number of connected components in the graph.
  A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex 
  outside of the subgraph.
*/

class Solution {
public:
    int countComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visited(V, 0);
        int components = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
              
                components++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
              
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                  for (auto &nbr : adj[node]) {
                        if (!visited[nbr]) {
                            visited[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return components;
    }
};
