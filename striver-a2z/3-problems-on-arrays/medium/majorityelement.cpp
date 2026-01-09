// BRUTE: O(N^2)
// BETTER: Either sort and give the middle element or use a hashmap and then check frequency
// OPTIMAL:
/*
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the majority element in an array
    int majorityElement(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size();
        
        // Count
        int cnt = 0;
        
        // Element
        int el; 
        
        // Applying the algorithm
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        /* Checking if the stored element
         is the majority element*/
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        
        //return element if it is a majority element
        if (cnt1 > (n / 2)) {
            return el;
        }
        
        //return -1 if no such element found
        return -1;
    }
};