// Number of Sets of K Non-Overlapping Line Segments
// Difficulty: Medium   Solved: 2026-09-16
// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/

class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        vector<vector<long long>> dp(n + k + 1, vector<long long>(2 * k + 1, 0));

        for (int i = 0; i <= n + k; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n + k; i++) {
            for (int j = 1; j <= 2 * k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= j)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
        }

        return dp[n + k - 1][2 * k];
    }
};
