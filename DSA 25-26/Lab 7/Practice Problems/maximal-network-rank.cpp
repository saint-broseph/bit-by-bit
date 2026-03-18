/*
  There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional 
  road between cities ai and bi. The network rank of two different cities is defined as the total number of directly connected roads to either city. 
  If a road is directly connected to both cities, it is only counted once.
  The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
  Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

  Concept: The network rank of two nodes is the sum of their degrees. If they are directly connected, we must subtract 1 so we don't double-count the shared road.
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> deg(n,0);
        vector<vector<bool>> conn(n, vector<bool>(n, false));

        for (auto&road: roads)
        {
            deg[road[0]]++;
            deg[road[1]]++;
            conn[road[0]][road[1]]=true;
            conn[road[1]][road[0]]=true;
        }

        int maxrank=0;

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int cur = deg[i] + deg[j];
                if(conn[i][j])
                    cur--;
                
                maxrank = max(cur, maxrank);
            }
        }
        return maxrank;
    }
};
