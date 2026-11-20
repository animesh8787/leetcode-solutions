// Maximize Consecutive Elements in an Array After Modification
// Difficulty: Hard   Solved: 2026-11-20
// https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxV = nums.back() + 2;
        vector<int> dp(maxV + 1, 0);
        int ans = 1;
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            ans = max(ans, max(dp[x], dp[x + 1]));
        }
        return ans;
    }
};
