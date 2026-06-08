/*
  A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k. 
  To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. 
  The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go 
  from the 0th step to the (n-1)th step.
*/

class Solution {
public:
    int minimizeEnergy(int n, vector<int>& heights, int k) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jumpEnergy = dp[i - j] + abs(heights[i] - heights[i - j]);
                    dp[i] = min(dp[i], jumpEnergy);
                } else {
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};

/*
  Time Complexity: O(n*k) 
  Space Complexity: O(n) 
*/
