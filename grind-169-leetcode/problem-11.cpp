/*
    PROBLEM: CONTAINER WITH MOST WATER
    You are given an integer array height of length n. There are n vertical lines drawn such that the
    two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    Notice that you may not slant the container.

    LOGIC: 2 POINTER:
    Initialize 2 pointers l and r to 0 and n-1. Keep calculating area with min(height 1 and height2)*r-l;
    If height of l is less than r; increment l else decrement r; store maxArea and return it.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1, area = 0, maxArea = 0;
        while (l < r)
        {
            int h = min(height[l], height[r]);
            int w = r - l;
            area = h * w;
            maxArea = max(area, maxArea);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return maxArea;
    }
};