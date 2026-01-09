/*
    Problem Statement: Given two strings s and goal, return true if and only if s can 
    become goal after some number of shifts on s. A shift on s consists of moving the leftmost 
    character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" 
    after one shift.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if goal is a rotation of s using string doubling method
    bool rotateString(string& s, string& goal) {
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
        //string::npos is to signify "until the end of the string"
    }
};