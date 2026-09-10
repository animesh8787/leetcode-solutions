// Count Square Submatrices with All Ones
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            int prev = 0;

            for (int j = 0; j < n; j++) {
                int temp = dp[j];

                if (matrix[i][j] == 1) {
                    dp[j] = 1 + min({
                        dp[j],
                        j > 0 ? dp[j - 1] : 0,
                        prev
                    });

                    ans += dp[j];
                } else {
                    dp[j] = 0;
                }

                prev = temp;
            }
        }

        return ans;
    }
};
