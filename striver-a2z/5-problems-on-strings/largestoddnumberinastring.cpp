/* Given a string s, representing a large integer, the task is to return the largest-valued odd 
integer (as a string) that is a substring of the given string s.
The number returned should not have leading zero's. But the given input string may have leading zero. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the largest odd number substring from the given string
    string largeOddNum(string& s) {
        int ind = -1;

        // Find the last odd digit in the string
        int i;
        for (i = s.length() - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }

        // Skip leading zeroes up to the odd digit
        i = 0;
        while (i <= ind && s[i] == '0') i++;

        // Return substring from first non-zero to odd digit
        return s.substr(i, ind - i + 1);
    }
};
