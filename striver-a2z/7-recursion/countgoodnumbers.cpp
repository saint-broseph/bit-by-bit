/*
    A digit string is considered good if the digits at even indices (0-based) are even digits (0, 2, 4, 6, 8) and the digits at odd indices are prime digits (2, 3, 5, 7).
    Given an integer n, return the total number of good digit strings of length n. As the result may be large, return it modulo 109 + 7.
    A digit string is a string consisting only of the digits '0' through '9'. It may contain leading zeros.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(int index, int n)
    {   
        if (index == n)
            return 1;
        int result = 0;
        if (index % 2 == 0)
        {
            for (int digit : {0, 2, 4, 6, 8})
            {
                result = (result + countGoodNumbers(index + 1, n)) % MOD;
            }
        }
        else
        {
            for (int digit : {2, 3, 5, 7})
            {
                result = (result + countGoodNumbers(index + 1, n)) % MOD;
            }
        }
        return result;
    }
};