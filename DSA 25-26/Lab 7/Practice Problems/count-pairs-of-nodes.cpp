/*
  You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, 
  where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
  Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
  The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
    a < b
    incident(a, b) > queries[j]
  Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
  Note that there can be multiple edges between the same two nodes.

  Concept: This problem asks for pairs (u, v) where degree[u] + degree[v] - shared_edges(u, v) > query. A brute force approach fails the time limits. 
  We use a two-pointer approach on a sorted degree array to quickly find pairs where degree[u] + degree[v] > query, and then subtract pairs that falsely passed 
  this check because of shared edges.
*/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

        vector<int> deg(n+1, 0);
        unordered_map<int, int> shared;

        for(auto& edge: edges)
        {
            int u = min(edge[0], edge[1]);
            int v = max(edge[0], edge[1]);
            deg[u]++;
            deg[v]++;
            shared[u*100000+v]++;
        }

        vector<int> sortdeg = deg;
        sort(sortdeg.begin(), sortdeg.end());

        vector<int> ans(queries.size());

        for(int q = 0; q < queries.size(); q++)
        {
            int count = 0;
            int target = queries[q];

            for(int left = 1, right = n; left < right; )
            {
                if(sortdeg[left] + sortdeg[right] > target)
                {
                    count += (right - left);
                    right--;
                }
                else 
                {
                    left++;
                }
            }

            for(auto& [encoded, freq] : shared)
            {
                int u = encoded/100000;
                int v = encoded%100000;

                if(deg[u]+deg[v]>target && deg[u]+deg[v]-freq<=target)
                count--;
            }
            ans[q] = count;
        }
        return ans;
        
    }
};
