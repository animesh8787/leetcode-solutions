// Frequency of the Most Frequent Element
// Difficulty: Medium   Solved: 2026-10-14
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int l = 0, best = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            best = max(best, r - l + 1);
        }
        return best;
    }
};
