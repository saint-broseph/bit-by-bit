/*
    Use bit masking to isolate the i-th bit in the binary representation of the number.
    By shifting 1 to the left i times, you create a mask where only the i-th bit is set.
    Perform a bitwise AND between the number and the mask to check if that specific bit is active.
    If the result is non-zero, the i-th bit is set to 1; otherwise, it is 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        // Check if the i-th bit is set using bitwise AND operation
        return (n & (1 << i)) != 0;  // If the i-th bit is 1, the result will be non-zero
    }
};