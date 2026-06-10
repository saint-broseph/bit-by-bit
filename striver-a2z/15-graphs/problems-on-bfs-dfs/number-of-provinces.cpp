/*
  There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, 
  then city a is connected indirectly with city c. A province is a group of directly or indirectly connected cities and no other cities outside of the group.
  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
  Return the total number of provinces.

  We can see that two cities x and y belong to the same province if there is a path from city x to city y using the cities that are directly connected.
  This leads us to consider the problem in terms of graphs.
  Each city can be thought of as a node in a graph. The roads that directly connect the cities are the edges. 
  If there is a path in this graph connecting cities x and y, then x and y are in the same province. Because the graph is undirected, x and y 
  belong to the same province if and only if they are part of the same graph component.
  The number of required provinces is the number of connected components formed in such a graph.
  To check the number of connected components in a graph, we can use a graph traversal algorithm like depth first search (DFS).
*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};
