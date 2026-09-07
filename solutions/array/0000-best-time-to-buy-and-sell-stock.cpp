// Best Time to Buy and Sell Stock
// Difficulty: Easy   Solved: 2026-09-07
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return profit;
    }
};
