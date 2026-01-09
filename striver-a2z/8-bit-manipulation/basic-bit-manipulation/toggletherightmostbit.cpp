/*
    Given a positive integer n, set the rightmost unset (0) bit of its binary representation to 1 and return the resulting integer.
    If all bits are already set, return the number as it is.

    Use bitwise OR with n + 1:
        result = n | (n + 1)
        n + 1 flips the rightmost 0 in n to 1, and all bits to the right become 0.
        Performing OR sets that bit to 1 while leaving other bits unchanged.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to set the rightmost unset bit (0 -> 1)
int setRightmostUnsetBit(int n) {
    // Use bitwise OR with n+1 to set rightmost 0
    return n | (n + 1);
}



