// House Robber
// Difficulty: Medium   Solved: 2026-09-02
// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;

        for (int money : nums) {
            int cur = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
