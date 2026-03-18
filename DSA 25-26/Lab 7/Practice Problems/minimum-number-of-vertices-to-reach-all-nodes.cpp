/*
  Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge 
  from node fromi to node toi.
  Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
  Notice that you can return the vertices in any order.

  Concept: In a Directed Acyclic Graph (DAG), the only nodes you absolutely must start from are the ones that have no incoming edges. 
  All other nodes can be reached from these.
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n+1, 0);
        vector<int> ans;

        for(auto&e : edges)
            indeg[e[1]]++;

        for(int i = 0; i<n; i++)
        {
            if(indeg[i]==0)
            ans.push_back(i);
        }

        return ans;
    }
};
