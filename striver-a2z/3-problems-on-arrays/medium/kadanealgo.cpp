// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find maximum sum of subarrays
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