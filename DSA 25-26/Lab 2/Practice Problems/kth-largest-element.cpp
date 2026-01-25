/*
  Given an integer array nums and an integer k, return the kth largest element in the array.
  Note that it is the kth largest element in the sorted order, not the kth distinct element.
  Can you solve it without sorting?
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.end() - k, nums.end());
    return nums[nums.size() - k];
    }
};

// TIME COMPLEXITY: O(N).

