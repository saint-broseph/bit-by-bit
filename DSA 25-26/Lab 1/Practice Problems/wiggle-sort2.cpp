/*
  Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
  You may assume the input array always has a valid answer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<int> a, b;
        int mid = (n+1)/2;
        for(int i=0; i<mid; i++)
            a.push_back(nums[i]);
        for(int i=mid; i<n; i++)
            b.push_back(nums[i]);
            int x=a.size()-1, y=b.size()-1;
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            temp.push_back(a[x--]);
            else
            temp.push_back(b[y--]);
        }        
        nums=temp;        
    }
};
