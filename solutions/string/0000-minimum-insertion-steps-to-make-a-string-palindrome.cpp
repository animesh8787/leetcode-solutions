// Minimum Insertion Steps to Make a String Palindrome
// Difficulty: Hard   Solved: 2026-09-06
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;

            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];

                if (s[i] == s[j])
                    dp[j] = prev;
                else
                    dp[j] = 1 + min(dp[j], dp[j - 1]);

                prev = temp;
            }
        }

        return dp[n - 1];
    }
};
