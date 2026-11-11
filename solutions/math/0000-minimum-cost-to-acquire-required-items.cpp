// Minimum Cost to Acquire Required Items
// Difficulty: Medium   Solved: 2026-11-11
// https://leetcode.com/problems/minimum-cost-to-acquire-required-items/

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        long long lo = min(n1, n2);
        long long hi = max(n1, n2);
        long long single = (n1 > n2) ? c1 : c2;

        long long opt1 = n1 * c1 + n2 * c2;
        long long opt2 = lo * cb + (hi - lo) * min(single, cb);
        long long opt3 = hi * cb;

        return min(opt1, min(opt2, opt3));
    }
};
