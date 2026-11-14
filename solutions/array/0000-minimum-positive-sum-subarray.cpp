// Minimum Positive Sum Subarray
// Difficulty: Easy   Solved: 2026-11-14
// https://leetcode.com/problems/minimum-positive-sum-subarray/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> P(n + 1, 0);
        for (int i = 0; i < n; i++) P[i + 1] = P[i] + nums[i];

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r && i + len <= n; len++) {
                int sum = P[i + len] - P[i];
                if (sum > 0) ans = min(ans, sum);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
