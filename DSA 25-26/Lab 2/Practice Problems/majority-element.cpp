/*
  Given an array nums of size n, return the majority element.
  The majority element is the element that appears more than ⌊n / 2⌋ times. 
  You may assume that the majority element always exists in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
/*
  // O(N) Solution:
  int majorityElement(vector<int>& nums) {
    int ans = 0;
    int c = 0;

    for (int num : nums) {
        if (c == 0) {
            ans = num;
        }
        c += (num == ans) ? 1 : -1;
    }
    return ans;
}
*/
};
