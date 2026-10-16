// Subarrays Distinct Element Sum of Squares II
// Difficulty: Hard   Solved: 2026-10-16
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/

class Solution {
    vector<long long> t, lz;
    void push(int x, int l, int r) {
        if (lz[x]) {
            int m = (l + r) / 2;
            t[2*x] += lz[x] * (m - l + 1);
            t[2*x+1] += lz[x] * (r - m);
            lz[2*x] += lz[x];
            lz[2*x+1] += lz[x];
            lz[x] = 0;
        }
    }
    void update(int x, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            t[x] += r - l + 1;
            lz[x]++;
            return;
        }
        push(x, l, r);
        int m = (l + r) / 2;
        update(2*x, l, m, ql, qr);
        update(2*x+1, m+1, r, ql, qr);
        t[x] = t[2*x] + t[2*x+1];
    }
    long long query(int x, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[x];
        push(x, l, r);
        int m = (l + r) / 2;
        return query(2*x, l, m, ql, qr) + query(2*x+1, m+1, r, ql, qr);
    }
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        t.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        unordered_map<int, int> last;
        long long cur = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            int p = last.count(nums[j]) ? last[nums[j]] : -1;
            long long s = query(1, 0, n - 1, p + 1, j);
            cur = (cur + 2 * (s % MOD) + (j - p)) % MOD;
            update(1, 0, n - 1, p + 1, j);
            ans = (ans + cur) % MOD;
            last[nums[j]] = j;
        }
        return ans;
    }
};
