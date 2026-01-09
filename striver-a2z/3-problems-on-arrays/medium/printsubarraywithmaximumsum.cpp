/*
    In the Kadane's question, print the subarray with largest sum.
    Start by iterating through the array using a variable i. During each iteration, add the current element arr[i] to a running sum variable.
Initialize a start variable to keep track of the starting index of the current subarray.
Use ansStart and ansEnd to store the starting and ending indices of the subarray with the maximum sum found so far. Initially, set both to -1.
If the current sum is greater than the previous maximum sum, update ansStart to start and ansEnd to i.
If the sum becomes negative at any point, reset it to 0 and set start to i + 1 to start a new subarray.
After processing all elements, ansStart and ansEnd will point to the starting and ending indices of the subarray with the maximum sum.
Return the subarray from arr[ansStart] to arr[ansEnd].

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN; 
        long long sum = 0;
        
        int start = 0; 
        int ansStart = -1, ansEnd = -1; 
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (sum == 0) {
                start = i;
            }
            
            sum += nums[i]; 
            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            if (sum < 0) {
                sum = 0;
            }
        }
        
        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return maxi;
    }
};