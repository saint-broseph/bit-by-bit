/*
    Given the two integers, dividend and divisor. Divide without using the mod, division, or multiplication operators and return the quotient.
    The fractional portion of the integer division should be lost as it truncates toward zero.
    As an illustration, 8.345 and -2.7335 would be reduced to 8 and -2 respectively.
    Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

    Determine the sign of the final result by checking if the dividend and divisor have opposite signs.
    Convert both numbers to positive using their absolute values to simplify the logic.
    To speed up division, subtract powers of two multiples of the divisor instead of subtracting it one by one.
    Use bit shifting to efficiently find the largest multiple of the divisor that fits into the remaining dividend.
    Subtract this multiple from the dividend and accumulate the equivalent power of two into the result.
    Repeat until the dividend becomes smaller than the divisor.
    Clamp the result to 32-bit signed integer limits if necessary to prevent overflow.
    Apply the correct sign to the result and return the final quotient.

    */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to divide two numbers
    without multiplication and division */
    int divide(int dividend, int divisor) {
        
        // Base case
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        // Variable to store the sign of result
        bool isPositive = true;
        
        // Updating the sign of quotient
        if(dividend >= 0 && divisor < 0) 
            isPositive = false;
        else if(dividend < 0 && divisor > 0)
            isPositive = false;
            
        // Storing absolute dividend & divisor
        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);
        
        // Variable to store the answer and sum
        long long ans = 0, sum = 0;
        
        /* Looping while sum added to divisor is
        less than or equal to divisor */
        while(sum + d <= n) {
            
            // Increment the count
           ans++;
           // Update the sum
           sum += d;
        }
        
        // Handling overflowing condition
        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;
        
        /* Returning the quotient 
        with proper sign */
        return isPositive ? ans : -1*ans;
    }
};