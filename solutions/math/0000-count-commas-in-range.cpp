// Count Commas in Range
// Difficulty: Easy   Solved: 2026-09-08
// https://leetcode.com/problems/count-commas-in-range/

class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        if (n >= 1000)
            ans += n - 999;

        return ans;
    }
};
