// Number of Sub-arrays With Odd Sum
// Difficulty: Medium   Solved: 2026-11-15
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0, ans = 0;
        int parity = 0;
        for (int x : arr) {
            parity = (parity + x) & 1;
            if (parity == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};
