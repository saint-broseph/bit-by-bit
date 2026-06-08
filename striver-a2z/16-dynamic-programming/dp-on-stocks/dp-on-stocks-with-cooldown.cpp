/*
  You are given an array prices where prices[i] is the price of a given stock on the ith day.
  Find the maximum profit you can achieve. 
  You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = -prices[0], s = 0, r = 0;
        for (int p : prices) {
            int nb = max(b, r - p);
            int ns = max(s, b + p);
            r = s;
            b = nb;
            s = ns;
        }
        return s;
    }
};
