// Count Commas in Range II
// Difficulty: Medium   Solved: 2026-09-09
// https://leetcode.com/problems/count-commas-in-range-ii/

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long p = 1000; p <= n; p *= 1000) {
            ans += n - p + 1;
        }

        return ans;
    }
};
