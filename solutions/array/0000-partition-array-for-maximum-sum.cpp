// Partition Array for Maximum Sum
// Difficulty: Medium   Solved: 2026-09-09
// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            long long mx = 0;

            for (int len = 1; len <= k && i - len >= 0; len++) {
                mx = max(mx, (long long)arr[i - len]);
                dp[i] = max(dp[i], dp[i - len] + mx * len);
            }
        }

        return dp[n];
    }
};
