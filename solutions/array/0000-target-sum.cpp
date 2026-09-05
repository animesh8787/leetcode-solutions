// Target Sum
// Difficulty: Medium   Solved: 2026-09-05
// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum || (sum + target) % 2 != 0)
            return 0;

        int need = (sum + target) / 2;
        vector<int> dp(need + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int j = need; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }

        return dp[need];
    }
};
