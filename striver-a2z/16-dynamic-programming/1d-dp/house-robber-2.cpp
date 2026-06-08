/*
  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
  That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if 
  two adjacent houses were broken into on the same night.
  Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {
private:
    int solve(vector<int>& nums, int s, int e) {
        int p2 = 0, p1 = 0;
        for (int i = s; i <= e; i++) {
            int cur = max(nums[i] + p2, p1);
            p2 = p1;
            p1 = cur;
        }
        return p1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
