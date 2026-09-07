// Distinct Subsequences II
// Difficulty: Hard   Solved: 2026-09-07
// https://leetcode.com/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> last(26, 0);
        long long total = 0;

        for (char c : s) {
            int x = c - 'a';
            long long add = (total + 1) % MOD;
            total = (total + add - last[x] + MOD) % MOD;
            last[x] = add;
        }

        return total;
    }
};
