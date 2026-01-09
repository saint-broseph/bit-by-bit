/*
    Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
    For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
    Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
    I before V or X → 4 and 9,
    X before L or C → 40 and 90,
    C before D or M → 400 and 900
    Given a Roman numeral, convert it to an integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        // Map of Roman numerals to their integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        // Iterate through the string, except the last character
        for (int i = 0; i < s.size() - 1; i++) {
            // Subtract if current numeral is less than the next
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                // Otherwise, add the current value
                res += roman[s[i]];
            }
        }

        // Add the value of the last character
        return res + roman[s.back()];
    }
};