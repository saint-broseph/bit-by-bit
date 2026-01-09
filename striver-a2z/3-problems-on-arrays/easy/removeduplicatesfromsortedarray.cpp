#include <bits/stdc++.h>
using namespace std;

// Class to hold the solution logic
class Solution {
public:
    // Function to remove duplicates from sorted array in-place
    int removeDuplicates(vector<int>& nums) {
        // If array is empty, return 0 directly
        if (nums.empty()) return 0;

        // Pointer for the position of last unique element
        int i = 0;

        // Traverse the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                // Move pointer for unique element forward
                i++;
                // Place the new unique element at the next position
                nums[i] = nums[j];
            }
        }

        // i is index of last unique element, count = i + 1
        return i + 1;
    }
};

//TC: O(N)
//SC: O(1)

/*
    BRUTE:
    Declare a set and put elements of array into set.
    TC: O(N)
    SC: O(N) //Here's the difference

     // Removes duplicates using unordered_set and returns count of unique elements
    int removeDuplicates(vector<int>& nums) {
        // Unordered set to store elements we have already seen
        unordered_set<int> seen;

        // Index where the next unique element will be written
        int index = 0;

        // Loop over each element in the array
        for (int num : nums) {
            // If num is not in seen, it's unique
            if (seen.find(num) == seen.end()) {
                // Add this num to the set of seen numbers
                seen.insert(num);

                // Overwrite nums[index] with this unique num
                nums[index] = num;

                // Move index forward
                index++;
            }
        }
        // Return count of unique elements
        return index;
    }
*/