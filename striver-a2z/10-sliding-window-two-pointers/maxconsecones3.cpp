// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

/*
    Initialize two pointers, left and right, both set to 0, and a variable zerocount to keep track of the number of zeros in the current window.
    Traverse the array using the right pointer.
    If the current element is 0, increment zerocount.
    If zerocount exceeds k, check if the element at the left pointer is 0, and if so, decrement zerocount. Then increment the left pointer.
    At each step, calculate the current window size and update the maximum length if it's greater than the previously recorded maximum.
    Continue this process until the right pointer has traversed the entire array.
    Return the maximum window size found.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer of the sliding window
        int left = 0;

        // Counter for zeros in the current window
        int zerocount = 0;

        // Variable to store the maximum valid window length
        int maxlen = 0;

        // Right pointer expands the window
        for (int right = 0; right < nums.size(); right++) {

            // If current element is 0, increment zerocount
            if (nums[right] == 0) {
                zerocount++;
            }

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                // Shrink the window from left
                left++; 
            }

            // Update the maximum window size
            maxlen = max(maxlen, right - left + 1);
        }

        // Return the maximum length found
        return maxlen;
    }
};