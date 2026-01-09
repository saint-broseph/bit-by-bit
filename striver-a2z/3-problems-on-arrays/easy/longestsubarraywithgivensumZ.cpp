#include <bits/stdc++.h>
using namespace std;

// Class to encapsulate subarray logic
class SubarraySolver {
public:
    // Function to get the length of longest subarray with sum equal to k
    int getLongestSubarray(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> preSumMap; // prefixSum -> earliest index
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i]; // compute running prefix sum

            // Case 1: If the entire sum from 0 to i is equal to k
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: If (sum - k) is seen before, a valid subarray exists
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Only store the first occurrence of each prefix sum
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};

//TC: O(N) or O(N*logn)
//SC: O(N)
