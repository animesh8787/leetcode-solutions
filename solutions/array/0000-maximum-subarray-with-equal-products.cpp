// Maximum Subarray With Equal Products
// Difficulty: Easy   Solved: 2026-11-24
// https://leetcode.com/problems/maximum-subarray-with-equal-products/

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > 25200) break;
                g = __gcd(g, (long long)nums[j]);
                l = l / __gcd(l, (long long)nums[j]) * nums[j];
                if (prod == l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
