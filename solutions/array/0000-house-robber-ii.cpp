// House Robber II
// Difficulty: Medium   Solved: 2026-09-02
// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int robRange(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0;

        for (int i = l; i <= r; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            robRange(nums, 0, n - 2),
            robRange(nums, 1, n - 1)
        );
    }
};
