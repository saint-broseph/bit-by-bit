/*
    Question:There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
    Without altering the relative order of positive and negative elements, you must return an 
    array of alternately positive and negative values.
*/

#include <bits/stdc++.h>
using namespace std;

// Define a class to handle array manipulation
class Solution {
public:
    vector<int> rearrangeBySign(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++) {
            if (A[i] < 0) {
                ans[negIndex] = A[i];
                negIndex += 2;
            } else {
                ans[posIndex] = A[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};
//TC: O(N)
//SC: O(N)

