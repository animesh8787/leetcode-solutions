// Minimum Sum of Squared Difference
// Difficulty: Medium   Solved: 2026-10-10
// https://leetcode.com/problems/minimum-sum-of-squared-difference/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> freq(100001, 0);
        long long k = (long long)k1 + k2;

        for (int i = 0; i < nums1.size(); i++) {
            freq[abs(nums1[i] - nums2[i])]++;
        }

        for (int i = 100000; i > 0 && k > 0; i--) {
            if (freq[i] == 0)
                continue;

            if (k >= freq[i]) {
                k -= freq[i];
                freq[i - 1] += freq[i];
                freq[i] = 0;
            } else {
                freq[i - 1] += k;
                freq[i] -= k;
                k = 0;
            }
        }

        long long ans = 0;

        for (int i = 1; i <= 100000; i++) {
            ans += freq[i] * i * i;
        }

        return ans;
    }
};
