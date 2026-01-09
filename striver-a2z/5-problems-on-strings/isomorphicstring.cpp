/*
    ISOMORPHIC STRINGS: Eg: s = "egg", t = "add"
    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    All occurrences of a character must be replaced with another character while preserving 
    the order of characters. No two characters may map to the same character, but a character 
    may map to itself.
*/

#include <bits/stdc++.h>
  using namespace std;
  
  class Solution {
  public:
      bool isomorphicString(string s, string t) {
          // Arrays to store last seen positions of characters in s and t
          int m1[256] = {0}, m2[256] = {0}; 
          
          // Get the length of the strings
          int n = s.size(); 
          for (int i = 0; i < n; ++i) {
              // If previous positions of current characters differ, return false
              if (m1[s[i]] != m2[t[i]]) return false;
              
              // Update the position with current index + 1
              m1[s[i]] = i + 1;
              m2[t[i]] = i + 1;
          }
          return true;
      }
  };