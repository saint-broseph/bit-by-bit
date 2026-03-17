/*
  Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
  A subarray is a contiguous non-empty sequence of elements within an array.  
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixc;
        prefixc[0]=1;
        int currsum=0;
        int count=0;

        for(int num: nums)
        {
            currsum+=num;
            if(prefixc.find(currsum-k)!=prefixc.end())
            count+=prefixc[currsum-k];
            prefixc[currsum]++;
        }
        return count;
    }
};
