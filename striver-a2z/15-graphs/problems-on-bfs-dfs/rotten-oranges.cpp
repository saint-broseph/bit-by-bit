/*
  You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
  Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
  Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

  All rotten oranges spread the rot to their adjacent fresh oranges at the same time. Since the spreading happens level by level (minute by minute), 
  we can use Breadth-First Search (BFS). Each level of BFS represents 1 minute.

  Approach
    Traverse the entire grid.
    Add all rotten oranges (2) to a queue.
      Count the number of fresh oranges (1).
      If there are no fresh oranges, return 0.
    Perform BFS:
      Process all rotten oranges currently in the queue.
      Check their 4 adjacent cells (up, down, left, right).
      If an adjacent cell contains a fresh orange:
      Change it to rotten.
        Decrease the fresh orange count.
        Add it to the queue for the next minute.
      After processing one BFS level:
        If at least one orange became rotten, increment the time by 1.
      After BFS completes:
      If all fresh oranges have become rotten (fresh == 0), return the total time.
      Otherwise, return -1 because some fresh oranges cannot be reached.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0, mins = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front(); q.pop();
                for (auto dir : dirs) {
                    int nr = r + dir.first, nc = c + dir.second;
                    if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            mins++;
        }
        return fresh == 0 ? mins : -1;
    }
};
