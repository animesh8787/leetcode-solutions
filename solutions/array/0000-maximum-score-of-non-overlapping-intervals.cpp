// Maximum Score of Non-overlapping Intervals
// Difficulty: Hard   Solved: 2026-09-12
// https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        struct Node {
            long long l, r, w;
            int id;
        };

        vector<Node> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](const Node& x, const Node& y) {
            if (x.l != y.l) return x.l < y.l;
            return x.r < y.r;
        });

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid].l > a[i].r)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> best(5, vector<vector<int>>(n + 1));

        for (int k = 1; k <= 4; k++) {
            for (int i = n - 1; i >= 0; i--) {
                dp[k][i] = dp[k][i + 1];
                best[k][i] = best[k][i + 1];

                long long takeScore = a[i].w + dp[k - 1][nxt[i]];

                vector<int> take = best[k - 1][nxt[i]];
                take.push_back(a[i].id);
                sort(take.begin(), take.end());

                if (takeScore > dp[k][i] ||
                    (takeScore == dp[k][i] && take < best[k][i])) {
                    dp[k][i] = takeScore;
                    best[k][i] = take;
                }
            }
        }

        return best[4][0];
    }
};
