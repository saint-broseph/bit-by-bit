/*
  You are given an integer array bloomDay, an integer m and an integer k.
  You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
  The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
  Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
  If it is impossible to make m bouquets return -1.
  */

class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k, int day)
        {
          int bouquets = 0, count = 0;
          for(int d: bloomDay)
            {
              if(d<=day) count++;
              else count = 0;
        
              if(count == k)
              {
                bouquets++;
                count = 0;
              }
            }
          return bouquets >= m;
        }

    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;

      int low = 1, high = 1e9, ans = -1;
      while(low<=high)
        {
          int mid = low + (high - low)/2;
          if(possible(bloomDay, m, k, mid))
          {
            ans = mid;
            high = mid - 1;
          }
          else low = mid + 1;
        }
      return ans;
    }
};
