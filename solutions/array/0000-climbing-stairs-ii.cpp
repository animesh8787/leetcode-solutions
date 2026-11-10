// Climbing Stairs II
// Difficulty: Medium   Solved: 2026-11-10
// https://leetcode.com/problems/climbing-stairs-ii/

class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int step = 1; step <= 3; step++) {
                int i = j - step;
                if (i < 0) break;
                if (dp[i] == LLONG_MAX) continue;
                long long cand = dp[i] + costs[j - 1] + (long long)step * step;
                dp[j] = min(dp[j], cand);
            }
        }

        return dp[n];
    }
};
