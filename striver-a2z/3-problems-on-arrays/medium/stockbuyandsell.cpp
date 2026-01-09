/*
    Question: You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0, p = 0;
        int buy = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {

            p = prices[i] - buy;

            if (prices[i] < buy)
                buy = prices[i];

            if (p > maxp)
                maxp = p;
        }
        return maxp;
    }
};