/*
    Given an integer array nums, return true if any value appears
    more than once in the array, otherwise return false.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (char c : nums)
            freq[c]++;

                for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            if (it->second != 1)
            {
                return true;
            }
        }
        return false;
    }
};