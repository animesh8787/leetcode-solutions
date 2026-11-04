// Minimum Operations to Make Elements Within K Subarrays Equal
// Difficulty: Hard   Solved: 2026-11-04
// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = x / 2;      // size of bottom/top half
        int m2 = x - m;     // complementary half size

        vector<int> sortedVals(nums.begin(), nums.end());
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int U = sortedVals.size();
        auto getIdx = [&](int v) {
            return int(lower_bound(sortedVals.begin(), sortedVals.end(), v) - sortedVals.begin()) + 1;
        };

        vector<long long> cntTree(U + 1, 0), sumTree(U + 1, 0);
        auto update = [&](vector<long long>& tree, int i, long long delta) {
            for (; i <= U; i += i & (-i)) tree[i] += delta;
        };
        auto query = [&](vector<long long>& tree, int i) -> long long {
            long long s = 0;
            for (; i > 0; i -= i & (-i)) s += tree[i];
            return s;
        };

        auto sumSmallest = [&](int t) -> long long {
            if (t <= 0) return 0;
            int lo = 1, hi = U, pos = U;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (query(cntTree, mid) >= t) { pos = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            long long before = query(cntTree, pos - 1);
            long long sumBefore = query(sumTree, pos - 1);
            long long need = t - before;
            return sumBefore + need * (long long)sortedVals[pos - 1];
        };

        auto insertVal = [&](int v) {
            int i = getIdx(v);
            update(cntTree, i, 1);
            update(sumTree, i, v);
        };
        auto removeVal = [&](int v) {
            int i = getIdx(v);
            update(cntTree, i, -1);
            update(sumTree, i, -v);
        };

        int numWindows = n - x + 1;
        vector<long long> cost(numWindows);
        long long windowSum = 0;
        for (int i = 0; i < x; i++) { insertVal(nums[i]); windowSum += nums[i]; }

        auto computeCost = [&]() -> long long {
            long long bottomM = sumSmallest(m);
            long long smallestXM = sumSmallest(m2);
            return windowSum - smallestXM - bottomM;
        };

        cost[0] = computeCost();
        for (int l = 1; l < numWindows; l++) {
            removeVal(nums[l - 1]);
            windowSum -= nums[l - 1];
            insertVal(nums[l + x - 1]);
            windowSum += nums[l + x - 1];
            cost[l] = computeCost();
        }

        const long long INF = LLONG_MAX / 2;
        vector<long long> dp((long long)(n + 1) * (k + 1), INF);
        auto idx = [&](int i, int j) { return (long long)i * (k + 1) + j; };
        for (int i = 0; i <= n; i++) dp[idx(i, 0)] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[idx(i, j)] = dp[idx(i - 1, j)];
                if (i >= x) {
                    long long prev = dp[idx(i - x, j - 1)];
                    if (prev < INF) {
                        long long cand = prev + cost[i - x];
                        dp[idx(i, j)] = min(dp[idx(i, j)], cand);
                    }
                }
            }
        }

        return dp[idx(n, k)];
    }
};
