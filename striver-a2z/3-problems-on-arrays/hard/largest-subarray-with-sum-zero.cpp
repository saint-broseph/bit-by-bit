/*
  Problem Statement: Given an array containing both positive and negative integers, 
  we have to find the length of the longest subarray with the sum of all elements equal to zero.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxLen(const std::vector<int>& A, int n) {
        std::unordered_map<int, int> mpp;
        int maxi = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum == 0) {
                maxi = i + 1;
            }
            else {
                if (mpp.find(sum) != mpp.end()) {
                    maxi = std::max(maxi, i - mpp[sum]);
                }
                else {
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
    }
};
int main() {
    std::vector<int> A = {9, -3, 3, -1, 6, -5};
    int n = A.size();
    Solution sol;
    int ans = sol.maxLen(A, n);
    std::cout << ans << std::endl;
    return 0;
}
