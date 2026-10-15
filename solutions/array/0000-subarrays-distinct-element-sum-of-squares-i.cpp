// Subarrays Distinct Element Sum of Squares I
// Difficulty: Easy   Solved: 2026-10-15
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> seen(101, false);
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    cnt++;
                }
                ans += cnt * cnt;
            }
        }
        return ans;
    }
};
