/*
  Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. 
  A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means 
  the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
*/

class Solution {
public:
    int frogJump(const vector<int>& height) {
        if (height.empty()) return 0;
        int n = (int)height.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int ind = 1; ind < n; ind++) {
            int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
            int jumpTwo = INT_MAX;
            if (ind > 1) {
                jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            }
            dp[ind] = min(jumpOne, jumpTwo);
        }
        return dp[n - 1];
    }
};
