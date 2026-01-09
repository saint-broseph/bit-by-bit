/*
    Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
    Input:
    s = "(1+(2*3)+((8)/4))+1"
    Output:
    3
    Explanation:
    Digit 8 is inside of 3 nested parentheses in the string.
    */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method to compute maximum depth of parentheses
    int maxDepth(string s) {
        int p = 0;  
        int ans = 0;
        for (char x : s) {
            // Increase depth on open parenthesis
            if (x == '(') p++;
            // Decrease depth on close parenthesis
            else if (x == ')') p--;
            // Update maximum depth encountered
            ans = max(ans, p);
        }
        return ans;
    }
};