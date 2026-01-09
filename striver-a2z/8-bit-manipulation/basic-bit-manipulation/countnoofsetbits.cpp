/*
    Given an integer n, return the number of set bits (1s) in its binary representation.
    Can you solve it in O(log n) time complexity?

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of set bits (1s) in the binary representation of n using Brian Kernighan's Algorithm
    int countSetBits(int n) {
        int count = 0;  // Variable to store the count of set bits

        // Step 1: While n is non-zero, turn off the rightmost set bit
        while (n) {
            n &= (n - 1);  // Turn off the rightmost set bit
            count++;  // Increment the count
        }

        // Step 2: Return the count of set bits
        return count;
    }
};