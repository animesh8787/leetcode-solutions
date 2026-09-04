// Partition Equal Subset Sum
// Difficulty: Medium   Solved: 2026-09-04
// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2)
            return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : nums) {
            for (int sum = target; sum >= x; sum--) {
                dp[sum] = dp[sum] || dp[sum - x];
            }
        }

        return dp[target];
    }
};
