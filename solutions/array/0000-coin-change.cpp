// Coin Change
// Difficulty: Medium   Solved: 2026-09-05
// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INF) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
