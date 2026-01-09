/*
    Question: Given an array Arr[] of integers, 
    rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
    If such an arrangement is not possible, it must rearrange to the lowest possible 
    order (i.e., sorted in ascending order).

    LOGIC:
    Traverse from the end and find the first index where the current digit is smaller than the next one (this is the "breaking point").
    Then again traverse from the end to find the first digit greater than the breaking point digit and swap them.
    Finally, reverse the part of the array to the right of the breaking point to get the smallest next permutation.
    If no such breaking point exists (entire array is descending), just reverse the whole array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};
