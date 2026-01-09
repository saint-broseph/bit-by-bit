/*
    You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order. A number which completely divides another number is called it's divisor.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find all 
    divisors of n */
    vector<int> divisors(int n) {
        
        // To store the divisors;
        vector<int> ans;
        
        int sqrtN = sqrt(n);
        
        // Iterate from 1 to sqrtN
        for(int i=1; i <= sqrtN; i++) {
            
            // If a divisor is found
            if(n % i == 0) {
                //Add it to the answer
                ans.push_back(i);
                
                /* Add the counterpart divisor
                 if it's different from i */
                if(i != n / i) {
                    ans.push_back(n/i);
                }
            }
        }
        
        // Sorting the result 
        sort(ans.begin(), ans.end());
        
        // Return the result
        return ans;
    }
};