// Maximum Number of Non-overlapping Palindrome Substrings
// Difficulty: Hard   Solved: 2026-09-15
// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                if (len == 1)
                    pal[l][r] = true;
                else if (len == 2)
                    pal[l][r] = s[l] == s[r];
                else
                    pal[l][r] = s[l] == s[r] && pal[l + 1][r - 1];
            }
        }

        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; r++) {
            dp[r + 1] = dp[r];

            for (int l = 0; l <= r; l++) {
                if (r - l + 1 >= k && pal[l][r]) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};
