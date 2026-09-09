// Palindrome Partitioning II
// Difficulty: Hard   Solved: 2026-09-09
// https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++)
            dp[i] = i;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == 0)
                    dp[r] = 0;
                else
                    dp[r] = min(dp[r], dp[l - 1] + 1);

                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == 0)
                    dp[r] = 0;
                else
                    dp[r] = min(dp[r], dp[l - 1] + 1);

                l--;
                r++;
            }
        }

        return dp[n - 1];
    }
};
