// Count Non-Decreasing Subarrays After K Operations
// Difficulty: Hard   Solved: 2026-11-13
// https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; i++) P[i + 1] = P[i] + nums[i];

        struct Seg {
            long long v;
            int s, e;
        };
        auto segCost = [&](const Seg& g) -> long long {
            return g.v * (g.e - g.s + 1) - (P[g.e + 1] - P[g.s]);
        };

        deque<Seg> dq;
        long long cost = 0;
        long long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            Seg cur = {nums[l], l, l};
            while (!dq.empty() && dq.front().v <= nums[l]) {
                cost -= segCost(dq.front());
                cur.e = dq.front().e;
                dq.pop_front();
            }
            cost += segCost(cur);
            dq.push_front(cur);

            while (cost > k) {
                Seg& b = dq.back();
                cost -= b.v - nums[r];
                b.e--;
                r--;
                if (b.e < b.s) dq.pop_back();
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
