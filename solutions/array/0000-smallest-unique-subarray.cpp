// Smallest Unique Subarray
// Difficulty: Hard   Solved: 2026-11-25
// https://leetcode.com/problems/smallest-unique-subarray/

class Solution {
public:
    typedef unsigned long long ull;
    static const ull MOD = (1ULL << 61) - 1;

    static ull mulmod(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull lo = (ull)(t & MOD), hi = (ull)(t >> 61);
        ull r = lo + hi;
        if (r >= MOD) r -= MOD;
        return r;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        ull B = rng() % (MOD - 1000) + 500;

        vector<ull> h(n + 1, 0), pw(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = (mulmod(h[i], B) + (ull)nums[i]) % MOD;
            pw[i + 1] = mulmod(pw[i], B);
        }

        auto hasUnique = [&](int L) -> bool {
            vector<ull> v;
            v.reserve(n - L + 1);
            for (int i = 0; i + L <= n; i++) {
                ull x = (h[i + L] + MOD - mulmod(h[i], pw[L])) % MOD;
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            int m = v.size();
            for (int i = 0; i < m; i++) {
                bool samePrev = i > 0 && v[i] == v[i - 1];
                bool sameNext = i + 1 < m && v[i] == v[i + 1];
                if (!samePrev && !sameNext) return true;
            }
            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (hasUnique(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
