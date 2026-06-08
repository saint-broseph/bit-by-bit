/*
  You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
  Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        vector<int> b(k + 1, -1e9), s(k + 1, 0);
        for (int p : prices) {
            for (int i = 1; i <= k; i++) {
                b[i] = max(b[i], s[i - 1] - p);
                s[i] = max(s[i], b[i] + p);
            }
        }
        return s[k];
    }
};
