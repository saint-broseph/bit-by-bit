#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        // Store the first element in a temporary variable
        int temp = nums[0];
        
        // Shift elements to the left
        for (int i = 1; i < nums.size(); ++i) {
            nums[i - 1] = nums[i];
        }

        // Place the first element at the end
        nums[nums.size() - 1] = temp;
    }
};


//TC: O(N)
//SC: O(1)