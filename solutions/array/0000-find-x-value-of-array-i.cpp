// Find X Value of Array I
// Difficulty: Medium   Solved: 2026-09-21
// https://leetcode.com/problems/find-x-value-of-array-i/

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int x = num % k;
            vector<long long> next(k, 0);

            next[x]++;

            for (int r = 0; r < k; r++) {
                next[(r * x) % k] += dp[r];
            }

            dp = next;

            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};
