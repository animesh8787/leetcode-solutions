// Minimum Operations to Sort a Permutation
// Difficulty: Medium   Solved: 2026-10-22
// https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int q = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) q = i;
        }

        // Can sorted be reached by rotations only? Can it be reached with reflections?
        bool rot = true, refl = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != ((i - q) % n + n) % n) rot = false;
            if (nums[i] != ((q - i) % n + n) % n) refl = false;
        }

        // Cost of rotating left by p (direct p, or via reversals: n - p + 2)
        auto rotCost = [&](long long p) -> long long {
            return min(p, (long long)(n - p) + 2);
        };

        long long best = LLONG_MAX;

        if (rot) {
            best = min(best, rotCost(q));
        }

        if (refl) {
            int d = ((n - 1 - q) % n + n) % n;
            for (int a = 0; a < n; a++) {
                int s = (d + a) % n;
                best = min(best, (long long)a + 1 + rotCost(s));
            }
        }

        return best == LLONG_MAX ? -1 : (int)best;
    }
};
