class Solution {
public:
int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (findFirst) right = mid - 1;
                else left = mid + 1;
            } else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};

/*
  class Solution {
  public:
  int findFirst(vector<int>&nums, int target)
        {
          // to find the first occurence
        }

        int findLast(vector<int>&nums, int target)
        {
          // to find the last occurence
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        find
    }
};
  

*/
