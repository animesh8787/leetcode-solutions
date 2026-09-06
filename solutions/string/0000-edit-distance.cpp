// Edit Distance
// Difficulty: Medium   Solved: 2026-09-06
// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> dp(n + 1);

        for (int j = 0; j <= n; j++)
            dp[j] = j;

        for (int i = 1; i <= m; i++) {
            vector<int> next(n + 1);
            next[0] = i;

            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    next[j] = dp[j - 1];
                } else {
                    next[j] = 1 + min({
                        dp[j],
                        next[j - 1],
                        dp[j - 1]
                    });
                }
            }

            dp = next;
        }

        return dp[n];
    }
};
