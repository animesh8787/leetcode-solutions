// Check if There Is a Valid Parentheses String Path
// Difficulty: Hard   Solved: 2026-09-29
// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int len = m + n - 1;

        if (len % 2 || grid[0][0] == ')')
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int bal = 0; bal <= len; bal++) {
                    if (grid[i][j] == '(') {
                        if (bal > 0) {
                            if (i > 0 && dp[i - 1][j][bal - 1])
                                dp[i][j][bal] = true;
                            if (j > 0 && dp[i][j - 1][bal - 1])
                                dp[i][j][bal] = true;
                        }
                    } else {
                        if (bal < len) {
                            if (i > 0 && dp[i - 1][j][bal + 1])
                                dp[i][j][bal] = true;
                            if (j > 0 && dp[i][j - 1][bal + 1])
                                dp[i][j][bal] = true;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
