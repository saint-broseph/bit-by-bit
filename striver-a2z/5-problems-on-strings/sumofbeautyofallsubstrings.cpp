/*
    The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character (excluding characters that do not appear) in that string.
    Given a string s, return the sum of beauty values of all possible substrings of s.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        // Loop over all substrings
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                // Increase frequency of current character
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                // Find max and min frequency
                for (auto it : freq) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                // Add difference to sum
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};  