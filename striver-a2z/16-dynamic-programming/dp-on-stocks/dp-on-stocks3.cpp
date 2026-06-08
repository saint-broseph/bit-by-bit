/*
  You are given an array prices where prices[i] is the price of a given stock on the ith day.
  Find the maximum profit you can achieve. You may complete at most two transactions.
  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = -1e9, s1 = 0, b2 = -1e9, s2 = 0;
        for (int p : prices) {
            b1 = max(b1, -p);
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        return s2;
    }
};
