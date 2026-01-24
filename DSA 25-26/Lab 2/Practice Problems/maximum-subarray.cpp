/*
  Given an integer array nums, find the subarray with the largest sum, and return its sum.
  */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN; 
        long long sum = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            
            sum += nums[i]; 
            if (sum > maxi) {
                maxi = sum; 
            }
            if (sum < 0) {
                sum = 0; 
            }
        }
        return maxi;
    }
};

/*
  class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
    }
};




*/
