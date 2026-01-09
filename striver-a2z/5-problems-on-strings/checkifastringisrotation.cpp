/*
    Given two strings s and goal, return true if and only if s can become goal after some 
    number of shifts on s. A shift on s consists of moving the leftmost character of s to the 
    rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if goal is a rotation of s using string doubling method
    bool rotateString(string& s, string& goal) {
        sort(s.begin(),s.end());
        sort(goal.begin(),goal.end());
        if(s==goal) return true;
        else false;
    }

}; 