// Best Time to Buy and Sell Stock with Transaction Fee
// Difficulty: Medium   Solved: 2026-09-07
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int prevCash = cash;

            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, prevCash - prices[i]);
        }

        return cash;
    }
};
