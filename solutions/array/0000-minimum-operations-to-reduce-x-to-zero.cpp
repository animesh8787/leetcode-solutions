// Minimum Operations to Reduce X to Zero
// Difficulty: Medium   Solved: 2026-09-23
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if (target < 0) return -1;

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (left <= right && sum > target) {
                sum -= nums[left++];
            }

            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};
