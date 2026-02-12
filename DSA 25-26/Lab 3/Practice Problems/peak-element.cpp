/*
  A peak element is an element that is strictly greater than its neighbors.
  Given a 0-indexed integer array nums, find a peak element, and return its index. 
  If the array contains multiple peaks, return the index to any of the peaks.
  */

class Solution{
public:
  int findPeakElement(vector<int>& nums)
{  
  int low = 0, high = nums.size() - 1;
  while(low < high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[mid+1])
          high = mid;
        else
          low = mid + 1;
    }
  return low;
}

};
