// Given a string, S. Find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        
        int HashLen = 256; 
        int hash[HashLen]; 
        for (int i = 0; i < HashLen; ++i)
            hash[i] = -1;
            
        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            
            /* If current character s[r] 
            is already in the substring*/
            if (hash[s[r]] != -1) {
                
                /* Move left pointer to the right
                of the last occurrence of s[r]*/
                l = max(hash[s[r]] + 1, l);
            }
            
            // Calculate the current substring length
            int len = r - l + 1;
            
            // Update maximum length found so far
            maxLen = max(len, maxLen);
            
            /* Store the index of the current
            character in the hash table*/
            hash[s[r]] = r;
            
            // Move right pointer to next position
            r++;
        }
       
        // Return the maximum length found
        return maxLen;
    }
};
