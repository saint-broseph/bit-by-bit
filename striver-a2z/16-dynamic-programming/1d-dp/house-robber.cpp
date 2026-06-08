/*
  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you 
  from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken 
  into on the same night.
  Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

  Imagine you are standing in front of the $i$-th house. You have two choices:Rob the $i$-th house: If you choose to rob it, you get the money from this house (nums[i]). 
  However, because adjacent houses cannot be robbed, you must add this to the maximum money you could have robbed up to the $(i-2)$-th house.Skip the $i$-th house: 
  If you skip it, you don't get its money, but you carry forward the maximum money you could have robbed up to the $(i-1)$-th house.To maximize your loot, you simply 
  take the maximum of these two decisions.Recurrence Relation$$dp[i] = \max(nums[i] + dp[i-2], dp[i-1])$$
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i = 2; i < n; i++)
        {
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];

    }
};
