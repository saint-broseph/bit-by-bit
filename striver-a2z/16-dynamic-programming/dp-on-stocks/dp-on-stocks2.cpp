/*
  You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
  On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
  However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
  Find and return the maximum profit you can achieve.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = -prices[0], s = 0;
        for (int p : prices) {
            int nb = max(b, s - p);
            int ns = max(s, b + p);
            b = nb;
            s = ns;
        }
        return s;
    }
};
