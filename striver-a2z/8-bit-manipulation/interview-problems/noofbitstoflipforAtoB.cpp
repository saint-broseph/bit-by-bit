/*
    Given two integers start and goal. Flip the minimum number of bits of start integer to convert it into goal integer.
    A bits flip in the number val is to choose any bit in binary representation of val and flipping it from either 0 to 1 or 1 to 0.

    LOGIC:

    To find how many bits differ between two numbers, compare them bit by bit.
    XOR highlights the positions where the two numbers have different bits.
    Each set bit in the XOR result represents a required flip to match the numbers.
    Count the number of set bits in the XOR result to get the total flips needed.
    This provides the minimum number of bit changes to convert one number into the other.

    */


    #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the minimum
     bit flips to convert number */
    int minBitsFlip(int start, int goal) {
        
        /* Variable to store bits that
        are different in both numbers */
        int num = start ^ goal;
        
        /* Variable to count 
        number of set bits */
        int count = 0;

        for(int i = 0; i < 32; i++) {
            /* Update count if the 
            rightmost bit is set */
            count += (num & 1); 
            
            /* Shift the number every 
            time by 1 place */
            num = num >> 1;
        }
        return count;
    }
};