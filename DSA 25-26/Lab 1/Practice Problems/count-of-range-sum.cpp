#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n + 1, lower, upper);
    }

private:
    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;

        int mid = (left + right) / 2;
        int count = 0;

        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid;
        for (int i = left; i < mid; i++) {
            while (j < right && prefix[j] - prefix[i] < lower) j++;
            while (k < right && prefix[k] - prefix[i] <= upper) k++;
            count += (k - j);
        }

        inplace_merge(prefix.begin() + left,
                      prefix.begin() + mid,
                      prefix.begin() + right);

        return count;
    }
};
