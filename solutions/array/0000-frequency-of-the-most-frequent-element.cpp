// Frequency of the Most Frequent Element
// Difficulty: Medium   Solved: 2026-09-10
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int left = 0, ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (1LL * nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
