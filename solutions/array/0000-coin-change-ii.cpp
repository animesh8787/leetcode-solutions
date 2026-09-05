// Coin Change II
// Difficulty: Medium   Solved: 2026-09-05
// https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const long long INF = INT_MAX;

        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] > INF - dp[i])
                    dp[i] = INF;
                else
                    dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
