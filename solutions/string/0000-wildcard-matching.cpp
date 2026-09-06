// Wildcard Matching
// Difficulty: Hard   Solved: 2026-09-06
// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[j] = dp[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            vector<bool> next(n + 1, false);

            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    next[j] = next[j - 1] || dp[j];
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    next[j] = dp[j - 1];
                }
            }

            dp = next;
        }

        return dp[n];
    }
};
