// Distinct Subsequences
// Difficulty: Hard   Solved: 2026-09-06
// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        const long long INF = INT_MAX;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    if (dp[j - 1] > INF - dp[j])
                        dp[j] = INF;
                    else
                        dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};
