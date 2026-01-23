/*
  Given an integer array nums, return the number of reverse pairs in the array.
  A reverse pair is a pair (i, j) where:
    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = 0;

        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j])
                j++;
            count += (j - (mid + 1));
        }

        inplace_merge(nums.begin() + left,
                      nums.begin() + mid + 1,
                      nums.begin() + right + 1);

        return count;
    }
};
